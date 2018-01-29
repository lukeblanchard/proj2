/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Implementation for ZooOwner class 
 ****************************************************************************/
#include "ZooOwner.hpp"

ZooOwner::ZooOwner(int tigers, int penguins, int turtles)
{
    zoo = new Zoo(tigers, penguins, turtles); 
    money = 100000 - zoo->getAnimalValue();  
}

bool ZooOwner::buyAnimal(int sp, int age)
{
    bool success = false; 
    switch(sp)
    {
        case(TIGER):
            if(money < 10000)
                std::cout << "**Insufficient funds to purchase a tiger." << std::endl;
            else
            {
                zoo->addTiger(age); 
                money -= 10000;
                success = true; 
            }    
            break; 
        case(PENGUIN): 
            if(money < 1000)                                                                      
                std::cout << "**Insufficient funds to purchase a penguin." << std::endl;
            else
            {
                zoo->addPenguin(age);  
                money -= 1000;
                success = true; 
            }                                                                            
            break; 
        case(TURTLE):
            if(money < 100)
                std::cout << "**Insufficient funds to purchase a turtle." << std::endl;
            else
            {
                zoo->addTurtle(age);
                money -= 100;
                success = true; 
            }
            break;
        case(NEWANIMAL):
            if(money < zoo->getNewAnimalCost())
                std::cout << "**Insufficient funds to purchase a " << zoo->getNewAnimalName() << "." << std::endl;
            else
            {
                zoo->addNewAnimal(age);
                money -= zoo->getNewAnimalCost();
                success = true; 
            }
    }
    return success;
}

void ZooOwner::addMoney(double profits)
{
    money += profits;
}

void ZooOwner::subtractMoney(double costs)
{
    money -= costs;
}

double ZooOwner::getMoney()
{
    return money;
}

void ZooOwner::setNewAnimalData(int babies, double food_cost, double cost, double profit, std::string name)
{
    zoo->setNewAnimalData(babies, food_cost, cost, profit, name); 
}

Zoo* ZooOwner::getZoo()
{
    return zoo;
}

ZooOwner::~ZooOwner()
{
    delete zoo;
}
