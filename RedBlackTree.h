/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedBlackTree.h
 * Author: miaoliang
 *
 * Created on May 16, 2016, 3:54 AM
 */

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "BinaryTree.h"

typedef enum _NODECOLOR
{
    NODE_COLOR_BLACK = 0,
    NODE_COLOR_RED = 1,
}NODECOLOR;

typedef enum _NODEPOS{
    NODE_POS_ROOT,
    NODE_POS_LEFT,
    NODE_POS_RIGHT,
}NODEPOS;

class RBTreeNode
{
public:
    RBTreeNode(){
        color = NODE_COLOR_BLACK;
    }
    RBTreeNode(int _key){
        key = _key;
        color = NODE_COLOR_BLACK;
    }
    RBTreeNode(int _key,NODECOLOR _color){
        color = _color;
        key = _key;
    }
    virtual ~RBTreeNode(){};
    
    RBTreeNode* grandparent();
    RBTreeNode* uncle();
    RBTreeNode* brother();
   
public:
    RBTreeNode* parent;
    RBTreeNode* left;
    RBTreeNode* right;
    int key;
    NODECOLOR color;
};

class RBTree:BinaryTree {
public:
    RBTree();
    virtual ~RBTree();
    
    
    RBTreeNode* find(int key);
    void insert(int key);
    void deleteNode(int key);
     
private:
     //判定当前节点是其负父的左子还是右子
    NODEPOS  getPos(RBTreeNode* node);
    void insertFixup(RBTreeNode* node);
    
    
   
    void leftRotate(RBTreeNode* node);
    void rightRotate(RBTreeNode* node);
    void showTree(RBTreeNode* node);
private:
    RBTreeNode*  root;
    RBTreeNode*  sentry;
};

#endif /* REDBLACKTREE_H */

