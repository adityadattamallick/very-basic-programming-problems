#include <iostream>
#include <cstdlib>
#include <ctime>

int diceRoller(); // Random number generator

int main() {
    std::cout << diceRoller() << std::endl;
    return 0;
}

int diceRoller() {
    int min{1};
    int max{6};
    std::time_t now = std::time(nullptr);
    srand(now); // sets the starting point or the seed for generating the random number using rand()
    return (rand() % max +
            min); // (Random Number % 6) generates a number always less than 6, and in range of 0 to 5. As dice has 1 as the minimum value and 6 as the maximum value, hence adding 1 afterwards to get the proper value
}
