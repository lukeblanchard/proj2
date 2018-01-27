/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 24, 218
 ** Description: Implementation files for Game class  
 ****************************************************************************/
#include "Game.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Game::Game()
{
    int tigers; 
    int penguins; 
    int turtles; 
    bool createNewAnimal;

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

    menuBoolIO newSpecies; 
    newSpecies.push_back(std::make_pair("\nDo you want to add a new animal to the zoo? (y/n) ", &createNewAnimal));
    
    menu->load(newSpecies); 

    if(createNewAnimal)
    {
        int babies; 
        int newAnimalsCount;
        double food_cost; 
        double cost; 
        double profit; 
        std::string name; 

        menuIntIO babyNumber; 
        babyNumber.push_back(std::make_pair("How many offspring can an adult birth? Please enter a number from 1 to 5: ", &babies)); 

        menuDoubleIO costPrompts; 
        costPrompts.push_back(std::make_pair("How much does it cost to purchase this animal (in USD)? ", &cost)); 
        costPrompts.push_back(std::make_pair("How much does it cost to feed per day (in USD)? ", &food_cost)); 

        menuDoubleIO profitPrompt;
        profitPrompt.push_back(std::make_pair("How much profit does the animal add to the zoo each day?\n(Profit is calculated as a percentage of the animal's market value) Please enter a number from 0.01 to 0.2: ", &profit)); 

        menuStringIO animalName; 
        animalName.push_back(std::make_pair("What do you call this animal? ", &name)); 

        menu->load(babyNumber, 1, 5); 
        menu->load(costPrompts); 
        std::cout << "Game Constructor, double newAnimalCost: " << cost << std::endl;
        menu->load(profitPrompt, 0.01, 0.2); 
        menu->load(animalName); 

        std::cout << "\n" << name << " cost: " << "$" << cost << "\n"; 

        menuIntIO buyNewAnimal;
        buyNewAnimal.push_back(std::make_pair("\nHow many do you want to buy?\nPlease enter 1 or 2: ", &newAnimalsCount)); 

        menu->load(buyNewAnimal); 

        //Need zoo to set Data, need data to set zoo
        tycoon->setNewAnimalData(babies, food_cost, cost, profit, name); 
        zoo->initializeNewAnimals(newAnimalsCount); 
        tycoon->subtractMoney(newAnimalsCount * cost); 
    }
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
    int numberOfSpecies; 
    int victim;
    if(zoo->includesNewAnimal())
        numberOfSpecies = 4; 
    else
        numberOfSpecies = 3; 
    victim = rand() % numberOfSpecies; 
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

    if(zoo->includesNewAnimal())
    {
        int d; 
        a = rand() % 4; 
        b = rand() % 4; 
        c = rand() % 4; 
        d = rand() % 4;
        while(a == b || a == c || a == d || b == c || b == d || c == d)
        {
            a = rand() % 4; 
            b = rand() % 4; 
            c = rand() % 4; 
            d = rand() % 4; 
        }
        success = zoo->animalBirth(a); 
        if(!success)
        {
            success = zoo->animalBirth(b); 
            if(!success)
            {
                success = zoo->animalBirth(c); 
                if(!success)
                {
                    success = zoo->animalBirth(d); 
                }
            }
        }
    }
    else
    {
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
    if(zoo->includesNewAnimal())
        std::cout << zoo->getNewAnimalName() << ": " << zoo->getNewAnimalCount() << std::endl; 
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
            if(zoo->includesNewAnimal())
            {
                std::ostringstream costString; 
                costString << zoo->getNewAnimalCost(); 
                std::string prompt = "1.Tiger (cost: $10,000)\n2.Penguin (cost: $1,000)\n3.Turtle (cost: $100)\n4."; 
                prompt += zoo->getNewAnimalName(); 
                prompt += " (cost: $"; 
                prompt += costString.str();  
                prompt += ")"; 
                prompt += "\n5.Do not buy an animal\nEnter choice: "; 
                animalChoices.push_back(std::make_pair(prompt, &choice)); 
                menu->load(animalChoices, 1, 5); 
                if(choice == 5)
                {
                    validChoice = true; 
                }
                else
                {
                    validChoice = tycoon->buyAnimal(choice - 1, 3); 
                }
            }
            else
            {
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
            }
        } while(!validChoice);
        if (choice != 4 && !zoo->includesNewAnimal())
        {
            std::cout << std::endl; 
            std::cout << "Animal Counts" << std::endl;
            std::cout << "Tigers: " << zoo->getTigerCount() << std::endl; 
            std::cout << "Penguins: " << zoo->getPenguinCount() << std::endl;  
            std::cout << "Turtles: " << zoo->getTurtleCount() << std::endl; 
            std::cout << std::endl;
            std::cout << "Current funds: " << tycoon->getMoney() << std::endl; 
        }
        else if (choice != 5 && zoo->includesNewAnimal())
        {
            std::cout << std::endl; 
            std::cout << "Animal Counts" << std::endl;
            std::cout << "Tigers: " << zoo->getTigerCount() << std::endl; 
            std::cout << "Penguins: " << zoo->getPenguinCount() << std::endl;  
            std::cout << "Turtles: " << zoo->getTurtleCount() << std::endl; 
            std::cout << zoo->getNewAnimalName() << ": " << zoo->getNewAnimalCount() << std::endl;
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
