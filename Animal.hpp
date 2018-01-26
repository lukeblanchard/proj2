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
    double base_food_cost; 
    double payoff;
    double cost; 
public: 
    Animal(int, int, double, double); 
    int getAge(); 
    double getPayoff(); 
    double getCost(); 
    void addAge(); 
    virtual double getFoodCost(); 
    virtual ~Animal(); 
};

#endif
