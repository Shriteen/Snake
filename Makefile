VPATH= src:src/headers
libs= -lsfml-graphics -lsfml-window -lsfml-system
objects= Main.o Engine.o Input.o Update.o Draw.o Pixel.o Snake.o

all: $(objects)
	g++ $^ -o Snake $(libs)

Main.o:  Engine.h
Engine.o:  Engine.h
Input.o: Engine.h
Update.o: Engine.h
Draw.o: Engine.h
Pixel.o: Pixel.h 
Snake.o: Snake.h

Engine.h: Snake.h
	touch Engine.h

Snake.h: Pixel.h
	touch Snake.h


%.o: %.cpp
	g++ $< -c

.PHONY: clean

clean:
	-rm *.o
	-rm Snake
