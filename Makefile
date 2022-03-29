VPATH= src:src/headers
libs= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
objects= Main.o Engine.o Input.o Update.o Draw.o Pixel.o Snake.o Food.o HUD.o Menu.o DarkModeToggle.o GameOverDialogue.o PauseMenu.o SoundToggle.o ChangeDifficultySubmenu.o FullscreenToggle.o

all: $(objects)
	g++ $^ -o Snake $(libs)


Input.o: Engine.h
Update.o: Engine.h
Draw.o: Engine.h

Engine.h: Snake.h Food.h HUD.h Menu.h DarkModeToggle.h GameOverDialogue.h PauseMenu.h SoundToggle.h ChangeDifficultySubmenu.h FullscreenToggle.h
	touch src/headers/Engine.h

Snake.h: Pixel.h
	touch src/headers/Snake.h

Food.h: Pixel.h
	touch src/headers/Food.h

HUD.h: Snake.h
	touch src/headers/HUD.h

GameOverDialogue.h: Menu.h
	touch src/headers/GameOverDialogue.h

PauseMenu.h: Menu.h
	touch src/headers/PauseMenu.h

ChangeDifficultySubmenu.h: Menu.h
	touch src/headers/ChangeDifficultySubmenu.h

%.o: %.cpp %.h
	g++ $< -c

%.o: %.cpp 
	g++ $< -c


.PHONY: clean

clean:
	-rm *.o
	-rm Snake
