#include<iostream>
using namespace std;

class impl;

class Node
{
    friend class impl;
    int data;
    Node *link;

public:
    Node(int ele)
    {
        data = ele;
        link = NULL;
    }
};

class impl
{
    Node *first;

public:
    impl()
    {
        first = NULL;
    }

    void insertEnd(int ele)
    {
        if(first == NULL)
        {
            first = new Node(ele);
        }
        else
        {
            Node *nm = new Node(ele);
            Node *temp = first;

            while(temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = nm;
        }
    }

    void insertAfter(int ele,int sele)
    {
        Node *nm = new Node(ele);
        Node *temp = first;

        while(temp->data != sele)
        {
            temp = temp->link;
        }

        nm->link = temp->link;
        temp->link = nm;
    }

    void insertBefore(int ele,int sele)
    {
        Node *nm = new Node(ele);
        Node *temp = first;
        Node *Temp1 = first;

        while(temp->data != sele)
        {
            Temp1 = temp;
            temp = temp->link;
        }

        nm->link = Temp1->link;
        Temp1->link = nm;
    }

    void deleteEle(int sele)
    {
        Node *temp = first;

        while(temp->link->data!=sele)
        {
            temp = temp->link;
        }

        temp->link = temp->link->link;
    }

    void deleteAfter(int sele)
    {
        Node *temp = first;

        while(temp->data!=sele)
        {
            temp = temp->link;
        }

        temp->link = temp->link->link;
    }

    void deleteBefore(int sele)
    {
        Node *temp = first;

        if(temp->link->data==sele)
        {
            first = temp->link;
        }
        else
        {
            while(temp->link->link->data!=sele)
            {
                temp = temp->link;
            }
            temp->link = temp->link->link;
        }
    }

    void display()
    {
        Node *temp = first;

        cout << endl << "LINKED LIST : ";
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl << endl;
    }
};

int main()
{
    impl I;
    I.insertEnd(10);
    I.insertEnd(20);
    I.insertEnd(30);
    I.insertEnd(40);
    I.insertEnd(50);

    I.display(); // 10 20 30 40 50

    I.insertAfter(15,10);
    I.insertAfter(35,30);

    I.display(); // 10 15 20 30 35 40 50

    I.insertBefore(12,15);
    I.insertBefore(25,30);

    I.display(); // 10 12 15 20 25 30 35 40 50

    I.deleteEle(12);

    I.display(); // 10 15 20 25 30 35 40 50

    I.deleteAfter(10);

    I.display();  // 10 20 25 30 35 40 50

    I.deleteBefore(30);
    I.deleteBefore(40);

    I.display();  //10 20 30 40 50

    return 0;
}
