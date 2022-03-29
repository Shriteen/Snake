#include "headers/Engine.h"
#include<iostream>

bool soundOn;

Engine::Engine():
    window(sf::VideoMode(1080,720),"Snake"),
    foodColor(sf::Color::Red),
    hudTextColor(sf::Color(0,192,192)),
    border(sf::Vector2f(1080-(2*Pixel::size),720-(2*Pixel::size))),
    hud(hudTextColor),
    playing(true),
    snake(nullptr),
    menu(std::vector<std::string>{"Start","Difficulty","Exit"},
         sf::FloatRect(0,0,1080,720),
         hudTextColor,
         50),
    overDialogue(sf::FloatRect(0,0,1080,720),
                 sf::Color(0,192,192)),
    pauseMenu(sf::FloatRect(0,0,1080,720),
                 sf::Color::White,
                 sf::Color(0,192,192,192)),
    soundToggle(sf::Color(0,192,192)),
    changeDifficultySubMenu(sf::FloatRect(0,0,1080,648),
                            hudTextColor),
    difficulty(Difficulty::easy),
    isFullScreen(false)
{
    window.setFramerateLimit(60);
    view.reset(sf::FloatRect(0,0,1080,720));
    hudView.reset(sf::FloatRect(0,0,1080,72));
    
    setColorScheme(colorScheme::light);
    
    border.setOutlineColor(borderColor);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(5);
    border.setPosition(Pixel::size,Pixel::size);
    
    food=new Food(border.getGlobalBounds(),foodColor);
    
    soundOn=true;
    
    gulpSoundBuffer.loadFromFile("sounds/eatingFX.flac");
    gulpSound.setBuffer(gulpSoundBuffer);
    gameOverSoundBuffer.loadFromFile("sounds/gameOverFX.flac");
    gameOverSound.setBuffer(gameOverSoundBuffer);
    changeSchemeSoundBuffer.loadFromFile("sounds/schemeToggleFX.wav");
    changeSchemeSound.setBuffer(changeSchemeSoundBuffer);
    selectOptionSoundBuffer.loadFromFile("sounds/selectFX.flac");
    selectOptionSound.setBuffer(selectOptionSoundBuffer);
    
}

Engine::~Engine()
{
    delete snake;
    delete food;
}

void Engine::main()
{
    while(window.isOpen())
    {
        view.setViewport(sf::FloatRect(0,0,1,1));
        window.setView(view);
        adjustViews(window.getSize().x,window.getSize().y);
        
        mainScreen();
        if(!window.isOpen())
            return;        
        
        do
        {
            start();
        }while(playAgain && window.isOpen());
    }
}

void Engine::start()
{
    snake=new Snake(((scheme==colorScheme::light)?sf::Color::Black : sf::Color::White),
                    sf::Vector2i(1080/2,720/2));
    gameIsRunning=true;
    playAgain=false;
    playing=true;

    sf::Clock clock;    
    update(1);
    draw();
    
    while(window.isOpen() && snake->isAlive() && gameIsRunning)
    {
        input();
        
        sf::Time interval=clock.getElapsedTime();
        
        if(interval.asMilliseconds() > int(difficulty))
        {
            update(interval.asSeconds());
            clock.restart();
        }
        
        draw();
    }
    
    if(!snake->isAlive())
        gameOverDialogue();
    
    delete snake;
    snake=nullptr;
}

void Engine::adjustViews(int width,int height)
{
    if(float(width)/float(height) > 1.5 )
    {
        view.setViewport(sf::FloatRect( 0.5-(float(height*1.25)/float(2000)),
                         0.1,
                         ((height*1.25)/float(1000)),
                         0.9));
        hudView.setViewport(sf::FloatRect( 0.5-(float(height*1.25)/float(2000)),
                         0,
                         ((height*1.25)/float(1000)),
                         0.1));
    }
    else
    {
        view.setViewport(sf::FloatRect(0,
                         0.5-(float(width*1.25)/float(1000))*0.4,
                         1,
                         (width*1.25)/float(1000)-0.1));
        hudView.setViewport(sf::FloatRect(0,
                         0.5-(float(width*1.25)/float(2000)),
                         1,
                         (width*1.25)/float(1000)*0.1));
    }
}

