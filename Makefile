DEFAULT_GOAL: test
test: test.c simd.h
	mkdir -p bin
	$(CC) -O2 -g test.c -o bin/test

.PHONY: clean
clean:
	rm -r bin 
