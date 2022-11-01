#include<iostream>
using namespace std;

class circularLinkedList;
class Node
{
    friend class circularLinkedList;
    int data;
    Node *link;

public:
    Node(int elem)
    {
        data = elem;
        link = NULL;
    }
};

class circularLinkedList
{
    Node *first;

public:
    circularLinkedList()
    {
        first = NULL;
    }

    void insertNode(int elem)
    {
        if(first == NULL)
        {
            first = new Node(elem);
        }
        else if(first->link==NULL)
        {
            Node *nm = new Node(elem);
            first->link = nm;
            nm->link = first;
        }
        else
        {
            Node *nm = new Node(elem);
            Node *temp = first;

            while(temp->link!=first)
            {
                temp = temp->link;
            }
            temp->link = nm;
            nm->link = first;
        }
    }

    void insertStart(int ele)
    {
        Node *nm = new Node(ele);
        Node *temp = first;

        while(temp->link!=first)
        {
            temp = temp->link;
        }

        temp->link = nm;
        nm->link = first;
        first = nm;
    }

    void insertAfter(int sele,int ele)
    {
        Node *nm = new Node(ele);
        Node *temp = first;

        while(temp->data!=sele)
        {
            temp = temp->link;
        }

        nm->link = temp->link;
        temp->link = nm;
    }

    void insertBefore(int sele,int ele)
    {
        Node *nm = new Node(ele);
        Node *temp = first;


            while(temp->link->data!=sele)
            {
                temp = temp->link;
            }
            nm->link = temp->link;
            temp->link = nm;

    }

    void display()
    {
        Node *temp = first;

        while(temp->link!=first)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << temp->data;

        cout << endl;
    }
};


int main()
{
    circularLinkedList C1;
    C1.insertNode(5);
    C1.insertNode(8);
    C1.display();
    C1.insertNode(14);
    C1.display();

    C1.insertStart(3);
    C1.display();

    C1.insertAfter(8,10);
    C1.display();

    C1.insertBefore(5,2);
    C1.display();

    C1.insertBefore(10,9);
    C1.display();

    C1.insertBefore(14,13);
    C1.display();

    return 0;
}
