/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 218
 ** Description: Turtle implementation 
 ****************************************************************************/
#include "Turtle.hpp"
Turtle::Turtle(int age) : Animal(age, 10, 100, 0.05)
{
    this->food_cost = this->Animal::base_food_cost * 0.5;
}
