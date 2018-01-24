/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Implementation for Zoo class 
 ****************************************************************************/
#include "Zoo.hpp"

Zoo::Zoo(int tigerCount, int penguinCount, int turtleCount)
{
    this->tigerCapacity = 10;  
    this->penguinCapacity = 10;  
    this->turtleCapacity = 10;  
    
    this->tigerCount = tigerCount;  
    this->penguinCount = penguinCount; 
    this->turtleCount = turtleCount; 

    *tigers = new Tiger[tigerCapacity]; 
    *penguins = new Penguin[penguinCapacity]; 
    *turtles = new Turtle[turtleCapacity]; 

    for(int i = 0; i < tigerCount; i++)
    {
        tigers[i] = new Tiger; 
    }
}
