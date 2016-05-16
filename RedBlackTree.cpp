/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RedBlackTree.cpp
 * Author: miaoliang
 * 
 * Created on May 16, 2016, 3:54 AM
 */

#include "RedBlackTree.h"

RedBlackTree::RedBlackTree() {
    root = 0;
    sentry = new RedBlackTreeNode(0,NODE_COLOR_BLACK);
}

RedBlackTree::~RedBlackTree() {
}

void RedBlackTree::insertNode(RedBlackTreeNode* node){
    RedBlackTreeNode* y = sentry;
    RedBlackTreeNode* x = root;
    while(x != 0){
        y = x;
        if(node->key <x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    node->parent = y;
    if(y = sentry){
        root = node;
    }else if(node->key < y->key){
        y->left = node;
    }else{
        y->right = node;
    }
    node->left = sentry;
    node->right = sentry;
    node->color = NODE_COLOR_RED;
}

void RedBlackTree::RedBlackTreeFixup(RedBlackTreeNode* node)
{
    while(node->parent->color == NODE_COLOR_RED){
     
    }
}
