OUTPUT=customprompt.out
FLAGS=-Wall -std=c++14

compile:
	@echo "Compiling..."
	@g++ src/prompts.cpp src/engine.cpp -o bin/${OUTPUT} ${FLAGS}

copy: compile
	@echo "Copying to home directory..."
	@mkdir ~/.bashconfig
	@cp bin/${OUTPUT} ~/.bashconfig

install: copy
	@echo "Updating profile..."
	@source ~/.bash_profile

clean:
	@echo "Removing ~/.bashconfig..."
	@rm -r ~/.bashconfig

update: clean install
