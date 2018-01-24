/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Header file for Animal class  
 ****************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal 
{
protected: 
    int age; 
    int number_of_babies;
    double cost; 
    double base_food_cost; 
    double payoff;
public: 
    Animal(int, int, double, double); 
    int getAge(); 
    void addAge(); 
    int getCost(); 
};

#endif
