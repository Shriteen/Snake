VPATH= src:src/headers
libs= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
objects= Main.o Engine.o Input.o Update.o Draw.o Pixel.o Snake.o Food.o HUD.o Menu.o DarkModeToggle.o GameOverDialogue.o PauseMenu.o SoundToggle.o

all: $(objects)
	g++ $^ -o Snake $(libs)

Main.o:  Engine.h
Engine.o:  Engine.h
Input.o: Engine.h
Update.o: Engine.h
Draw.o: Engine.h
Pixel.o: Pixel.h 
Snake.o: Snake.h
Food.o: Food.h
HUD.o: HUD.h
Menu.o: Menu.h
DarkModeToggle.o: DarkModeToggle.h
GameOverDialogue.o: GameOverDialogue.h
PauseMenu.o: PauseMenu.h
SoundToggle.o: SoundToggle.h

Engine.h: Snake.h Food.h HUD.h Menu.h DarkModeToggle.h GameOverDialogue.h PauseMenu.h SoundToggle.h
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

%.o: %.cpp
	g++ $< -c

.PHONY: clean

clean:
	-rm *.o
	-rm Snake
