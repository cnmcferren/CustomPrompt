FLAGS=-Wall -std=c++14

compile:
	g++ src/standardPrompt.cpp -o bin/standardPrompt.out $(FLAGS)
	g++ src/errorPrompt.cpp -o bin/errorPrompt.out $(FLAGS)
	g++ src/gitPrompt.cpp -o bin/gitPrompt.out $(FLAGS)

copy: compile
	cp bin/*.out ~/.bashconfig

update: copy
	source ~/.bash_profile
