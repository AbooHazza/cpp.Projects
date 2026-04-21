#include<iostream>
using namespace std;

class Node
{
      public:
      int data;
      Node*next;
      Node(int value)
    {
           data=value;
           next=nullptr;
    }
};
class linkedlist
{
      public:
      Node*head;
      linkedlist()
{head=nullptr;}
bool isEmpty()
{
    return (head==NULL);
}

bool isFound(int key)
{
    Node*temp=head;
while(temp != NULL)
{
    if(temp->data == key)
    return true ;
temp=temp->next;
}
return false;

}

//linkedlist doesn't become fully;

void insertFirst(int value)
{
         Node*newNode = new Node(value);
         newNode->next=head;
           head=newNode;
}

void Display()
{
Node*temp=head;
while(temp!=NULL)
{
         cout<<temp->data<<" "<<endl;
         temp=temp->next;    
}
}
int counter()
{
         int count=0;
         Node*temp=head;
    while(temp!=NULL)
    {
             count++;
             temp=temp->next;
    }
    return count;
}
void insertBefore()
{
  
    int value;
    int newValue;

cout<<"Enter the value you want to insert before :"<<endl;
cin>>value; cout<<" "<<endl;
cout<<"Enter the new Value :"<<endl;
cin>>newValue;

    if(isFound(value)) //check condtion
    {
Node*temp=head;
while(temp->next !=NULL && temp->next->data!=value)   // to be before the node we want to insert 
{
    temp=temp->next;
}
Node*newNode = new Node(newValue); //new node insert his value 
newNode->next = temp->next;  // newNode & temp points to the node we want to insert 
temp->next=newNode; 
    }
    else
    {
cout<<"The Item is Not there "<<endl;
    }
}

void append(int value)
{
    Node*newNode= new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
Node*temp=head;
while(temp->next!=NULL)
{
    temp=temp->next;
}
         
             temp->next=newNode;
                 newNode->next=NULL;
            
}

void Delete(int item)
{
    if(isEmpty())
    {
    cout<<"Empty"<<endl;
    return ;
    }

    if(head->data == item) //    <-- Special Case
{
Node*delptr=head;
head=head->next;
delete delptr;
}

else
{
Node* delptr = head;
Node*prev=NULL;
while(delptr != NULL && delptr->data != item )
{
    prev=delptr;
    delptr=delptr->next;
}
prev->next=delptr->next;
delete delptr;
}
}

};
int main()
{
    linkedlist m;

    cout << "How many elements to append? ";
    int n, value;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        m.append(value);
    }

    cout << "List:" << endl;
    m.Display();

    cout << "Insert Before operation:" << endl;
    m.insertBefore();

    cout << "Final List:" << endl;
    m.Display();

    cout << "Count = " << m.counter() << endl;

    return 0;
}
