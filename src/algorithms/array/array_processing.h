#pragma once

#include<algorithm>
#include<ctime>
#include<iostream>
#include<string>
#include"../../globals.h"

void prepareArray();

void randomizeArray(int max_rand = ARRAY_SIZE);

void updateArraySize(unsigned int size, int max_rand = ARRAY_SIZE);

void sortInOrder(bool ascending_order);

std::string shortPrintArray();

void resetResults();