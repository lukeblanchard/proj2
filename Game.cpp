/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 218
 ** Description: Implementation files for Game class  
 ****************************************************************************/
#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <string>

Game::Game()
{
    int tigers; 
    int penguins; 
    int turtles; 

    menu = new Menu;

    menuIntIO buyAnimals;
    buyAnimals.push_back(std::make_pair("\nTiger cost: $10,000\nHow many tigers do you want to buy?\nPlease enter 1 or 2: ", &tigers)); 
    buyAnimals.push_back(std::make_pair("\nPenguin cost: $1,000\nHow many penguins do you want to buy?\nPlease enter 1 or 2: ", &penguins)); 
    buyAnimals.push_back(std::make_pair("\nTurtle cost: $100\nHow many turtles do you want to buy?\nPlease enter 1 or 2: ", &turtles)); 
    
    std::cout << std::endl;
    std::cout << "ZOO TYCOON" << std::endl; 
    std::cout << "----------" << std::endl;
    std::cout << "Welcome to Zoo Tycoon!\nFirst you need animals to start your zoo!" << std::endl; 
    std::cout << "Starting funds: $100,000" << std::endl;
    std::cout << std::endl;

    menu->load(buyAnimals, 1, 2); 

    tycoon = new ZooOwner(tigers, penguins, turtles);    
    zoo = tycoon->getZoo(); 

    playGame(); 
}

void Game::playGame()
{
    bool play; 
    do 
    {
        day(); 
        menuBoolIO keepPlaying; 
        keepPlaying.push_back(std::make_pair("Do you want to keep playing? (y/n) ", &play)); 

        menu->load(keepPlaying); 

    } while(play && checkMoney()); 

    if(!checkMoney())
    {
        std::cout << "You ran out of money! Better luck next time!" << std::endl; 
    }
    else 
    {
        std::cout << "Thanks for playing!" << std::endl; 
    }
}

void Game::sickness()
{
    int victim = rand() % 3; 
    zoo->animalDeath(victim);
}

void Game::attendance_boom()
{
    int tigerCount = zoo->getTigerCount();           
    tycoon->addMoney(350 * tigerCount); 
}

bool Game::baby_born() 
{
    int a, b, c; 
    bool success; 
    a = rand() % 3; 
    b = rand() % 3; 
    c = rand() % 3; 
    while(a == b || a == c || b == c)
    {
        a = rand() % 3; 
        b = rand() % 3; 
        c = rand() % 3; 
    }
    success = zoo->animalBirth(a); 
    if(!success)
    {
        success = zoo->animalBirth(b); 
        if(!success)
        {
            success = zoo->animalBirth(c); 
        }
    }
    return success;
}

void Game::randomEvent()
{
    std::ifstream file;  
    file.open("statusMessages.txt"); 
    std::string status; 
    int event = rand() % 4; 
    int lineCount = 0; 
    bool newBaby = false; 

    switch(event)
    {
        case 0:
            sickness(); 
            break; 
        case 1:
            attendance_boom(); 
            break; 
        case 2:
            newBaby = baby_born(); 
            break; 
        case 3: 
            break; 
    }
    do
    {
        std::getline(file, status); 
        lineCount++;
    } while(lineCount <= event);

    if(event == 2 && !newBaby)
        std::getline(file, status); 
    std::cout << status << std::endl;
    file.close();

}

void Game::day()
{
    int foodCosts; 
    int profit;
    bool buyAnimal;
    int choice;
    double moneyBeginDay = tycoon->getMoney(); 
    int moneyEndDay; 
    std::cout << std::endl;
    std::cout << "Daily Summary" << std::endl;
    std::cout << "-------------" << std::endl;
    //age
    zoo->animalsAge(); 
    //feed and subtract cost
    foodCosts = zoo->getFoodCost(); 
    tycoon->subtractMoney(foodCosts); 
    randomEvent();  
    //calculate and add profit
    profit = zoo->getProfit(); 
    tycoon->addMoney(profit); 
    
    std::cout << std::endl;
    std::cout << "Animal Counts" << std::endl;
    std::cout << "Tigers: " << zoo->getTigerCount() << std::endl;
    std::cout << "Penguins: " << zoo->getPenguinCount() << std::endl; 
    std::cout << "Turtles: " << zoo->getTurtleCount() << std::endl; 
    std::cout << std::endl;

    moneyEndDay = tycoon->getMoney(); 

    std::cout << "Daily profit (after feeding costs): " << moneyEndDay - moneyBeginDay << std::endl;
    std::cout << std::endl; 
    std::cout << "Current funds: " << moneyEndDay << std::endl; 

    menuBoolIO buyAnimalPrompt; 
    buyAnimalPrompt.push_back(std::make_pair("Do you want to buy another animal? (y/n) ", &buyAnimal)); 
    menu->load(buyAnimalPrompt); 

    if(buyAnimal)
    {
        bool validChoice = false; 
        do
        {
            menuIntIO animalChoices; 
            animalChoices.push_back(std::make_pair("1.Tiger (cost: $10,000)\n2.Penguin (cost: $1,000)\n3.Turtle (cost: $100))\n4.Do not buy an animal\nEnter choice: ", &choice)); 
            menu->load(animalChoices, 1, 4); 
            if(choice == 4)
            {
                validChoice = true; 
            }
            else
            {
                validChoice = tycoon->buyAnimal(choice - 1, 3);
            }
        } while(!validChoice);
        if (choice != 4)
        {
            std::cout << std::endl; 
            std::cout << "Animal Counts" << std::endl;
            std::cout << "Tigers: " << zoo->getTigerCount() << std::endl; 
            std::cout << "Penguins: " << zoo->getPenguinCount() << std::endl;  
            std::cout << "Turtles: " << zoo->getTurtleCount() << std::endl; 
            std::cout << std::endl;
            std::cout << "Current funds: " << tycoon->getMoney() << std::endl; 
        }
    }
}

bool Game::checkMoney()
{
    bool hasFunds; 
    if(tycoon->getMoney() <= 0)
        hasFunds = false;
    else
        hasFunds = true; 
    return hasFunds;
}

Game::~Game() 
{
    delete tycoon;
    delete menu;
}
