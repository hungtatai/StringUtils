
.PHONY: test

test:
	@cd ./test && \
	g++ main.cpp -o main && \
	./main && \
	rm main test_writefile.txt
