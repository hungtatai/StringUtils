
.PHONY: test demo

test:
	@cd ./test && \
	g++ main.cpp -o main && \
	./main && \
	rm main test_writefile.txt

demo:
	@cd ./demo/customize_configuration && \
	g++ main.cpp -o main && \
	./main && \
	rm main
