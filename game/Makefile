CC := g++
CXXFLAGS  := -std=c++11 -g -Wall
TARGET := game

.PHONY : all clean
all: $(TARGET)
clean:
	rm game
	rm main.o

$(TARGET):main.cpp
	@echo "building target..."
	$(CC) $(CXXFLAGS) -o $@ $^
