#include <bits/stdc++.h>
using namespace std;

class Node
 {
public:
    string val; 
    Node* next;  
    Node* prev; 
    Node(string value) 
    {
        val = value;
        next = nullptr;
        prev = nullptr;
    }
};


class DoublyLinkedList {
private:
    Node* head;  
    Node* tail;  
    Node* current;  

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void insert(string value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            current = head;  // Set current to the head initially
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;  // Update tail
        }
    }

    // Function to visit an address
    string visit(string value) {
        Node* temp = head;
        while (temp) {
            if (temp->val == value) {
                current = temp;  // Update current to the found node
                return current->val;  // Return the visited address
            }
            temp = temp->next;
        }
        return "Not Available";  // Address not found
    }

    // Function to move to the next address
    string next() {
        if (current && current->next) {
            current = current->next;
            return current->val;
        }
        return "Not Available";  // No next address
    }

    // Function to move to the previous address
    string prev() {
        if (current && current->prev) {
            current = current->prev;
            return current->val;
        }
        return "Not Available";  // No previous address
    }
};

int main() {
    DoublyLinkedList addresses;  // Create a doubly linked list for web addresses

    // Read input web addresses until "end"
    string address;
    while (cin >> address && address != "end") {
        addresses.insert(address);  // Insert each address into the list
    }

    int Q; // Number of queries
    cin >> Q;

    // Processing queries
    while (Q--) {
        string command;
        cin >> command;

        if (command == "visit") {
            string visitAddress;
            cin >> visitAddress;
            cout << addresses.visit(visitAddress) << endl;  // Output the result of visit
        } 
        else if (command == "next") {
            cout << addresses.next() << endl;  // Output the result of next
        } 
        else if (command == "prev") {
            cout << addresses.prev() << endl;  // Output the result of prev
        }
    }

    return 0;
}














// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     list<string> web_addresses;
//     for (string address; cin >> address && address != "end";)
//     {
//         web_addresses.push_back(address);
//     }
//     int Q;
//     cin >> Q;
//     auto current_address = web_addresses.begin();

//     while (Q--)
//     {
//         string command_query;
//         cin >> command_query;

//         if (command_query == "visit")
//         {
//             string visit_address;
//             cin >> visit_address;
//             auto it = find(web_addresses.begin(), web_addresses.end(), visit_address);
//             if (it != web_addresses.end())
//             {
//                 current_address = it;
//                 cout << *current_address << endl;
//             }
//             else
//             {
//                 cout << "Not Available" << endl;
//             }
//         }
//         else if (command_query == "next")
//         {
//             auto nextIt = current_address;
//             ++nextIt;

//             if (nextIt != web_addresses.end())
//             {
//                 current_address = nextIt;
//                 cout << *current_address << endl;
//             }
//             else
//             {
//                 cout << "Not Available" << endl;
//             }
//         }
//         else if (command_query == "prev")
//         {
//             if (current_address != web_addresses.begin())
//             {
//                 --current_address;
//                 cout << *current_address << endl;
//             }
//             else
//             {
//                 cout << "Not Available" << endl;
//             }
//         }
//     }

//     return 0;
// }
