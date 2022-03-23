VPATH= src:src/headers
libs= -lsfml-graphics -lsfml-window -lsfml-system
objects= Main.o Engine.o Input.o Update.o Draw.o Pixel.o Snake.o Food.o HUD.o Menu.o DarkModeToggle.o

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

Engine.h: Snake.h Food.h HUD.h Menu.h DarkModeToggle.h
	touch src/headers/Engine.h

Snake.h: Pixel.h
	touch src/headers/Snake.h

Food.h: Pixel.h
	touch src/headers/Food.h

HUD.h: Snake.h
	touch src/headers/HUD.h

%.o: %.cpp
	g++ $< -c

.PHONY: clean

clean:
	-rm *.o
	-rm Snake
