/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QuickSort.h
 * Author: miaoliang
 *
 * Created on May 16, 2016, 1:10 AM
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "HeapData.h"
#include "Function.h"


template <typename T> size_t quickSortPartition(HeapData<T>& A,size_t p,size_t r)
{
    T x = A[r];
    int i = p-1;
    for(size_t j = p;j<r-1;j++){
        if(A[j]<=x){     
            i++;
            swap<T>(A[j],A[i]);
            
        }
    }
    swap<T>(A[i+1],A[r]);
    return i+1;
}

template <typename T> void quickSort(HeapData<T>& A,size_t p,size_t r){
    if(p<r){
        size_t q = quickSortPartition(A,p,r);
        quickSort<T>(A,p,q-1);
        quickSort<T>(A,q+1,r);
    }
}
#endif /* QUICKSORT_H */

