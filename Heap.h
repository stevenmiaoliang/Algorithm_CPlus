/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   sort.h
 * Author: miaoliang
 *
 * Created on May 14, 2016, 8:50 PM
 */

#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <cstddef>
#include "Function.h"
#define HEAP_PARENT(i)      i/2
#define HEAP_LEFT(i)        (2*i+1)
#define HEAP_RIGHT(i)       (2*i+2)

template <typename T> void maxHeapifyRecursion(T* A,size_t length,int i)
{
    if(A == NULL || length == 0){
        return;
    }
    size_t l = HEAP_LEFT(i);
    size_t r = HEAP_RIGHT(i);
    size_t largest = 0;
    if(l<length && A[l]>A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r<length && A[r]>A[largest]){
        largest = r;
    }

    if(largest != i){
        swap<T>(A[i],A[largest]);
        for(int i=0;i<length;i++){
            std::cout<<A[i]<<" ";
        }
        std::cout<<std::endl;
        maxHeapifyRecursion<T>(A,length,largest);
    }
}

template <typename T> void maxHeapifyCircle(T* A,size_t length,int i)
{
    if(A == NULL || length == 0){
        return;
    }

    size_t largest = i;
    size_t largestTemp = largest;
    while(largest<length){
        size_t l = HEAP_LEFT(largest);
        size_t r = HEAP_RIGHT(largest);
        if(l<length && A[l]>A[largest]){
            largestTemp = l;
        }else{
            largestTemp = largest;
        }
        if(r<length && A[r]>A[largestTemp]){
            largestTemp = r;
        }

        if(largestTemp != largest){
            swap<T>(A[largestTemp],A[largest]);
        }else{
            break;
        }
         for(int i=0;i<length;i++){
            std::cout<<A[i]<<" ";
        }
        std::cout<<std::endl;
        largest = largestTemp;

    }
}

template <typename T> void buildMaxHeapify(T* A,size_t length){
    for(int i=length/2;i>=0;i--){
        maxHeapifyCircle<T>(A,length,i);
    }
}

template <typename T> void minHeapify(T* A,size_t length,int i)
{
    if(A == NULL || length == 0){
        return;
    }
    size_t l = HEAP_LEFT(i);
    size_t r = HEAP_RIGHT(i);
    size_t smallest = 0;
    if(l<length && A[l]<A[i]){
        smallest = l;
    }else{
        smallest = i;
    }
    if(r<length && A[r]<A[smallest]){
        smallest = r;
    }

    if(smallest != i){
        swap<T>(A[i],A[smallest]);
        for(int i=0;i<length;i++){
            std::cout<<A[i]<<" ";
        }
        std::cout<<std::endl;
        minHeapify<T>(A,length,smallest);
    }
}

template <typename T> void buildMinHeapify(T* A,size_t length){
    for(int i=length/2;i>=0;i--){
        minHeapify<T>(A,length,i);
    }
}


#endif /* HEAP_H */

