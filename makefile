SRCS=$(shell find src -name '*.c')
all: hextrainer

hextrainer: $(SRCS)
	mkdir -p bin
	$(CC) -o bin/hextrainer $(SRCS)

clean:
	rm -rf bin
