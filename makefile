CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#LDFLAGS = -lboost_date_time

OBJS = Animal.o Tiger.o Penguin.o Turtle.o Zoo.o ZooOwner.o Game.o Menu.o NewAnimal.o main.o

SRCS = Animal.cpp Tiger.cpp Penguin.cpp Turtle.cpp Zoo.cpp ZooOwner.cpp Game.cpp Menu.cpp NewAnimal.cpp main.cpp 

HEADERS = Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp Zoo.hpp ZooOwner.hpp Game.hpp NewAnimal.hpp Menu.hpp

#target: dependencies 
#	rule to build

main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS} 
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f main ${OBJS}
