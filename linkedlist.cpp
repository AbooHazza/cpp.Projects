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
    next = nullptr;
}

};

class linkedList
{
    public:
Node* head;

linkedList()
{
    head=NULL;
}
bool isEmpty()
{
return (head == NULL); //  <--- if (head == NULL) RETURN TRUE OR FALSE ;
}
void insertFirst(int value)
{
Node*MoyNode = new Node(value); // New Node  & fill the data 
MoyNode->next=head;            //             [MoyNode] -> [The First Node || Null] 
head = MoyNode;               // head -> [MoyNode]
}
void Display() 
{
Node*temp=head;
while(temp!=NULL)
{
    cout<<temp->data<<endl;
    temp=temp->next;
}

}
int counter()  // return how many nodes are there 
{
    int counter=0;
Node*temp=head;
while(temp!=NULL)
{
        counter++;
    temp=temp->next;

}
return counter;
}

};
int main()
{
linkedList m;
cout<<m.isEmpty()<<endl; // return false (0) or true(1)
cout<<"<><><><><><><><>"<<endl;
m.insertFirst(5);
m.insertFirst(4);
cout<<m.isEmpty()<<endl; // return false (0) or true(1)
cout<<"<><><><><><><><>"<<endl;
m.Display();
cout<<m.counter()<<endl;
cout<<" "<<endl;

}
