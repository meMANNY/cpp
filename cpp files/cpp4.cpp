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

int main()
{
    node *root = NULL;
    // creating the tree
    root = buildTree(root);

    return 0;
}
