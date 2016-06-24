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
#include "PriorityQueue.h"
#include "QuickSort.h"
#include "BTree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned char A[20] = {'C','N','G','A','H','E','K','Q','M','F','W','L','T','Z','D','P','R','X','Y','S',};
    
    BTree tree;
    for(int i=0;i<20;i++){
        tree.insert(A[i]);
    }
//    buildMinHeapify<double>(A,10)
    HeapData<unsigned int> heapData(10);
    for(int i=0;i<10;i++){
        heapData[i] = A[i];
        heapData.setDataIndex(i,A[i]);
    }
    quickSort<unsigned int>(heapData,1,8);
    
    buildMaxHeapify<unsigned int>(heapData);
    deleteMaxHeapItem<unsigned int>(heapData,1);
    for(int i=0;i<9;i++){
        unsigned int t = heapData[i];
        
    }
    priorityQueueHeapIncKey<unsigned int>(heapData,3,100);
    
    return 0;
}

