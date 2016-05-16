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

class RedBlackTreeNode:public TreeNode
{
public:
    RedBlackTreeNode():TreeNode(){
        color = NODE_COLOR_BLACK;
    }
    RedBlackTreeNode(int key):TreeNode(key){
        color = NODE_COLOR_BLACK;
    }
    RedBlackTreeNode(int key,NODE_COLOR_BLACK color):TreeNode(key){
        color = NODE_COLOR_BLACK;
    }
    RedBlackTreeNode* parent;
    RedBlackTreeNode* left;
    RedBlackTreeNode* right;
    NODE_COLOR_BLACK color;
};

class RedBlackTree:BinaryTree {
public:
    RedBlackTree();
    virtual ~RedBlackTree();
    
    void insertNode(RedBlackTreeNode* node);
    void deleteNode(RedBlackTreeNode* node);
    
private:
    void RedBlackTreeFixup(RedBlackTreeNode* node);
    
private:
    RedBlackTreeNode*  root;
    RedBlackTreeNode*  sentry;
};

#endif /* REDBLACKTREE_H */

