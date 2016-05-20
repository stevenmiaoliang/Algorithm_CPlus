/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.cpp
 * Author: miaoliang
 * 
 * Created on May 16, 2016, 2:45 AM
 */

#include "BinaryTree.h"

TreeNode::TreeNode()
{
    parent = 0;
    left = 0;
    right = 0;
    key = 0;
}

TreeNode::TreeNode(int _key){
    parent = 0;
    left = 0;
    right = 0;
    key = _key;
}
TreeNode::~TreeNode(){

}

BinaryTree::BinaryTree() {
    root = 0;
}

BinaryTree::~BinaryTree() {
}

void inorderWalk(TreeNode* node)
{
    if(node != 0){
        inorderWalk(node->right);
        int k = node->key;
        inorderWalk(node->right);
    }
}
void preorderWalk(TreeNode* node)
{
    if(node != 0){
        int k = node->key;
        preorderWalk(node->right);
        preorderWalk(node->right);
    }
}

void postorderWalk(TreeNode* node)
{
    if(node != 0){
        postorderWalk(node->right);
        postorderWalk(node->right);
        int k = node->key;
    }
}
void BinaryTree::insertNode(TreeNode* node)
{
    TreeNode* y = 0;
    TreeNode* x = root;
     while(x != 0){
        y = x;
        if(node->key <x->key){
            x = x->left;
        }else{
            x = x->right;
        }
     }
    node->parent = x;
    if(y == 0){
        root = node;
    }else if(node->key<y->key){
        y->left = node;
    }else{
        y->right = node;
    }
}

void BinaryTree::transplant(TreeNode* u,TreeNode* v)
{
    if(u->parent == 0){
        root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    if(v != 0){
        v->parent = u->parent;
    }
}

void BinaryTree::deleteNode(TreeNode* node)
{
    if(node->left == 0){
        transplant(node,node->right);
    }else if(node->right == 0){
        transplant(node,node->left);
    }else{
        TreeNode* y = minimum(node->right);
        if(y->parent != node){
            transplant(y,y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        transplant(node,y);
        y->left = node->left;
        y->left->parent = y;
    }
}
    
TreeNode* BinaryTree::search(TreeNode* startNode,int key)
{
    if(startNode == 0 || key == startNode->key){
        return startNode;
    }
    if(key<startNode->key){
        search(startNode->left,key);
    }else{
        search(startNode->left,key);
    }
}

 TreeNode* BinaryTree::searchIterative(TreeNode* startNode,int key)
 {
     while(startNode != 0 && key != startNode->key){
         if(key < startNode->key){
             startNode = startNode->left;
         }else{
             startNode = startNode->right;
         }
     }
     return startNode;
 }

TreeNode* BinaryTree::successor(TreeNode* node)
{
    if(node->right != 0){
        return minimum(node->right);
    }
    TreeNode* y = node->parent;
    while(y !=0 && node == y->right){
        node = y;
        y = y->parent;
    }
    return y;
}
TreeNode* BinaryTree::predecessor(TreeNode* node)
{
    if(node->left != 0){
        return minimum(node->left);
    }
    TreeNode* y = node->parent;
    while(y !=0 && node == y->left){
        node = y;
        y = y->parent;
    }
    return y;
}
TreeNode* BinaryTree::minimum(TreeNode* node)
{
    while(node != 0 && node->left != 0){
        node = node->left;
    }
    return node;
}
TreeNode* BinaryTree::maximum(TreeNode* node)
{
    while(node != 0 && node->right != 0){
        node = node->right;
    }
    return node;
}