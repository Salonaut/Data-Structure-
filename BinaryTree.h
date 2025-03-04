
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>


struct Node3 {
    int data;
    Node3* left;
    Node3*right;


    Node3(int value) : data(value), left(nullptr), right(nullptr) {}
};


Node3* insertRoot(Node3* root, int value);

void preOrder( Node3* root);

void inOrder(Node3* root);

void postOrder(Node3* root);


bool binarySearch(Node3* root, int value);

Node3* deleteRoot(Node3* root, int value);


int countRoot(Node3 *root);


int maxRoot(Node3* root);


int minRoot(Node3* root);


int height(Node3*root);

int countLeaf(Node3* root);

bool isBalanced(Node3* root);

void storeSort(Node3 *root, int arr[], int &i);

void binaryTreeSort(int arr[], int n);

#endif //BINARYTREE_H
