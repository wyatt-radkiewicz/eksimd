DEFAULT_GOAL: test
test: src/test.c src/simd_neon.h src/simd_sse2.h src/simd_fallback.h src/simd_common.h
	mkdir -p bin
	$(CC) -O2 -g src/test.c -o bin/test

.PHONY: clean
clean:
	rm -r bin 
