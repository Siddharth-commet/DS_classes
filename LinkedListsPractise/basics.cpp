#include<iostream>
#include<list>
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

int main()
{
    // LinkedList MyList;
    // MyList.insertAtEndUsingTail(1);
    // MyList.insertAtEndUsingTail(2);
    // MyList.display();
    // MyList.insertAtEndUsingTail(400);
    // MyList.display();
    // // MyList.insertAtPos(4, 500);
    // MyList.display();
    // MyList.deleteAtPos(3);
    // MyList.display();
    // MyList.insertAtEndUsingTail(4);
    // MyList.insertAtEndUsingTail(5);
    // MyList.insertAtEndUsingTail(6);
    // MyList.insertAtEndUsingTail(7);
    // MyList.insertAtEndUsingTail(8);
    // MyList.insertAtEndUsingTail(9);
    // MyList.display();
    // MyList.deleteAltEle();
    // cout << "\n"<< MyList.length << "\n";
    // MyList.display();
    LinkedList l1;
    l1.insertAtEnd(2);
    l1.insertAtHead(1);
    l1.display();
    l1.insertAtPos(3,3);
    l1.display();
    return 0;

}
