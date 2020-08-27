compile:
	gcc -o app ./sources/*.c -Wall -g -lm `sdl2-config --cflags --libs`

clean:
	rm app