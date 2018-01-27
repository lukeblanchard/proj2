/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018 
 ** Description: Header file for Game class 
 ****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "ZooOwner.hpp"
#include "Menu.hpp"
#include "NewAnimal.hpp"

class Game 
{
private: 
    ZooOwner *tycoon;
    Zoo *zoo; 
    Menu *menu;
public: 
    Game();  
    void makeNewAnimal(); 
    void day(); 
    void playGame(); 
    void randomEvent(int); 
    void sickness(); 
    void attendance_boom(); 
    bool baby_born(); 
    bool checkMoney(); 
    ~Game(); 
}; 

#endif
