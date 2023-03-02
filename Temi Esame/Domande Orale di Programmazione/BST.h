#ifndef ORALE_BST_H
#define ORALE_BST_H

#include<stdlib.h>
#include<stdio.h>

typedef struct node* link;

struct node{
    int data;
    link left;
    link right;
} typedef Tree;

struct node* newNode(int data);
void inOrder(link root);
int count(link root);
int height(link root);

#endif
