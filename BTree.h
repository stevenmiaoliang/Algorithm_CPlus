/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BTree.h
 * Author: miaoliang
 *
 * Created on 2016年6月23日, 上午11:39
 */

#ifndef BTREE_H
#define BTREE_H

using namespace std;
#include <vector>
#define MAX_NODE     5
#define SPLIT_INDEX  MAX_NODE/2
#define ERROR_V    -10000000

typedef enum _NODELEVEL{
    NODE_FULL,
    NODE_MID,
    NODE_POOR,
}NODELEVEL;

class BTreeListNode{
public:
    BTreeListNode(int _key):key(_key){}
    BTreeListNode* preNode;
    BTreeListNode* nextNode;
    unsigned char key;
};
class BTreeNode{
public:
    BTreeNode(int key);
    virtual ~BTreeNode();
    bool insert(int key);
    bool remove(int index);
    bool insert(BTreeNode* node);
    bool removeChild(int index);
    bool isFull();
    NODELEVEL getLevel();
    int minKey();
    int maxKey();
    int operator [] (int index); 
    BTreeNode* getChild(int index);
    int inRange(int key);
    //查找Key所需要在的节点
    BTreeNode* searchNode(int key);
    //查找Key所在的节点
    BTreeNode* search(int key,int& index);
    BTreeNode* rightBrother();
public:
    BTreeNode*       parent;
    unsigned char keys[MAX_NODE];
    int keyNumber;
    BTreeNode* childs[MAX_NODE+1];
    int childNumber;
};

class BTree {
public:
    BTree();
    virtual ~BTree();
public:
    BTreeNode* search(int key,int& index);
    void insert(int key);
    void deleteItem(int key);
    bool split(BTreeNode* node);
    bool merge(BTreeNode* node);
    bool refactoring(BTreeNode* node);
private:
    BTreeNode*      root;
    
};

#endif /* BTREE_H */

