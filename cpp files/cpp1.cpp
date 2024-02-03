#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void Insert(Node **head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = *head;
    *head = newNode;
}

void Insertat(Node *&head, int data, int pos)
{
    Node *temp = head;
    int cnt = 1;

    while (cnt < pos)
    {
        temp = temp->next;
        cnt++;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteNode(int position, Node *&head)
{
    Node *temp = head;
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        cout << "looks good " << endl;
    }
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
}