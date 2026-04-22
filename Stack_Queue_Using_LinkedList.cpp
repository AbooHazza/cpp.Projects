#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
public:
          Node* head;
          Node* tail;

      LinkedList()
     {
        head = tail = NULL;
     }

     ~LinkedList()
     {
        Node* current = head;

        while (current != NULL)
            {
                  Node* temp = current;
                  current = current->next;
                  delete temp;
            }

                  head = tail = NULL;
        }
};

class Stack // LIFO
{
public:
    LinkedList list;

    void push(int value)
    {
        Node* newNode = new Node(value);

        if (list.head == NULL)
        {
            list.head = newNode;
            list.tail = newNode;
        }
        else
        {
            newNode->next = list.head;
            list.head = newNode;
        }
    }

    void pop()
    {
        if (list.head == NULL)
        {
            cout << "Stack Is Empty ! " << endl;
        }
        else
        {
            Node* delptr = list.head;
            list.head = list.head->next;
            delete delptr;
        }
    }
};

class Queue // FIFO
{
public:
    LinkedList list;

    void Enqueue(int value)
    {
        Node* newNode = new Node(value);

        if (list.head == NULL)
        {
            list.head = newNode;
            list.tail = newNode;
        }
        else
        {
            list.tail->next = newNode;
            list.tail = newNode;
        }
    }

    void Dequeue()
    {
        if (list.head == NULL)
        {
            cout << "The Queue Is Empty " << endl;
        }
        else if (list.head == list.tail)
        {
            delete list.head;
            list.head = list.tail = NULL;
        }
        else
        {
            Node* delptr = list.head;
            cout << "The Dealted Value is : " << delptr->data << endl;
            list.head = list.head->next;
            delete delptr;
        }
    }
};

int main()
{
    Stack O1;
    Queue O2;

    O1.push(13);
    O1.push(42);
    O1.pop();

    O2.Enqueue(7);
    O2.Enqueue(9);
    O2.Dequeue();

    return 0;

}







