/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Implementation for Animal class 
 ****************************************************************************/
#include "Animal.hpp"

Animal::Animal(int age, int number_of_babies, double cost, double payoff)
{
    this->age = age; 
    this->number_of_babies = number_of_babies; 
    this->base_food_cost = 10; 
    this->cost = cost; 
    this->payoff = payoff; 
}

int Animal::getAge()
{
    return this->age; 
}

void Animal::addAge()
{
    this->age += 1; 
}

double Animal::getFoodCost() 
{
    return this->base_food_cost; 
}

double Animal::getPayoff()
{
    return this->payoff;
}

double Animal::getCost()
{
    return this->cost;
}

Animal::~Animal() {} 
