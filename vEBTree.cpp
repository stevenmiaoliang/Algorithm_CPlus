/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vEBTree.cpp
 * Author: miaoliang
 * 
 * Created on 2016年6月27日, 上午9:16
 * 前驱存在问题
 */

#include "vEBTree.h"
#include <math.h>
using namespace std;
vEBTreeNode::vEBTreeNode()
{
    u = 0;
    min = max = -1;
    summary = 0;
    cluster = 0;
}
vEBTreeNode::~vEBTreeNode(){
    
}
int vEBTreeNode::minimum(){
    return min;
}
int vEBTreeNode::maximum(){
    return max;
}
int vEBTreeNode::high(int x){
    return (int)floor(x/sqrt((double)u));
}
int vEBTreeNode::low(int x){
    return x%(int)sqrt((double)u);
}
int vEBTreeNode::index(int x,int y){
    return x*(int)sqrt((double)u)+y;
}

vEBTree::vEBTree() {
    root = new vEBTreeNode();
}

vEBTree::~vEBTree() {
}

void vEBTree::create(vEBTreeNode* node,int u){
    node->u = u;
    node->min = node->max = -1;
    if(u == 2){
        node->cluster = 0;
        node->summary = 0;
    }else{
        int v = (int)sqrt((double)u);
        node->summary = new vEBTreeNode();
        create(node->summary,v);
        node->cluster = new vEBTreeNode*[v];
        for(int i=0;i<v;i++){
            node->cluster[i] = new vEBTreeNode();
            create(node->cluster[i],v);
        }
    }
}
bool vEBTree::member(vEBTreeNode* node,int x){
    if(node->min == x || x == node->max){
        return true;
    }else if(node->u == 2){
        return false;
    }else{
        return member(node->cluster[node->high(x)],node->low(x));
    }
}
int vEBTree::successor(vEBTreeNode* node,int x){
    if(node->u == 2){
        if(x== 0 || node->max == 1){
            return 1;
        }else{
            return -1;
        }
    }else if(node->min != -1 && x<node->min){
        return node->min;
    }else{
        int maxLow = node->cluster[node->high(x)]->max;
        if(maxLow != -1 && node->low(x)<maxLow){
            int high = node->high(x);
            int low = node->low(x);
            int offset = successor(node->cluster[high],low);
            return node->index(high,offset);
        }else{
            int succCluster = successor(node->summary,node->high(x));
            if(succCluster == -1){
                return -1;
            }else{
                int offset = node->cluster[succCluster]->min;
                return node->index(succCluster,offset);
            }
        }
    }
}

int  vEBTree::presuccessor(vEBTreeNode* node,int x){
    if(node->u == 2){
        if(x== 0 || node->min == 0){
            return 0;
        }else{
            return -1;
        }
    }else if(node->max != -1 && x> node->max){
        return node->max;
    }else{
        vEBTreeNode* nodeT = node->cluster[node->high(x)];
        int minLow = node->cluster[node->high(x)]->min;
        if(minLow != -1 && node->low(x)>minLow){
            int offset = presuccessor(node->cluster[node->high(x)],node->low(x));
            return node->index(node->high(x),offset);
        }else{
            int presuccCluster = presuccessor(node->summary,node->high(x));
            if(presuccCluster == -1){
                if(node->min!=-1 &&x >node->min){
                    return node->min;
                }else{
                    return -1;
                }
            }else{
                int offset = node->cluster[presuccCluster]->max;
                return node->index(presuccCluster,offset);
            }
        }
    }
}

void vEBTree::emptyInsert(vEBTreeNode* node,int x)
{
    node->min=node->max=x;
}

void vEBTree::insert(vEBTreeNode* node,int x){
    if(node->min == -1){
        emptyInsert(node,x);
    }else{
        if(x<node->min){
            int temp = x;
            x = node->min;
            node->min = temp;
        }
        if(node->u > 2){
            if(node->cluster[node->high(x)]->min == -1){
                insert(node->summary,node->high(x));
                emptyInsert(node->cluster[node->high(x)],node->low(x));
            }else{
                insert(node->cluster[node->high(x)],node->low(x));
            }
        }
        if(x>node->max){
            node->max = x;
        }
    }
}
void vEBTree::deleteNode(vEBTreeNode* node,int x){
    if(node->min == node->max){
        node->min = node->max = -1;
    }else if(node->u == 2){
        if(x == 0){
            node->min = 1;
        }else{
            node->min = 0;
        }
        node->max = node->min;
    }else if(x == node->min){
        int firstCluster = node->summary->min;
        x = node->index(firstCluster,node->cluster[firstCluster]->min);
        node->min = x;
        deleteNode(node->cluster[node->high(x)],node->low(x));
        if(node->cluster[node->high(x)]->min == -1){
            deleteNode(node->summary,node->high(x));
            if(x == node->max){
                int summaryMax = node->summary->max;
                if(summaryMax == -1){
                    node->max = node->min;
                }else{
                    node->min = node->index(summaryMax,node->cluster[summaryMax]->max);
                }
            }
        }else if(x == node->max){
           node->max = node->index(node->high(x),node->cluster[node->high(x)]->max); 
        }
    }
}

