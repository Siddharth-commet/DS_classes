// Develop a menu driven program for the following operations of on a Singly Linked
// List.
// (a) Insertion at the beginning.
// (b) Insertion at the end.
// (c) Insertion in between (before or after a node having a specific value, say 'Insert a
// new Node 35 before/after the Node 30').
// (d) Deletion from the beginning.
// (e) Deletion from the end.
// (f) Deletion of a specific node, say 'Delete Node 60').
// (g) Search for a node and display its position from head.
// (h) Display all the node values.


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int target, int val) {
        if (!head) return;
        if (head->data == target) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Node " << target << " not found!\n";
        }
    }

    void insertAfter(int target, int val) {
        Node* temp = head;
        while (temp && temp->data != target) {
            temp = temp->next;
        }
        if (temp) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Node " << target << " not found!\n";
        }
    }

    void deleteFromBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    void deleteNode(int target) {
        if (!head) return;
        if (head->data == target) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        } else {
            cout << "Node " << target << " not found!\n";
        }
    }

    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found!\n";
    }

    void display() {
        Node* temp = head;
        if (!temp) {
            cout << "List is empty!\n";
            return;
        }
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, target;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Insert value: ";
            cin >> val;
            cout << "Before which node? ";
            cin >> target;
            list.insertBefore(target, val);
            break;
        case 4:
            cout << "Insert value: ";
            cin >> val;
            cout << "After which node? ";
            cin >> target;
            list.insertAfter(target, val);
            break;
        case 5:
            list.deleteFromBeginning();
            break;
        case 6:
            list.deleteFromEnd();
            break;
        case 7:
            cout << "Delete which value? ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 8:
            cout << "Search value: ";
            cin >> val;
            list.searchNode(val);
            break;
        case 9:
            list.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
