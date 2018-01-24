/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Header file for Zoo class 
 ****************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

class Zoo 
{
private:
    Tiger **tigers; 
    int tigerCount; 
    int tigerCapacity; 
    Penguin **penguins; 
    int penguinCount; 
    int penguinCapacity;
    Turtle **turtles; 
    int turtleCount; 
    int turtleCapacity;
public: 
    Zoo(int, int, int); 
}; 

#endif
