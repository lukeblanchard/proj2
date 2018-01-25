/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 218
 ** Description: Implementation files for Game class  
 ****************************************************************************/
#include "Game.hpp"
#include <iostream>

Game::Game(int tigers, int penguins, int turtles)
{
    tycoon = new ZooOwner(tigers, penguins, turtles);    
}

void Game::sickness()
{
    int victim = rand() % 3; 
    Zoo *exhibits = tycoon->getZoo(); 
    exhibits->animalDies(victim);
}

void Game::print() 
{
    std::cout << "Tigers: " << std::endl;
}

Game::~Game() 
{
    delete tycoon;
}
