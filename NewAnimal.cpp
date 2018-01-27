/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 26, 2018
 ** Description: Implementation for New Animal class 
 ****************************************************************************/
#include "NewAnimal.hpp"

NewAnimal::NewAnimal(int age, int babies, double food_cost, double cost, double profit) : Animal(age, babies, cost, profit)
{
    this->food_cost = food_cost;  
}

