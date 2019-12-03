#include <iostream>
#include <fstream>
#include <assert.h>
#include <cmath>

int calculateFuel(int n);
int calculateFuelPartTwo(int n);

int main() {
    std::ifstream file("input.txt");
    int input;
    int fuelPartOne = 0;
    int fuelPartTwo = 0;

    assert(calculateFuel(1969) == 654);
    assert(calculateFuel(100756) == 33583);
    assert(calculateFuel(12) == 2);
    assert(calculateFuel(14) == 2);
    assert(calculateFuelPartTwo(100756) == 50346);

    while (file >> input) {
        fuelPartOne += calculateFuel(input);
        fuelPartTwo += calculateFuelPartTwo(input);
    }

    std::cout << "Part I: " << fuelPartOne << std::endl;
    std::cout << "Part II: " << fuelPartTwo;

    return 0;
}

int calculateFuel(int n) {
    return floor(n/3) - 2;
}

int calculateFuelPartTwo(int n) {
    int initialFuel = calculateFuel(n);
    int finalFuel = 0;
    while (initialFuel > 0) {
        finalFuel += initialFuel;
        initialFuel = calculateFuel(initialFuel);
    }
    return finalFuel;
}