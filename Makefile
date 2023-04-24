.PHONY: all clean test

ALL= xxxx circle swirl naruto slant katori

%: %.o
	$(CC) $< $(LDFLAGS) -o $@

all: $(ALL)

xxxx: xxxx.o
circle: circle.o
swirl: swirl.o
naruto: naruto.o
slant: slant.o
katori: katori.o

clean:
	rm -f *.o $(ALL)

test: $(ALL)
	@echo "---------X----------"
	@echo "*  20 20" | ./xxxx
	@echo "------circle--------"
	@echo "*  20 20" | ./circle
	@echo "-------swirl--------"
	@echo "*  20 20" | ./swirl
	@echo "-------naruto-------"
	@echo "*  20 20" | ./naruto
	@echo "-------slant--------"
	@echo "*  20 20" | ./slant
	@echo "-------katori-------"
	@echo "*  20 20" | ./katori

LDFLAGS=-lm
