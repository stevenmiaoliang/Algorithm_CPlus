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
#include "RedBlackTree.h"
#include "vEBTree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned char A[7] = {2,3,4,5,7,14,15};
    
    vEBTree vebTree;
    vebTree.create(vebTree.root,16);
    for(int i=0;i<7;i++){
        vebTree.insert(vebTree.root,A[i]);
    }
    int successor = vebTree.presuccessor(vebTree.root,5);
    bool ret = vebTree.member(vebTree.root,3);
    
    
    RBTree tree;
    for(int i=0;i<7;i++){
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

