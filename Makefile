OUTPUT=customprompt.out
FLAGS=-Wall -std=c++14

compile:
	echo "Compiling..."
	g++ src/prompts.cpp src/engine.cpp -o bin/${OUTPUT} ${FLAGS}

copy: compile
	echo "Copying to home folder..."
	cp bin/${OUTPUT} ~/.bashconfig

install: copy
	echo "Updating profile..."
	source ~/.bash_profile
