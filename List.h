/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: miaoliang
 *
 * Created on May 16, 2016, 7:15 AM
 */

#ifndef LIST_H
#define LIST_H

template<typename T>
class ListNode{
public:
    ListNode();
    ListNode(T t);
    ~ListNode();
    
    T getKey(){return key;};
    ListNode<T>* pre;
    ListNode<T>* next;
private:
    T key;
};

template<typename T> ListNode<T>::ListNode()
{
    pre = 0;
    next = 0;
}

template<typename T> ListNode<T>::ListNode(T t)
{
    pre = 0;
    next = 0;
    key = t;
}

template<typename T> ListNode<T>::~ListNode(){
    pre = 0;
    next = 0;
}

template<typename T>
class List{
    friend class ListNode<T>;
public: 
    List();
    virtual ~List();
    
    void add(T t);
    void remove(size_t index);
    void remove(T t);
private:
    ListNode<T>* operator [](size_t index);
private:
    ListNode<T>*  tail;
    ListNode<T>  root;
    size_t       listLength;
};

template<typename T> List<T>::List()
{
    listLength = 0;
    tail = &root;
}

template<typename T> List<T>::~List()
{
    while(tail != &root){
        ListNode<T>* tmp = tail;
        tail = tail->pre;
        delete tmp;
    }
}

template<typename T> void List<T>::add(T t){
    ListNode<T>* node = new ListNode<T>(t);
    if(node == 0){
        return; //throw alloc error
    }
    
    tail->next = node;
    node->pre = tail;
    tail = node;
    listLength ++;
}


template<typename T> void List<T>::remove(size_t index){
    if(index>=listLength){
        return; //throe List Overflow
    }
    ListNode<T>* node = this[index];
    node->pre->next = node->next;
    if(node->next != 0){
        node->next->pre = node->pre;
    }

}


template<typename T> ListNode<T>* List<T>::operator [](size_t index)
{
    if(index>=listLength){
        return; //throe List Overflow
    }
    int cnt = index;
    ListNode<T>* node = root.next;
    while(cnt--){
        node = node->next;
    }
    return node;
}
#endif /* LIST_H */

