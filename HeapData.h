/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HeapData.h
 * Author: miaoliang
 *
 * Created on May 15, 2016, 10:21 PM
 */

#ifndef HEAPDATA_H
#define HEAPDATA_H

template <typename T> 
class HeapData{
public:
    HeapData(size_t _length);
    virtual ~HeapData();
    
    T* getData() const;
    size_t getLength()  const;
    
    T getDataIndex(size_t index);
    T* getDataPtrIndex(size_t index);
    
    void setDataIndex(size_t index,T value);
    void resize(size_t length);
    
    T& operator [](size_t index); 
    
private:
    T  data[10];
    size_t length;
};

template<typename T> HeapData<T>::HeapData(size_t _length)
{
    memset(data,0,sizeof(T)*_length);
    length = _length;
}

template<typename T> HeapData<T>::~HeapData()
{
 //   delete data;
    length = 0;
}

template<typename T> size_t HeapData<T>::getLength()  const
{
    return length;
}

template<typename T> T* HeapData<T>::getData() const
{
    return data;
}

template<typename T> T HeapData<T>::getDataIndex(size_t index)
{
    if(index>=0 && index<length){
        return data[index];
    }
}

template<typename T> T* HeapData<T>::getDataPtrIndex(size_t index)
{
    if(index>=0 && index<length){
        return &data[index];
    }
}

#endif /* HEAPDATA_H */

