/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 26, 2017
 ** Description: Header file for New Animal class 
 ****************************************************************************/

#ifndef NEWANIMAL_HPP
#define NEWANIMAL_HPP
#include "Animal.hpp"
#include <string>

class NewAnimal : public Animal
{
private: 
   double food_cost;  
public:
    NewAnimal(int, int, double, double, double);
};

#endif
