//
// Created by Arash Khajelou on 3/4/16.
//

#ifndef ALGORITHMCOURSEHW_MARRIAGEPROBLEM_H
#define ALGORITHMCOURSEHW_MARRIAGEPROBLEM_H


#include <iostream>

using namespace std;

#define SIZE 5

int men[SIZE][SIZE] = {
        {2, 1, 3, 4, 0}, //this means man with id '0' prefers women with id's [2,1,3,4,0]
        {1, 3, 4, 2, 0},
        {0, 1, 4, 3, 2},
        {0, 1, 2, 3, 4},
        {4, 3, 2, 1, 0}
};

int women[SIZE][SIZE] = {
        {1, 2, 4, 0, 3}, //this means woman with id '0' prefers men with id's [1,2,4,0,3]
        {1, 3, 4, 2, 0},
        {0, 1, 4, 3, 2},
        {0, 1, 2, 3, 4},
        {4, 3, 2, 1, 0}
};

int menMarriage[SIZE] = {-1, -1, -1, -1, -1}; //this means all men are
int womanMarriage[SIZE] = {-1, -1, -1, -1, -1}; //this means all men are

int getFirstSingleMan() {
    for (int i = 0; i < SIZE; i++) {
        if (menMarriage[i] == -1)
            return i;
    }
    return -1;
}

int getIndex(int *array, int needle) {
    for (int i; i < SIZE; i++) {
        if (array[i] == needle)
            return i;
    }
    return -1;
}

void testMarriageProblem() {

    int single = -1;
    int counter = 0;
    while ((single = getFirstSingleMan()) != -1) {
        for (int i = 0; i < SIZE; i++) {
            counter++;
            if (womanMarriage[men[single][i]] == -1) {
                womanMarriage[men[single][i]] = single;
                menMarriage[single] = men[single][i];
                break;
            } else {
                if (getIndex(women[men[single][i]], womanMarriage[men[single][i]]) >
                    getIndex(women[men[single][i]], single)) {
                    menMarriage[womanMarriage[men[single][i]]] = -1;
                    womanMarriage[men[single][i]] = single;
                    menMarriage[single] = men[single][i];
                    break;
                }
            }
        }
    }

    std::cout << "Count of while is : " << counter << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Man [" << i << "] is married to Woman [" << menMarriage[i] << "]" << endl;
    }
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Woman [" << i << "] is married to Woman [" << womanMarriage[i] << "]" << endl;
    }
}


#endif //ALGORITHMCOURSEHW_MARRIAGEPROBLEM_H
