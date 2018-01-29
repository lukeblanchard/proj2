/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018
 ** Description: Header file for ZooOwner class 
 ****************************************************************************/

#ifndef ZOOOWNER_HPP
#define ZOOOWNER_HPP
#include "Zoo.hpp"
#include <string> 
#include <iostream> 

class ZooOwner 
{
private: 
   double money; 
   Zoo *zoo; 
public: 
    ZooOwner(int, int, int);
    bool buyAnimal(int, int); 
    void addMoney(double); 
    void subtractMoney(double); 
    double getMoney();
    void setNewAnimalData(int, double, double, double, std::string); 
    Zoo* getZoo(); 
    ~ZooOwner(); 
}; 
#endif 
