compile:
	gcc -o app ./sources/*.c -Wall -g -lm `sdl2-config --cflags --libs` -lSDL2_ttf

clean:
	rm app