#include <iostream>
using namespace std;

class Node
{
    public:
    Node*next;
    int data;
    Node(int value)
    {
          next=NULL;
          data=value;
    }
};
class Stack
{
    public :

    Node*top;
    Stack()
     {
        top = NULL;
     }

bool isEmpty()
{
    return (top == NULL);  //check condtion 
}

void push(int item)
{

    if(top == NULL)
    {
         Node*newNode = new Node(item);  // Creation 
             newNode->next = NULL;    
         top = newNode; 
    }
    else 
    {
         Node*newNode = new Node(item);                // you can put this line out side the if condtion 
             newNode->next = top;            //link the new node with the first node
         top = newNode;            // link the top with new node
          
    }
}
int pop()
{
    if(top == NULL)
    {
        cout << "Stack is Empty " << endl;
        return -1;
    }
    else
    {
    int item;
     Node*delptr = top; 
     item = top->data;
         top = top->next;
    delete delptr;
    return item ;
}
}

void peek()
{
    if (top == NULL)
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    cout << top->data << endl;
}

void display()
{
    Node*temp = top ; 
    while(temp != NULL)
    {
        cout << temp->data << " " << endl;
        temp = temp->next;

        cout <<" "<< endl;
    }
}


};


int main()
{
    Stack m;

    int n, value, delCount;

    cout << "Enter number of elements to push: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        m.push(value);
    }

    cout << "\nStack after push:\n";
    m.display();

    cout << "\nEnter number of pops: ";
    cin >> delCount;

    for (int i = 0; i < delCount; i++)
    {
        cout << "Popped: " << m.pop() << endl;
    }

    cout << "\nStack after pop:\n";
    m.display();

    return 0;
}