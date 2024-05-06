#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "enter the data:" << endl;

    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data to be filled in left" << endl;
    root->left = buildTree(root->left);
    cout << "enter the data to be filled in right" << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void preOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void buildTreefromLevelOrder(node *&root)
{
    queue<node *> q;
    int data;
    cin >> data;

    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "enter the left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "enter the right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{
    node *root = NULL;
    // creating the tree
    root = buildTree(root);

    cout << "Levelorder Traversal of tree is:" << endl;
    LevelOrderTraversal(root);

    cout << endl;
    cout << "Inorder Traversal of tree is:" << endl;
    Inorder(root);
    cout << endl;

    cout << "PreOrder Traversal of tree is:" << endl;
    preOrder(root);
    cout << endl;

    cout << "Postorder Traversal of tree is:" << endl;
    postOrder(root);
    cout << endl;

    return 0;
}
