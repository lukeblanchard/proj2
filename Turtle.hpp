/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Turtle header file 
 ****************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal
{
private:
    int food_cost; 
public: 
    Turtle(int age=1);
    double getFoodCost(); 
}; 

#endif
