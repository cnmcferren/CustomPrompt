OUTPUT=customprompt.out
FLAGS=-Wall -std=c++14

compile:
	@echo "Compiling..."
	@g++ src/prompts.cpp src/engine.cpp -o bin/${OUTPUT} ${FLAGS}

copy: compile
	@echo "Copying to home directory..."
	@cp bin/${OUTPUT} ~/.bashconfig

install: copy
	@echo "Updating bash profile..."
	@cat anc/ps1Update.txt >> ~/.bash_profile
	@source ~/.bash_profile

clean:
	@echo "Removing ~/.bashconfig..."
	@rm -r ~/.bashconfig

update: clean copy
	@echo "Updating bash profile..."
	@source ~/.bash_profile
