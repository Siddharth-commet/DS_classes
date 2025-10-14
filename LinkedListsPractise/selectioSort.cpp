#include<iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class LinkedList
{

public:
    Node *head;
    Node *tail;
    int length = 0;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr)
        {
            tail = newNode;
        }
        length++;
    }
    void insertAtEnd(int val)
    {
        Node *temp = head;
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        tail = newNode;
        length++;
    }
    void insertAtEndUsingTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void insertAtPos(int pos, int val)
    {
        if (pos = length + 1)
        {
            insertAtEnd(val);
            return;
        }

        Node *temp = head;
        Node *temp2;
        pos = pos - 1;
        Node *newNode = new Node(val);
        if (pos == 0)
        {
            this->insertAtHead(val);
        }
        else
        {
            int tempPos = 0;
            while (tempPos < pos - 1)
            {
                if (temp->next == nullptr)
                {
                    cout << "pos is greater than length\n";
                    return;
                }

                temp = temp->next;
                tempPos++;
            }
            temp2 = temp->next;
            temp->next = newNode;
            newNode->next = temp2;
        }
        length++;
    }

    void deleteAtPos(int pos)
    {
        Node *temp = head;
        Node *beforeTemp;
        int temPos = 0;
        while (temPos < pos - 1)
        {
            if (temp->next == NULL)
            {
                cout << "given position is greater than Lenght ";
            }
            beforeTemp = temp;
            temp = temp->next;
            temPos++;
        }
        beforeTemp->next = temp->next;
        tail = beforeTemp;
        delete temp;
        length--;
    }

    void deleteHead()
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    void deleteAtEnd()
    {
        Node *second_last = head;
        while (second_last->next->next != nullptr)
        {
            second_last = second_last->next;
        }
        Node *temp = tail;
        tail = second_last;
        delete temp;
        length--;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void deleteAltEle()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        Node *temp = head;

        while (temp != nullptr && temp->next != nullptr)
        {
            Node *tempDel = temp->next;
            temp->next = tempDel->next;
            delete tempDel;
            length--;

            temp = temp->next;
        }
    }
};

int main(){
    int arr[] = {12,10,48,56,20,60,75,2,60,48};
    LinkedList list1;
    int arrKaSize = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        list1.insertAtEnd(arr[i]);
    }
    list1.display();

    Node* min;
    for (Node* i = list1.head; i!= nullptr; i=i->next)
    {
        Node* min=i;
        for (Node* j = i; j!= nullptr; j=j->next)
        {
            if (j->val<min->val)
            {
                min=j;
            }
            
        }
        int temp = i->val;
        i->val = min->val;
        min->val = temp;
    }
    list1.display();
    return 0;
}