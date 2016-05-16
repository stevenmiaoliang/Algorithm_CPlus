/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.h
 * Author: miaoliang
 *
 * Created on May 16, 2016, 2:45 AM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

class TreeNode{
public:
    TreeNode();
    TreeNode(int key);
    virtual ~TreeNode();
    
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    
    int key;
}; 

class BinaryTree {
public:
    BinaryTree();
    virtual ~BinaryTree();
    
    void inorderWalk(TreeNode* node);
    void preorderWalk(TreeNode* node);
    void postorderWalk(TreeNode* node);
    virtual void insertNode(TreeNode* node);
    virtual void deleteNode(TreeNode* node);
    
    virtual TreeNode* search(TreeNode* strartNode,int key);
    virtual TreeNode* searchIterative(TreeNode* strartNode,int key);
    virtual TreeNode* successor(TreeNode* node);
    virtual TreeNode* predecessor(TreeNode* node);
    virtual TreeNode* minimum(TreeNode* node);
    virtual TreeNode* maximum(TreeNode* node);
private:
    void transplant(TreeNode* u,TreeNode* v);
    TreeNode* root;
};

#endif /* BINARYTREE_H */

