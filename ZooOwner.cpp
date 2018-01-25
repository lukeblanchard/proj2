/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Implementation for ZooOwner class 
 ****************************************************************************/
#include "ZooOwner.hpp"

ZooOwner::ZooOwner(int tigers, int penguins, int turtles)
{
    zoo = new Zoo(tigers, penguins, turtles);
    bank = 100000; 
}

void ZooOwner::buyAnimal(Species s)
{
    switch(s)
    {
        case(TIGER):
            if(bank < 10000)
                std::cout << "Insufficient funds to purchase a tiger." << std::endl;
            else
            {
                zoo->buyTiger(); 
                bank -= 10000;
            }    
            break; 
        case(PENGUIN): 
            if(bank < 1000)                                                                      
                std::cout << "Insufficient funds to purchase a penguin." << std::endl;
            else
            {
                zoo->buyPenguin();  
                bank -= 1000;
            }                                                                            
            break; 
        case(TURTLE):
            if(bank < 100)
                std::cout << "Insufficient funds to purchase a turtle." << std::endl;
            else
            {
            zoo->buyTurtle();
            bank -= 100;
            }
    }
   
}

Zoo* ZooOwner::getZoo()
{
    return zoo;
}

ZooOwner::~ZooOwner()
{
    delete zoo;
}
