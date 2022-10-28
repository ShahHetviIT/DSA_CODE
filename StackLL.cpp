#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;

    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        if(top==NULL)
            return true;
        else
            return false;
    }

    void push(int ele)
    {
        Node *nm = new Node(ele);

        if(top == NULL)
            top = nm;
        else
        {
            Node *temp = top;
            nm->next = temp;
            top = nm;
        }
    }

    void pop()
    {
        Node *temp = top;

        if(isEmpty())
        {
            cout << "Stack underflow!!" << endl;
        }
        else
        {
            top = top->next;
        }
    }

    int Count()
    {
        int ctr = 0;
        Node *temp = top;

        while(temp!=NULL)
        {
            ctr++;
            temp = temp->next;
        }
        return ctr;
    }

    void display()
    {
        Node *temp = top;

        cout << "Values in Stack are : "  << endl;

        while(temp!=NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Stack S1;

    S1.pop();

    S1.push(100);
    S1.push(90);
    S1.push(80);
    S1.push(70);
    S1.push(60);

    S1.display();

    cout << "Total elements in Stack : " << S1.Count() << endl << endl;

    S1.pop();
    S1.pop();
    S1.display();

    cout << "Total elements in Stack : " << S1.Count() << endl << endl;

    return 0;
}
