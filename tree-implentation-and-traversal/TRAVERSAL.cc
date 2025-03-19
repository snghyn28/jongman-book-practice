#include <iostream>

using namespace std;

int preOrder[100];
int inOrder[100];

struct TreeNode {
    int value;
    TreeNode *left, *right;
};

int findFromInOrder(int value, int from) {
    int index = from;
    while (inOrder[index] != value) index++;
    return index;
}

TreeNode* makeTree(int preFrom, int preTo, int inFrom, int inTo) {
    if (preFrom > preTo) return NULL;
    TreeNode* root = new TreeNode;
    root->value = preOrder[preFrom];
    int rootIndexAtInOrder = findFromInOrder(root->value, inFrom);
    int leftSize = rootIndexAtInOrder - inFrom;
    int rightSize = inTo - rootIndexAtInOrder;
    if (leftSize == 0) {
        root->left = NULL;
    } else {
        root->left = makeTree(preFrom + 1, preFrom + leftSize, inFrom, rootIndexAtInOrder - 1);
    }
    if (rightSize == 0) {
        root->right = NULL;
    } else {
        root->right = makeTree(preFrom + leftSize + 1, preTo, rootIndexAtInOrder + 1, inTo);
    }
    return root;
}

void printPostOrder(TreeNode* root) {
    if (root->left != NULL) printPostOrder(root->left);
    if (root->right != NULL) printPostOrder(root->right);
    cout << root->value << ' ';
    delete root;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> preOrder[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> inOrder[i];
        }
        TreeNode* root = makeTree(0, n - 1, 0, n - 1);
        printPostOrder(root);
        cout << endl;
    }
