#CXXFLAGS=-ggdb -std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CXXFLAGS=-std=c++17 -O3

INC = -I DomainObject -I DomainObject/include -I Cache -I Cache/include

SRC = main.cpp
DO_SRCS = $(wildcard DomainObject/src/*.cpp)
INFRA_SRC = $(wildcard Cache/src/*.cpp)

all: $(SRCS)
	@echo ----------------compiling executable program app--------------------
	g++ $(CXXFLAGS) $(INFRA_SRC) $(DO_SRCS) $(SRC) $(INC) -o app 

clean:
	@echo ----------------removing executable program app--------------------
	rm app

