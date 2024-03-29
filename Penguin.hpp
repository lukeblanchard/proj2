/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Header file for Penguin class 
 ****************************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal
{
private: 
    double food_cost;
public:
    Penguin(int age=1); 
}; 

#endif 
