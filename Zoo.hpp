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

    enum Species {TIGER, PENGUIN, TURTLE};

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
    void addTiger(int age=0); 
    int getTigerCount(); 
    void addPenguin(int age=0); 
    int getPenguinCount(); 
    void addTurtle(int age=0); 
    int getTurtleCount(); 
    bool animalBirth(int); 
    void animalsAge(); 
    void animalDeath(int); 
    int getFoodCost(); 
    int getProfit(); 
    double getAnimalValue(); 
    ~Zoo(); 
}; 

#endif
