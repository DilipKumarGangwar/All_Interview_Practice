//convert a binary tree to bst
/*
https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(Node* root, vector<int>& arr) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left, arr);
    arr.push_back(root->data);
    inOrderTraversal(root->right, arr);
}

void convertToBST(Node* root, vector<int>& arr, int& i) {
    if (root == nullptr)
        return;
    convertToBST(root->left, arr, i);
    root->data = arr[i++];
    convertToBST(root->right, arr, i);
}

class Solution {
public:
    Node* binaryTreeToBST(Node* root) {
        vector<int> arr;
        inOrderTraversal(root, arr);
        sort(arr.begin(), arr.end());
        int i = 0;
        convertToBST(root, arr, i);
        return root;
    }
};

// Utility function to print the in-order traversal of a tree
void printInOrder(Node* root) {
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    // Creating an instance of Solution class
    Solution solution;

    // Converting binary tree to BST
    Node* bstRoot = solution.binaryTreeToBST(root);

    // Printing the in-order traversal of the resulting BST
    cout << "In-order traversal of the resulting BST: ";
    printInOrder(bstRoot);
    cout << endl;

  
    
    return 0;
}
