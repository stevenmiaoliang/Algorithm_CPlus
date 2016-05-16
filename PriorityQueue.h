/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueue.h
 * Author: miaoliang
 *
 * Created on May 15, 2016, 7:09 PM
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Heap.h"

template<typename T> T priorityQueueHeapExtractMax(HeapData<T>& A)
{
    if(A.getLength()<=0){
        return;
    }
    T max = A[0];
    A[0] = A[A.getLength()-1];
    A.resize(A.getLength()-1);
    maxHeapifyRecursion<T>(A,0);
}


template<typename T> void priorityQueueHeapIncKey(HeapData<T>& A,size_t index,T key)
{
    if(index>=A.getLength()){
        return;
    }
    if(key<A[index]){
        return;
    }
    A[index] = key;
    while(index>=0 && A[HEAP_PARENT(index)]<A[index]){
        swap<T>(A[index],A[HEAP_PARENT(index)]);
        index = HEAP_PARENT(index);
    }
}

#endif /* PRIORITYQUEUE_H */

