/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vEBTree.h
 * Author: miaoliang
 *
 * Created on 2016年6月27日, 上午9:16
 */

#ifndef VEBTREE_H
#define VEBTREE_H

class vEBTreeNode{
public:
    vEBTreeNode();
    virtual ~vEBTreeNode();
public:
    int minimum();
    int maximum();
    int high(int x);
    int low(int x);
    int index(int x,int y);
public:
    int u;
    int min;
    int max;
    vEBTreeNode* summary;
    vEBTreeNode** cluster;
};

class vEBTree {
public:
    vEBTree();
    virtual ~vEBTree();
    
    void create(vEBTreeNode* node,int u);
    bool member(vEBTreeNode* node,int x);
    int  successor(vEBTreeNode* node,int x);
    int  presuccessor(vEBTreeNode* node,int x);
    void emptyInsert(vEBTreeNode* node,int x);
    void insert(vEBTreeNode* node,int key);
    void deleteNode(vEBTreeNode* node,int key);
    vEBTreeNode*   root;
    
};

#endif /* VEBTREE_H */

