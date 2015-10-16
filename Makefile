.PHONY: all clean test

ALL= swirl naruto slant

%: %.o
	$(CC) $< $(LDFLAGS) -o $@

all: $(ALL)

swirl: swirl.o
naruto: naruto.o
slant: slant.o

clean:
	rm -f *.o $(ALL)

test: $(ALL)
	@echo "-------swirl--------"
	@echo "*  20 20" | ./swirl
	@echo "-------naruto-------"
	@echo "*  20 20" | ./naruto
	@echo "-------slant--------"
	@echo "*  20 20" | ./slant

LDFLAGS=-lm
