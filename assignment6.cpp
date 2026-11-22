#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != NULL)
            q.push(current->left);

        if (current->right != NULL)
            q.push(current->right);
    }
}

Node* copyTree(Node* root) {
    if (root == NULL)
        return NULL;

    Node* newNode = new Node(root->data);

    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

void printLeafNodes(Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    Node* root = NULL;
    Node* newRoot = NULL;

    int n, value;

    cout << "Enter number of employees: ";
    cin >> n;

    cout << "Enter employee IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    
    cout << "\nOriginal BST (Level Order): ";
    levelOrder(root);

    newRoot = copyTree(root);

    cout << "\nCopied BST (Level Order): ";
    levelOrder(newRoot);

    cout << "\nHeight of BST: " << height(root);

    cout << "\nLeaf Nodes: ";
    printLeafNodes(root);

    cout << endl;

    return 0;
}
