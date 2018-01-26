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

void Zoo::addTiger(int age)
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
    tigers[tigerCount] = new Tiger(age);     
    tigerCount += 1; 
}

void Zoo::addPenguin(int age)
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
    penguins[penguinCount] = new Penguin(age);     
    penguinCount += 1; 
}

void Zoo::addTurtle(int age)
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
    turtles[turtleCount] = new Turtle(age);     
    turtleCount += 1; 
}

void Zoo::animalDeath(int species)
{
    switch(species)
    {
        case(TIGER):
            tigerCount -= 1; 
            delete tigers[tigerCount]; 
            std::cout << "A tiger dies." << std::endl;
            break; 
        case(PENGUIN):
            penguinCount -= 1; 
            delete penguins[penguinCount];
            std::cout << "A penguin dies." << std::endl;
            break; 
        case(TURTLE):
            turtleCount -= 1; 
            delete turtles[turtleCount]; 
            std::cout << "A turtle dies." << std::endl;
            break;
    }
}

int Zoo::getTigerCount()
{
    return tigerCount;
}

int Zoo::getPenguinCount()
{
    return penguinCount;
}

int Zoo::getTurtleCount()
{
    return turtleCount;
}

bool Zoo::animalBirth(int species)
{
    bool success = false; 
    switch(species)
    {
        case(TIGER):
            for(int i = 0; i < tigerCount; i++)
            {
                if(tigers[i]->getAge() >= 3)
                {
                    addTiger(); 
                    success = true; 
                    std::cout << "You have a new tiger!" << std::endl;
                    break; 
                }
            }
            break; 
        case(PENGUIN):
            for(int i = 0; i < penguinCount; i++)
            {
                if(penguins[i]->getAge() >= 3)
                {
                    addPenguin(); 
                    success = true; 
                    std::cout << "You have a new penguin!" << std::endl;
                    break; 
                }
            }
            break; 
        case(TURTLE):
            for(int i = 0; i < turtleCount; i++)
            {
                if(turtles[i]->getAge() >= 3)
                {
                    addTurtle(); 
                    success = true; 
                    std::cout << "You have a new turtle!" << std::endl;
                    break; 
                }
            }
            break; 
    }
    return success; 

}

void Zoo::animalsAge()
{
    for(int i = 0; i < tigerCount; i++) 
    {
        tigers[i]->addAge(); 
    }
    for(int i = 0; i < penguinCount; i++) 
    {
        penguins[i]->addAge(); 
    }
    for(int i = 0; i < turtleCount; i++) 
    {
        turtles[i]->addAge(); 
    }
}

int Zoo::getFoodCost()
{
    std::cout << std::endl;
    std::cout << "Daily Food Cost" << std::endl;
    int total = 0; 
    int tigerFood; 
    int penguinFood; 
    int turtleFood; 
    if(tigerCount >= 1) 
    {
        tigerFood = tigers[tigerCount-1]->getFoodCost() * tigerCount; 
        std::cout << "Tigers: " << tigerFood << std::endl;
        total += tigerFood;
    }
    if(penguinCount >= 1) 
    {
        penguinFood = penguins[penguinCount-1]->getFoodCost() * penguinCount; 
        std::cout << "Penguins: " << penguinFood << std::endl;
        total += penguinFood;
    }
    if(turtleCount >= 1) 
    {
        turtleFood = turtles[turtleCount-1]->getFoodCost() * turtleCount; 
        std::cout << "Turtles: " << turtleFood << std::endl;
        std::cout << std::endl;
        total += turtleFood;
    }
    return total;
}

int Zoo::getProfit()
{
    int total = 0;
    if(tigerCount >= 1) 
        total += tigers[tigerCount-1]->getCost() * tigers[tigerCount-1]->getPayoff() * tigerCount; 
    if(penguinCount >= 1) 
        total += penguins[penguinCount-1]->getCost() * penguins[penguinCount-1]->getPayoff() * penguinCount; 
    if(turtleCount >= 1) 
        total += turtles[turtleCount-1]->getCost() * turtles[turtleCount-1]->getPayoff() * turtleCount; 
    return total;
}

double Zoo::getAnimalValue()
{
    int total = 0; 
    if(tigerCount >= 1) 
        total += tigers[tigerCount-1]->getCost() * tigerCount; 
    if(penguinCount >= 1) 
        total += penguins[penguinCount-1]->getCost() * penguinCount; 
    if(turtleCount >= 1) 
        total += turtles[turtleCount-1]->getCost() * turtleCount; 
    return total;
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

