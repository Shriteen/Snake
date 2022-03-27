#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Snake.h"
#include "Food.h"
#include "HUD.h"
#include "Menu.h"
#include "DarkModeToggle.h"
#include "GameOverDialogue.h"
#include "PauseMenu.h"

extern bool soundOn;

class Engine
{
	private:		
		sf::RenderWindow window;
		sf::Color bgColor;
		sf::Color borderColor;
		sf::Color foodColor;
		sf::Color hudTextColor;
		sf::View view;
		sf::View hudView;
		sf::RectangleShape border;
		Snake *snake;
		Food *food;
		HUD hud;
		bool playing;
		Menu menu;
		colorScheme scheme;
		DarkModeToggle schemeToggle;
		bool playAgain;
		GameOverDialogue overDialogue;
		bool gameIsRunning;
		PauseMenu pauseMenu;
		sf::SoundBuffer gulpSoundBuffer;
		sf::Sound gulpSound;
		sf::SoundBuffer gameOverSoundBuffer;
		sf::Sound gameOverSound;
		sf::SoundBuffer changeSchemeSoundBuffer;
		sf::Sound changeSchemeSound;
		sf::SoundBuffer selectOptionSoundBuffer;
        sf::Sound selectOptionSound;
		
		void input();
		void update(float interval);
		void draw();
		void adjustViews(int width,int height);
		void mainScreen();
		void setColorScheme(colorScheme mode);
		void gameOverDialogue();
	public:		
		Engine();
		~Engine();
		void main();
		void start();
};
