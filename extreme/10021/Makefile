CC = g++
FLAG = -std=c++11 -O2 -Wall
TARGET := $(shell find . -name '*.cpp')
OBJECT = $(TARGET: .cpp=.o)
EXECUTABLE = a

all: $(TARGET) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECT)
	$(CC) $(OBJECT) -o $@

.cpp.o:
	$(CC) $(FLAG) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
