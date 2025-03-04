#include "BinaryTree.h"


Node3* insertRoot(Node3* root, int value) {
    if (root == nullptr) {
        return new Node3(value);
    }
    if (value < root->data) {
        root->left = insertRoot(root->left, value);
    }else {
        root->right = insertRoot(root->right, value);
    }

    return root;
}



void inOrder(Node3 * root) {
    if (root == nullptr) return;
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}


void preOrder( Node3* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    inOrder(root->left);
    inOrder(root->right);
}



void postOrder(Node3* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    inOrder(root->right);
    std::cout << root->data << " ";
}


bool binarySearch(Node3* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) {
        return binarySearch(root->left, value);
    }else {
        return binarySearch(root->right, value);
    }
}


int maxRoot(Node3* root) {
    Node3 *temp = root;

    while (temp->right != nullptr) {
        temp = temp->right;
    }

    return temp->data;
}



int minRoot(Node3* root) {
    Node3 *temp = root;

    while (temp->left != nullptr) {
        temp = temp->left;
    }

    return temp->data;
}


Node3* deleteRoot(Node3* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data) {
        root->left = deleteRoot(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteRoot(root->right, value);
    }else {
        if (root->left == nullptr) {
            Node3* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node3* temp  = root->left;
            delete root;
            return temp;
        }


        Node3*temp = root->right;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }

        root->data = temp->data;

        root->right = deleteRoot(root->right, temp->data);
    }

    return root;
}


int countRoot(Node3 *root) {
    if (root == nullptr) return 0;

    return  countRoot(root->left) + countRoot(root->right) + 1 ;
}

int countLeaf(Node3* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;


    return countLeaf(root->left) + countLeaf(root->right);
}

int height(Node3*root) {
    if (root == nullptr) return 0;

    return 1 + std::max(height(root->left), height(root->right));
}


bool isBalanced(Node3* root) {
    if (root == nullptr) return true;
    int lh = height(root->left);
    int rh = height(root->right);

    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}
void storeSort(Node3 *root, int arr[], int &i) {
    if (root) {
        storeSort(root->left, arr, i);
        arr[i++] = root->data;
        storeSort(root->right, arr, i);
    }

}

void binaryTreeSort(int arr[], int n) {
    Node3* root = nullptr;

    for (int i = 0; i < n; i++) {
        root = insertRoot(root, arr[i]);
    }

    int i = 0;

    storeSort(root,arr, i);
}


