CC = g++
CFLAGS = -std=c++11 -c -Wall -O2
SOURCE = 908.cpp
OBJECTS = 908.o
EXE = a

all: $(SOURCE) $(EXE)

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	@rm -f *.o

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

dep:
	$(CC) -M *.cpp > .depend

clean:
	rm -f $(OBJECTS) $(EXE) .depend
