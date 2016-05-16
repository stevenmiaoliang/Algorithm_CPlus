/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: miaoliang
 *
 * Created on May 14, 2016, 8:48 PM
 */

#include <cstdlib>
#include <iostream>
#include "Heap.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    double A[10] = {1,2,3,4,5,6,7,8,9,10};
//    buildMinHeapify<double>(A,10);
    buildMaxHeapify<double>(A,10);
    std::cout<<"Result:";
    for(int i=0;i<11;i++){
        std::cout<<A[i]<<" ";
    }
    return 0;
}

