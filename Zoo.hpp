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
#include "NewAnimal.hpp"
#include <string> 

    enum Species {TIGER, PENGUIN, TURTLE, NEWANIMAL};
    enum Feed {CHEAP, GENERIC, PREMIUM}; 

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

    NewAnimal **newAnimals; 
    int newAnimalCount; 
    int newAnimalCapacity; 
    int newAnimalBabies; 
    double newAnimalFoodCost; 
    double newAnimalCost; 
    double newAnimalProfit; 
    std::string newAnimalName; 
    bool hasNewAnimal;
public: 
    Zoo(int, int, int); 
    void addTiger(int age=0); 
    int getTigerCount(); 
    void addPenguin(int age=0); 
    int getPenguinCount(); 
    void addTurtle(int age=0); 
    int getTurtleCount(); 
    int getNewAnimalCount(); 
    void initializeNewAnimals(int);
    double getNewAnimalCost(); 
    std::string getNewAnimalName(); 
    void addNewAnimal(int age=0);
    bool animalBirth(int); 
    void animalsAge(); 
    void animalDeath(int); 
    int getFoodCost(int); 
    int getProfit(); 
    double getAnimalValue(); 
    bool includesNewAnimal(); 
    void setNewAnimalData(int, double, double, double, std::string);
    ~Zoo(); 
}; 

#endif
