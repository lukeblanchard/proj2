/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Implementation for Tiger class 
 ****************************************************************************/
#include "Tiger.hpp"

Tiger::Tiger(int age) : Animal(age, 1, 10000, 0.2)
{
    this->food_cost = this->Animal::base_food_cost * 5; 
}

double Tiger::getFoodCost()
{
    return this->food_cost;
}
