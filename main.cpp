#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <iostream> 

int main()
{
    Tiger tiger(3); 
    Penguin pastor(5); 
    Turtle turtle(8); 
    std::cout << tiger.getAge() << std::endl;
    tiger.addAge(); 
    std::cout << tiger.getAge() << std::endl;
    return 0;
}
