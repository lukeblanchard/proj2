/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Implementation for Penguin class 
 ****************************************************************************/
#include "Penguin.hpp"

Penguin::Penguin() : Animal(1, 5, 1000, 0.1) 
{
    this->food_cost = this->Animal::base_food_cost;
}

Penguin::Penguin(int age) : Animal(age, 5, 1000, 0.1) 
{
    this->food_cost = this->Animal::base_food_cost;
}