void Engine::mainScreen()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed :
                    window.close();
                    break;
                
                case sf::Event::Resized :
                    adjustViews(event.size.width,event.size.height);
                    break;
                
                case sf::Event::KeyPressed :
                    if(event.key.code == sf::Keyboard::Enter)
                    {
                        if(soundOn)
                            selectOptionSound.play();
                        if(menu.getSelected() == "Start")
                            return;
                        else if(menu.getSelected() == "Difficulty")
                            changeDifficultySubMenuShow();
                        else if(menu.getSelected() == "Exit")
                            window.close();
                    }
                    else if(event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    else if(event.key.code == sf::Keyboard::D)
                    {
                        if(scheme == colorScheme::light)
                            setColorScheme(colorScheme::dark);
                        else
                            setColorScheme(colorScheme::light);
                        if(soundOn)
                            changeSchemeSound.play();
                    }
                    else if(event.key.code == sf::Keyboard::S)
                    {
                        soundOn=!soundOn;
                    }
                    else if(event.key.code == sf::Keyboard::F11)
                    {
                        isFullScreen=!isFullScreen;
                        if(isFullScreen)
                            window.create(sf::VideoMode::getDesktopMode(),"Snake",sf::Style::Fullscreen);
                        else
                            window.create(sf::VideoMode(1080,720),"Snake");
                        if(soundOn)
                            selectOptionSound.play();
                        window.setFramerateLimit(60);
                    }
                    else
                    {
                        menu.keyHandle(event);
                    }
                    break;
                    
                case sf::Event::MouseButtonPressed :
                    if(menu.mouseHandle(event,window))
                    {
                        if(menu.getSelected() == "Start")
                            return;
                        else if(menu.getSelected() == "Difficulty")
                            changeDifficultySubMenuShow();
                        else if(menu.getSelected() == "Exit")
                            window.close();
                    }
                    else if(schemeToggle.isClicked(event,window))
                    {
                        if(scheme == colorScheme::light)
                            setColorScheme(colorScheme::dark);
                        else
                            setColorScheme(colorScheme::light);
                        if(soundOn)
                            changeSchemeSound.play();
                    }
                    else if(soundToggle.isClicked(event,window))
                    {
                        soundOn=!soundOn;
                    }
                    else if(fullscreenToggle.isClicked(event,window))
                    {
                        isFullScreen=!isFullScreen;
                        if(isFullScreen)
                            window.create(sf::VideoMode::getDesktopMode(),"Snake",sf::Style::Fullscreen);
                        else
                            window.create(sf::VideoMode(1080,720),"Snake");
                        if(soundOn)
                            selectOptionSound.play();
                        window.setFramerateLimit(60);
                    }
                    break;
            }
            
        }
        
        adjustViews(973,648);
        
        schemeToggle.update(scheme);
        soundToggle.update(soundOn);
        fullscreenToggle.update(isFullScreen);
        
        window.clear(bgColor);
        
        window.setView(view);
        menu.draw(window);
        schemeToggle.draw(window);
        soundToggle.draw(window);
        fullscreenToggle.draw(window);
        
        window.display();
    }
}

void Engine::setColorScheme(colorScheme mode)
{
    scheme=mode;
    switch(mode)
    {
        case colorScheme::light :
            bgColor=sf::Color::White;
            borderColor=sf::Color::Black;
            //snake->setColor(sf::Color::Black);
            break;
        case colorScheme::dark :
            bgColor=sf::Color::Black;
            borderColor=sf::Color::White;
            //snake->setColor(sf::Color::White);
            break;
    }
    border.setOutlineColor(borderColor);
}

void Engine::gameOverDialogue()
{
    if(soundOn)
        gameOverSound.play();
    
    overDialogue.setScore(snake->getScore());
    window.setView(view);    
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed :
                    window.close();
                    break;
                
                case sf::Event::Resized :
                    adjustViews(event.size.width,event.size.height);
                    break;
                
                case sf::Event::KeyPressed :
                    if(event.key.code == sf::Keyboard::Enter)
                    {
                        if(soundOn)
                            selectOptionSound.play();
                        if(overDialogue.getSelected() == "Play Again")
                        {
                            playAgain=true;
                            return;
                        }
                        else if(overDialogue.getSelected() == "Exit To Menu")
                        {
                            playAgain=false;
                            return;
                        }
                    }
                    else if(event.key.code == sf::Keyboard::Escape)
                    {
                        playAgain=false;
                        return;
                    }
                    else
                    {
                        overDialogue.keyHandle(event);
                    }
                    break;
                    
                case sf::Event::MouseButtonPressed :
                    if(overDialogue.mouseHandle(event,window))
                    {
                        if(overDialogue.getSelected() == "Play Again")
                        {
                            playAgain=true;
                            return;
                        }
                        else if(overDialogue.getSelected() == "Exit To Menu")
                        {
                            playAgain=false;
                            return;
                        }
                    }
                    break;
            }
            
        }
        
        window.clear(bgColor);
        overDialogue.draw(window);
        window.display();
    }
}

void Engine::changeDifficultySubMenuShow()
{
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed :
                    window.close();
                    break;
                
                case sf::Event::Resized :
                    adjustViews(event.size.width,event.size.height);
                    break;
                
                case sf::Event::KeyPressed :
                    if(event.key.code == sf::Keyboard::Enter)
                    {
                        if(soundOn)
                            selectOptionSound.play();
                        if(changeDifficultySubMenu.getSelected() == "Easy")
                        {
                            difficulty=Difficulty::easy;
                            return;
                        }
                        else if(changeDifficultySubMenu.getSelected() == "Medium")
                        {
                            difficulty=Difficulty::medium;
                            return;
                        }
                        else if(changeDifficultySubMenu.getSelected() == "Hard")
                        {
                            difficulty=Difficulty::hard;
                            return;
                        }
                    }
                    else if(event.key.code == sf::Keyboard::Escape)
                    {
                        return;
                    }
                    else
                    {
                        changeDifficultySubMenu.keyHandle(event);
                    }
                    break;
                    
                case sf::Event::MouseButtonPressed :
                    if(changeDifficultySubMenu.mouseHandle(event,window))
                    {
                        if(changeDifficultySubMenu.getSelected() == "Easy")
                        {
                            difficulty=Difficulty::easy;
                            return;
                        }
                        else if(changeDifficultySubMenu.getSelected() == "Medium")
                        {
                            difficulty=Difficulty::medium;
                            return;
                        }
                        else if(changeDifficultySubMenu.getSelected() == "Hard")
                        {
                            difficulty=Difficulty::hard;
                            return;
                        }
                    }
                    break;
            }
            
        }
        
        window.setView(view);
        window.clear(bgColor);
        changeDifficultySubMenu.draw(window);
        window.display();
    }
}
