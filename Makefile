build:
	gcc -Iinclude -Wall -std=c99 ./src/*.c -lSDL2 -o ./bin/game

run:
	./bin/game

clear:
	rm ./bin/game