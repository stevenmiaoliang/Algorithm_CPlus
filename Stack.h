/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: miaoliang
 *
 * Created on May 16, 2016, 7:01 AM
 */

#ifndef STACK_H
#define STACK_H

template<typename T,int MAXDEPTH = 1024> 
class Stack{
public:
    Stack();
    virtual ~Stack();
    
    void push(T A);
    T pop();
    size_t size();
    bool empty();
private:
    int    top;
    T*     data;
    size_t maxDepth;
};

template<typename T,int MAXDEPTH = 1024> Stack::Stack()
{
    data = new T(MAXDEPTH);
    maxDepth = MAXDEPTH;
    top = -1;
}

template<typename T,int MAXDEPTH = 1024> Stack::~Stack()
{
    delete data;
    maxDepth = 0;
    top = -1;
}

template<typename T,int MAXDEPTH = 1024>  void Stack::push(T A)
{
    top++;
    if(top>= maxDepth){
        top--;
        return;//throw stack full error
    }
    data[top] = A;
}
template<typename T,int MAXDEPTH = 1024>  T Stack::pop()
{
    if(top < 0){
        T t;
        return t; //throw stack  empty error; 
    }
    T temp = data[top];
    top--;
}

template<typename T,int MAXDEPTH = 1024>  size_t Stack::size()
{
    return top+1;
    
}
template<typename T,int MAXDEPTH = 1024>  bool Stack::empty()
{
    if(top == -1){
        return true;
    }else{
        return false;
    }
}
#endif /* STACK_H */

