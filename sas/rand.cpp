#include "rand.h"

RandomNum::RandomNum() {
    this->minNum = 4;
    this->maxNum = 4;
    std::random_device rd;
    std::mt19937 mt(rd());
}
RandomNum::RandomNum(int min, int max) {
    this->minNum = min; // min num;
    this->maxNum = max; // max random num;
    
    srand(time(NULL));
}
int RandomNum::genRandom() {
    std::mt19937 g(std::random_device{}());
    std::uniform_int_distribution<int> dist(minNum, maxNum);
    return dist(g);  // generates a random num between min and max;
}
int RandomNum::genRandom(int minimum, int maximum) {
    
    std::mt19937 g(std::random_device{}());
    std::uniform_int_distribution<int> dist(minimum, maximum);
    return dist(g);  // generates a random num between min and max; //generates a random num between min and max;
}

int RandomNum::getMinNum()
{
    return minNum;
}

int RandomNum::getMaxNum()
{
    return maxNum;
}

int RandomNum::randomInt(int exclusiveMax) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, exclusiveMax - 1);
    return dist(mt);
}

int RandomNum::randomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dist(0, max - min);
    return dist(mt) + min;
}

bool RandomNum::randomBool()
{
    double probability = 0.5;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::bernoulli_distribution dist(probability);
    return dist(mt);
}

int RandomNum::rollDie(int num, int die) {
    int total = 0;
    
    for (int i = 0; i < num; i++)
    {
        total += randomInt(die);
    }
    return total;
    
}
