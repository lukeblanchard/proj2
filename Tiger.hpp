/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Header file for Tiger class 
 ****************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal
{
private: 
    double food_cost; 
public: 
    Tiger(int age=1); 
}; 

#endif
