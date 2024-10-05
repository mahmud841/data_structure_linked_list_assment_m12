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

bool is_palindrome(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    // head & tail compare
    while (head != tail && head->prev != tail)
    {
        if (head->val != tail->val)
        {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    cin>>value;
    while (value != -1)
    {

        Node *newNode = new Node(value);
        cin >> value;
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Check pilindrome
    if (is_palindrome(head))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node *prev;
//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//         this->prev = NULL;
//     }
// };

// bool is_palindrome(Node *head)
// {
//     if (head == NULL)
//     {
//         return true;
//     }
//     Node *tail = head;
//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }
//     // head & tail compare
//     while (head != tail && head->prev != tail)
//     {
//         if (head->val != tail->val)
//         {
//             return false;
//         }
//         head = head->next;
//         tail = tail->prev;
//     }
//     return true;
// }

// int main()
// {
//     Node *head = NULL;
//     Node *tail = NULL;
//     int value;
//     while (cin>> value && value != -1)
//     {
//         Node *newNode = new Node(value);
//         if (head == NULL)
//         {
//             head = tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//     }

//     // Check pilindrome
//     if (is_palindrome(head))
//     {
//         cout << "YES" << endl;
//     }
//     else
//     {
//         cout << "NO" << endl;
//     }
//     return 0;
// }
