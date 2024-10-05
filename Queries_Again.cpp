#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_linked_list(Node *head, Node *tail)
{
    // l to r
    cout << "L -> ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // r to l
    cout << "R -> ";
    temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        Node *newNode = new Node(V);
        if (X == 0)
        {
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            print_linked_list(head, tail);
        }
        else
        {
            Node *temp = head;
            int index_address = 0;

            while (temp != NULL && index_address < X - 1)
            {
                temp = temp->next;
                index_address++;
            }

            if (temp == NULL)
            {
                cout << "Invalid" << endl;
            }
            else
            {
                newNode->next = temp->next;
                newNode->prev = temp;

                if (temp->next != NULL)
                {
                    temp->next->prev = newNode;
                }
                else
                {
                    tail = newNode;
                }

                temp->next = newNode;
                print_linked_list(head, tail);
            }
        }
    }

    return 0;
}
