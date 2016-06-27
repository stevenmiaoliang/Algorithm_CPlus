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
 * History: Add Insert Function
 */

#include "RedBlackTree.h"
#include <iostream> 
#include <stack>
#include <vector>
using namespace std;



RBTreeNode* RBTreeNode::grandparent(){
    return this->parent->parent;
}

RBTreeNode* RBTreeNode::uncle(){
    if(this->parent == grandparent()->left){
        return grandparent()->right;
    }else{
        return grandparent()->left;
    }
}

RBTreeNode* RBTreeNode::brother(){
    if(this == this->parent->left){
        return this->parent->right;
    }else{
        return this->parent->left;
    }
}

RBTree::RBTree() {
    sentry = new RBTreeNode(-1,NODE_COLOR_BLACK);
    root = sentry;
}

RBTree::~RBTree() {
}

RBTreeNode* RBTree::find(int key){
    RBTreeNode* node = root;
    while(node != sentry){
        if(node->key == key){
            break;
        }
        if(key < node->key){
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return node;
}

void RBTree::insert(int key){
    RBTreeNode* node = new RBTreeNode(key,NODE_COLOR_BLACK);
    RBTreeNode* y = sentry;
    RBTreeNode* x = root;
    while(x != sentry){
        y = x;
        if(node->key <x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    node->parent = y;
    if(y == sentry){
        root = node;
    }else if(node->key < y->key){
        y->left = node;
    }else{
        y->right = node;
    }
    node->left = sentry;
    node->right = sentry;
    node->color = NODE_COLOR_RED;
    insertFixup(node);
    showTree(root);
}

void RBTree::deleteNode(int key){
    RBTreeNode* node = find(key);
    if(node == sentry){
        return;
    }
}

void RBTree::insertFixup(RBTreeNode* node)
{
    //当前节点为红色
    while(node->parent->color == NODE_COLOR_RED){   
        //节点的父亲是祖父的左子
        if(getPos(node->parent) == NODE_POS_LEFT){
            //节点的右叔叔
            RBTreeNode* uncle = node->uncle();
            //如果节点的叔叔红色
            if(uncle->color == NODE_COLOR_RED){    
                //将节点的父亲和叔叔全部置黑
                node->parent->color = NODE_COLOR_BLACK;  
                uncle->color = NODE_COLOR_BLACK;
                //祖父置红色
                node->grandparent()->color = NODE_COLOR_RED;
                //将当前节点变为祖父，看是否满足规则
                node = node->grandparent();
            }else if(uncle->color == NODE_COLOR_BLACK){   
                if(getPos(node) == NODE_POS_RIGHT){ //节点是父亲的右子
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = NODE_COLOR_BLACK;
                node->grandparent()->color = NODE_COLOR_RED;
                rightRotate(node->grandparent());
            }
        }else{
            RBTreeNode* uncle = node->grandparent()->left;
            //如果节点的叔叔红色
            if(uncle->color == NODE_COLOR_RED){    
                //将节点的父亲和叔叔全部置黑
                node->parent->color = NODE_COLOR_BLACK;  
                uncle->color = NODE_COLOR_BLACK;
                //祖父置红色
                node->grandparent()->color = NODE_COLOR_RED;
                //将当前节点变为祖父，看是否满足规则
                node = node->grandparent();
            }else if(uncle->color == NODE_COLOR_BLACK){  
                if(getPos(node) == NODE_POS_LEFT){ //节点的父亲是祖父的右子
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = NODE_COLOR_BLACK;
                node->grandparent()->color = NODE_COLOR_RED;
                leftRotate(node->grandparent());
            } 
        }
    }
    root->color = NODE_COLOR_BLACK;
    
}

NODEPOS  RBTree::getPos(RBTreeNode* node){
    if(node->parent == sentry){
        return NODE_POS_ROOT;
    }else if(node->parent->left == node){
        return NODE_POS_LEFT;
    }else if(node->parent->right == node){
        return NODE_POS_RIGHT;
    }
}

void RBTree::leftRotate(RBTreeNode* node){
    if(node == sentry || node->right == sentry){
        return;
    }
    RBTreeNode* rightChild = node->right;
    rightChild->parent = node->parent;
    node->right = rightChild->left;
    if(rightChild->left != sentry){
        rightChild->left->parent = node;
    }
    
    if(node->parent == sentry){
        root = rightChild;
    }else if(node == node->parent->left){
        node->parent->left = rightChild;
    }else{
        node->parent->right = rightChild;
    }
    rightChild->left = node;
    node->parent = rightChild;
}

void RBTree::rightRotate(RBTreeNode* node){
    RBTreeNode* leftChild = node->left;
    node->left = leftChild->right;
    if(leftChild->right != sentry){
        leftChild->right->parent = node;
    }
    leftChild->parent = node->parent;
    if(node->parent == sentry){
        root = leftChild;
    }else if(node == node->parent->left){
        node->parent->left = leftChild;
    }else{
        node->parent->right = leftChild;
    }
    leftChild->right = node;
    node->parent = leftChild;
}

void RBTree::showTree(RBTreeNode* node){
    vector<RBTreeNode*> nodeVector;
    nodeVector.push_back(node);
    while(nodeVector.size() != 0){
        node = *nodeVector.begin();
        string msg = node->color == NODE_COLOR_RED?"RED":"Black";
        std::cout<<node->key<<" "<<msg <<std::endl;      
        nodeVector.erase(nodeVector.begin());
        if(node->left != sentry){
            nodeVector.push_back(node->left);
        }
        if(node->right != sentry){
            nodeVector.push_back(node->right);
        }
    }
}
