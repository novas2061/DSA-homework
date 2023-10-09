#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :data(0), left(nullptr), right(nullptr) {}
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
    TreeNode(int value, TreeNode* left, TreeNode* right) : data(value), left(left), right(right) {}
};

TreeNode* buildTree(int noOfNodes, vector<pair<int, int>> edges) {
    unordered_map<int, TreeNode*> tree;
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if(tree.find(u) == tree.end()) {
            tree[u] = new TreeNode(u);
        } 
        if(tree.find(v) == tree.end()) {
            tree[v] = new TreeNode(v);
        }
        if(tree[u]->left == nullptr) {
            tree[u]->left = tree[v];
        } else {
            tree[u]->right = tree[v];
        }
    }
    return tree[1];
}

int heightOfTree(TreeNode* root) {
    if(!root) {
        return -1;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void printPreOrder(TreeNode* root) {
    if(!root) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(TreeNode* root) {
    if(!root) {
        return;
    } 
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

void printInOrder(TreeNode* root) {
    if(!root) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

bool isBinaryTree(TreeNode* root) {
    if(!root) {
        return true;
    }
    if(root->left && root->right) {
        return isBinaryTree(root->left) && isBinaryTree(root->right);
    } else if(root->left) {
        return isBinaryTree(root->left);
    } else if(root->right) {
        return isBinaryTree(root->right);
    }
    return true;
}

int main() {
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    vector<pair<int, int>> edges(noOfEdges);

    for (auto& edge : edges) {
        cin >> edge.first >> edge.second;
    }

    TreeNode* root = buildTree(noOfNodes, edges);

    cout << heightOfTree(root);
    cout << endl;
    printPreOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    if(isBinaryTree(root)) {
        printInOrder(root);
    } else {
        cout << "NOT BINARY TREE";
    }
    return 0;
}
