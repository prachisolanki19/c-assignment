#include <iostream>
#include <stack>
using namespace std;

// Structure for a BST node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a value into BST
Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    Node* current = root;

    while (true)
    {
        if (value < current->data)
        {
            if (current->left == NULL)
            {
                current->left = createNode(value);
                break;
            }
            else
            {
                current = current->left;
            }
        }
        else if (value > current->data)
        {
            if (current->right == NULL)
            {
                current->right = createNode(value);
                break;
            }
            else
            {
                current = current->right;
            }
        }
        else
        {
            // Duplicate value
            break;
        }
    }

    return root;
}

// Non-recursive Inorder Traversal
void inorder(Node* root)
{
    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty())
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->data << " ";

        current = current->right;
    }
}

// Non-recursive Preorder Traversal
void preorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node*> s;
    s.push(root);

    while (!s.empty())
    {
        Node* current = s.top();
        s.pop();

        cout << current->data << " ";

        // Push right first
        if (current->right != NULL)
        {
            s.push(current->right);
        }

        // Push left second
        if (current->left != NULL)
        {
            s.push(current->left);
        }
    }
}

// Main function
int main()
{
    Node* root = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << endl;

    return 0;
}
