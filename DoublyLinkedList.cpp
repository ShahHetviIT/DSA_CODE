#include<iostream>
using namespace std;

class impl;

class Node
{
    friend class impl;
    int data;
    Node *next;
    Node *pre;

public:
    Node(int ele)
    {
        data = ele;
        next = NULL;
        pre = NULL;
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

            while(temp->next!=NULL)
            {
                temp = temp->next;
            }

            nm->pre = temp;
            temp->next = nm;
        }
    }

    void insertAfter(int ele,int sele)
    {
        Node *nm = new Node(ele);
        Node *temp = first;

        while(temp->data!=sele)
        {
            temp = temp->next;
        }

        nm->next = temp->next;
        nm->pre = temp;
        temp->next->pre = nm;
        temp->next = nm;
    }

    void insertBefore(int ele,int sele)
    {
        Node *nm = new Node(ele);
        Node *temp = first;

        while(temp->data!=sele)
        {
            temp = temp->next;
        }

        nm->next = temp;
        nm->pre = temp->pre;
        temp->pre->next = nm;
        temp->pre = nm;
    }

    void deleteEle(int sele)
    {
        Node *temp = first;

        while(temp->data!=sele)
        {
            temp = temp->next;
        }

        if(temp==first)
        {
            first = temp->next;
        }
        else
        {
            temp->pre->next = temp->next;
            temp->next->pre = temp->next;
        }
    }

    void deleteAfter(int sele)
    {
        Node *temp = first;

        while(temp->data!=sele)
        {
            temp = temp->next;
        }
        
        temp->next->next->pre = temp;
        temp->next = temp->next->next;
    }

    void deleteBefore(int sele)
    {
        Node *temp = first;

        while(temp->data!=sele)
        {
            temp = temp->next;
        }

        temp->pre->pre->next = temp;
        temp->pre = temp->pre->pre;
    }

    void display()
    {
        Node *temp = first;

        cout << endl << "LINKED LIST : ";
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
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
