CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g
CXXFLAGS += -std=c++11
LDFLAGS =

SRC = $(wildcard *.cpp)
OUT = $(SRC:.cpp=.out)

all: $(OUT)

help:
	@echo "'make all' to build $(SRC)"
	@echo "'make help' to show help"
	@echo "'make rebuild' to build from scratch"
	@echo "'make clean' to delete everything except source files"
	@echo "'make vars' to print file-related variables"

rebuild: clean all

%.out: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUT)

vars:
	@echo "SRC = $(SRC)"
	@echo "OUT = $(OUT)"

.PHONY: all help rebuild clean vars
