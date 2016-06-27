/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BTree.cpp
 * Author: miaoliang
 * 
 * Created on 2016年6月23日, 上午11:39
 */

#include "BTree.h"
#include "stdio.h"
BTreeNode::BTreeNode(int _key)
{
    parent = 0;
    keys[0] = _key;
    keyNumber = 1;
    for(int i=1;i<MAX_NODE;i++){
        keys[i] = 0;
    }
    childNumber = 0;
    for(int i=0;i<MAX_NODE+1;i++){
        childs[i] = 0;
    }
}

BTreeNode::~BTreeNode(){

}

/*************************
 * @param : add key
 * @return: is insert success
 *************************/
bool BTreeNode::insert(int key){
    if(keyNumber>MAX_NODE-1){
        return false;
    }
    int insertIndex = 0;
    for(int k=0;k<keyNumber;k++){
        if(key<keys[0]){
            insertIndex = 0;
            break;
        }
        if(key>keys[k] && key<keys[k+1]){
            insertIndex = k+1;
            break;
        }
        if(key>keys[keyNumber-1]){
            insertIndex = keyNumber;
            break;
        }
    }
    for(int i=keyNumber;i>insertIndex;i--){
        keys[i] = keys[i-1];
        childs[i+1] = childs[i];
    }
    keys[insertIndex] = key;
    keyNumber++;
    return true;
}

bool BTreeNode::remove(int index){
    if(index>=MAX_NODE){
        return false;
    }
    keys[index] = 0;
    for(int i=index;i<keyNumber-1;i++){
        keys[i] = keys[i+1];
    }
    keys[keyNumber-1] = 0;
    keyNumber--;
}

bool BTreeNode::insert(BTreeNode* node)
{
    if(childNumber>MAX_NODE+1){
        return false;
    }
    int insertIndex = 0;
    int key = node->maxKey();
    for(int k=0;k<keyNumber;k++){
        if(key<keys[0]){
            insertIndex = 0;
            break;
        }
        if(key>keys[k] && key<keys[k+1]){
            insertIndex = k+1;
            break;
        }
        if(key>keys[keyNumber-1]){
            insertIndex = keyNumber;
            break;
        }
    }

    childs[insertIndex] = node;
    childNumber++;
    return true;
}

 bool BTreeNode::removeChild(int index){
      if(index>=MAX_NODE+1){
        return false;
    }
    keys[index] = 0;
    for(int i=index;i<childNumber-1;i++){
        childs[i] = childs[i+1];
    }
    childs[childNumber-1] = 0;
    childNumber--;
 }

bool BTreeNode::isFull(){
     if(keyNumber>=MAX_NODE){
        return true;
    }
     return false;
}

NODELEVEL BTreeNode::getLevel(){
    if(keyNumber<SPLIT_INDEX){
        return NODE_POOR;
    }else if(keyNumber == SPLIT_INDEX){
        return NODE_MID;
    }
    return NODE_FULL;
}

int BTreeNode::minKey()
{
    return keys[0];
}

int BTreeNode::maxKey()
{
    return keys[keyNumber-1];
}

int  BTreeNode::operator [] (int index)
{
    if(index>=0 && index<keyNumber){
        return keys[index];
    }
    return ERROR_V;
}
BTreeNode* BTreeNode::getChild(int index)
{
    if(index>=0 && index<childNumber){
        return childs[index];
    }
    return 0;
}

int BTreeNode::inRange(int key){
    for(int k=0;k<keyNumber;k++){
        if(key<keys[0]){
            return 0;
        }
        if(key>keys[k] && key<keys[k+1]){
            return k+1;
        }
        if(key>keys[keyNumber-1]){
            return keyNumber;
        }
    }
    return keyNumber;
}

BTreeNode* BTreeNode::searchNode(int key){
    BTreeNode* node = this;
    BTreeNode* nodeT = 0;
    while(node != 0){
        if(node->childNumber == node->keyNumber+1){
            node = node->childs[inRange(key)];
            nodeT = node;
        }else{
            node = 0;
        }
    }
    return nodeT;
}

BTreeNode* BTreeNode::search(int key,int& index){
    BTreeNode* node = this;
    while(node != 0){
        for(int i=0;i<node->keyNumber;i++){
            if(node->keys[i] == key){
                index = i;
                return node;
            }
        }
        node = node->childs[inRange(key)];
    }
}

BTreeNode* BTreeNode::rightBrother(){
    BTreeNode* node = 0;
    int currentIndex = 0;
    for(int i=0;i<parent->childNumber;i++){
        if(parent->childs[i] == this){
            currentIndex = i;
            break;
        }
    }
    if(currentIndex < parent->childNumber-1){
        node = parent->childs[currentIndex+1];
    }
    return node;
}

BTree::BTree() {
    root = 0;
}

BTree::~BTree() {
}
BTreeNode* BTree::search(int key,int& index){
    BTreeNode* node = root->search(key,index);
    return node;
}

void BTree::insert(int key){
    if(root == 0){
        root = new BTreeNode(key);
        return;
    }
    if(key == 88)
    {
        int l = 0;
    }
    printf("%c",key);
    BTreeNode* node = root->searchNode(key);
    node->insert(key);
    if(node->isFull()){
        split(node);
    }
}

bool BTree::split(BTreeNode* node){
    BTreeNode* parent = node->parent;
    bool bNewParent = false;
    if(parent == 0){
        parent = new BTreeNode((*node)[SPLIT_INDEX]);
        root = parent;     
        node->parent = parent;
        bNewParent = true;
    }else{
        parent->insert((*node)[SPLIT_INDEX]);
    }
    
    BTreeNode* nodeN = new BTreeNode((*node)[SPLIT_INDEX+1]);
    nodeN->parent = parent;
    nodeN->parent->insert(nodeN);
    nodeN->insert((*node)[SPLIT_INDEX+2]);

    node->remove(SPLIT_INDEX);
    node->remove(SPLIT_INDEX);
    node->remove(SPLIT_INDEX);
    if(bNewParent == true){
        node->parent->insert(node);
    }
    while(parent != 0 && parent->isFull() == true){
        split(parent);
        parent = parent->parent;
        //移动第一个孙子的父亲变为第二个
        BTreeNode* firstChild = parent->childs[0];
        BTreeNode* secondChild = parent->childs[1];
        for(int i=firstChild->childNumber-1;i>=0;i--){
            if(firstChild->childs[i]->minKey()>parent->keys[0]){
                secondChild->insert(firstChild->childs[i]);
                firstChild->removeChild(i);
            }
        }
    }   
}

 void BTree::deleteItem(int key){
     int index = 0;
     BTreeNode* node = search(key,index);
     if(node == 0){
         return;
     }
     node->remove(index);
     if(node->getLevel() == NODE_POOR){
         
     }
 }
 
 bool BTree::merge(BTreeNode* node){
     
 }
 
 bool BTree::refactoring(BTreeNode* node){
     
     
 }
