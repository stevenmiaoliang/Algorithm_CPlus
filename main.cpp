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
    
    unsigned int  A[10] = {1,2,3,4,5,6,7,8,9,10};
//    buildMinHeapify<double>(A,10);
    HeapData<unsigned int> heapData(10);
    for(int i=0;i<10;i++){
        heapData[i] = A[i];
        heapData.setDataIndex(i,A[i]);
    }

    buildMaxHeapify<unsigned int>(heapData);
    
    for(int i=0;i<10;i++){
        unsigned int t = heapData[i];
        t++;
    }
    return 0;
}

