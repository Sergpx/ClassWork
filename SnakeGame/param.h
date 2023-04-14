#pragma once

#include <iostream>

using namespace std;
#define random(min, max) min + rand() % (max + 1 - min)

void setPosition(int* fruit, int y, int x);
void setPosition(int** snake, int y, int x);

const int SIZE_FIELD = 10;

const int MARGIN = 5;
const int MIN_SIZE_SNAKE = 3;