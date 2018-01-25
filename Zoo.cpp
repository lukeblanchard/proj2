/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Implementation for Zoo class 
 ****************************************************************************/
#include "Zoo.hpp"
#include <iostream>

Zoo::Zoo(int tigerCount, int penguinCount, int turtleCount)
{
    this->tigerCapacity = 10;  
    this->penguinCapacity = 10;  
    this->turtleCapacity = 10;  
    
    this->tigerCount = tigerCount;  
    this->penguinCount = penguinCount; 
    this->turtleCount = turtleCount; 

    tigers = new Tiger*[tigerCapacity]; 
    penguins = new Penguin*[penguinCapacity]; 
    turtles = new Turtle*[turtleCapacity]; 

    for(int i = 0; i < tigerCount; i++)
    {
        tigers[i] = new Tiger; 
    }

    for(int i = 0; i < penguinCount; i++)
    {
        penguins[i] = new Penguin; 
    }

    for(int i = 0; i < turtleCount; i++)
    {
        turtles[i] = new Turtle; 
    }
}

void Zoo::buyTiger()
{
    if(tigerCount + 1 > tigerCapacity)
    {
        tigerCapacity *= 2; 
        Tiger **newTigers = new Tiger*[tigerCapacity]; 
        for(int i = 0; i < tigerCount; i++)
            newTigers[i] = tigers[i]; 
        delete [] tigers; 
        tigers = newTigers; 
    }
    tigers[tigerCount] = new Tiger(3);     
    tigerCount += 1; 
}

void Zoo::buyPenguin()
{
    if(penguinCount + 1 > penguinCapacity)
    {
        penguinCapacity *= 2; 
        Penguin **newPenguins = new Penguin*[penguinCapacity]; 
        for(int i = 0; i < penguinCount; i++)
            newPenguins[i] = penguins[i]; 
        delete [] penguins; 
        penguins = newPenguins; 
    }
    penguins[penguinCount] = new Penguin(3);     
    penguinCount += 1; 
}

void Zoo::buyTurtle()
{
    if(turtleCount + 1 > turtleCapacity)
    {
        turtleCapacity *= 2; 
        Turtle **newTurtles = new Turtle*[turtleCapacity]; 
        for(int i = 0; i < turtleCount; i++)
            newTurtles[i] = turtles[i]; 
        delete [] turtles; 
        turtles = newTurtles; 
    }
    turtles[turtleCount] = new Turtle(3);     
    turtleCount += 1; 
}

void Zoo::animalDies(int species)
{
    switch(species)
    {
        case(TIGER):
            tigerCount -= 1; 
            delete tigers[tigerCount]; 
            break; 
        case(PENGUIN):
            penguinCount -= 1; 
            delete penguins[penguinCount];
            break; 
        case(TURTLE):
            turtleCount -= 1; 
            delete turtles[turtleCount]; 
            break;
    }
}

Zoo::~Zoo() 
{
    for(int i = 0; i < tigerCount; i++) 
    {
        delete tigers[i]; 
    }
    delete [] tigers; 
    
    for(int i = 0; i < penguinCount; i++) 
    {
        delete penguins[i]; 
    }
    delete [] penguins; 
    
    for(int i = 0; i < turtleCount; i++) 
    {
        delete turtles[i]; 
    }
    delete [] turtles; 

}

