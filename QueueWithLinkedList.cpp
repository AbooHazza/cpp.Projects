#include <iostream>
using namespace std;

class Node
{
    public:
    Node*next;
    int data;
    Node(int value)
    {
next = NULL;
data = value;
    }
};

class Queue
{
public : 
Node*front = NULL;
Node*rear = NULL;

Queue()
{
    front = rear = NULL;
}

bool isEmpty()
{
    return (front == NULL );
}


void Enqueue(int item)
{
     Node*newNode = new Node( item );
     
     if(isEmpty())
     {
        front = rear = newNode;
     }
     else
     {
     rear -> next = newNode;
     rear = newNode;
     }
}

int peek()
{
    if(isEmpty())
    {
        return -1;
    } 
   
    return front->data ;
}
void Dequeue()
{
if( front == NULL)
{
    cout << "The Queue is Empty " << endl;
}
else if (front == rear)
{
    delete front ; 
    front = rear = NULL;
}
else 
{

    Node*delptr = front ;
    front = front->next;
delete delptr;

}
}


void DeleteQueue()
{
   while(!isEmpty())
   {
    Dequeue();
   }
}

void Display()
{
    Node*temp = front ;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next ; 
    }
}
};

int main()
{
    Queue q;

    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);

    q.Display();

    cout << q.peek() << endl;

    q.Dequeue();
    q.Display();

    q.Dequeue();
    q.Dequeue();

    q.Display();

    q.Dequeue(); 

    return 0;
}
