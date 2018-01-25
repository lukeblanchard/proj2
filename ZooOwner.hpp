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
   int bank; 
   Zoo *zoo; 
public: 
    ZooOwner(int, int, int);
    void buyAnimal(Species); 
    Zoo* getZoo(); 
    ~ZooOwner(); 
}; 
#endif 
