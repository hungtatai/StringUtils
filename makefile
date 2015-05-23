
#.PHONY test

test:
	@g++ main.cpp -o main
	@./main
	@rm main
