/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 2018 
 ** Description: Header file for Game class 
 ****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "ZooOwner.hpp"

class Game 
{
private: 
    ZooOwner *tycoon;
public: 
    Game(int, int, int);  
    void day(); 
    void sickness(); 
    void attendance_boom(); 
    void baby_born(); 
    void print(); 
    ~Game(); 
}; 

#endif
