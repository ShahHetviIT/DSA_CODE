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

class Queue
{
public:
    Node *rear;
    Node *Front;

    Queue()
    {
        rear = NULL;
        Front = NULL;
    }

    bool isEmpty()
    {
        if(Front == NULL && rear == NULL)
            return true;
        else
            return false;
    }

    void enqueue(int ele)
    {
        Node *nm = new Node(ele);

        if(isEmpty())
        {
            Front = nm;
            rear = nm;
        }
        else
        {
            rear->next = nm;
            rear = nm;
        }
    }

    void dequeue()
    {
        if(isEmpty())
            cout << "Stack underflow!!" << endl;
        else
        {
            if(Front == rear)
            {
                Front = NULL;
                rear = NULL;
            }
            else
            {
                Front = Front->next;
            }
        }
    }

    int Count()
    {
        Node *temp = Front;
        int ctr = 0;

        while(temp != NULL)
        {
            ctr++;
            temp = temp->next;
        }

        return ctr;
    }

    void display()
    {
        Node *temp = Front;

        cout << "All values in queue are : " << endl;

        while(temp !=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << endl;
    }
};

int main()
{
    Queue Q1;

    Q1.dequeue();

    Q1.enqueue(10);
    Q1.enqueue(20);
    Q1.enqueue(30);
    Q1.enqueue(40);
    Q1.enqueue(50);
    Q1.display();

    cout << "Total elements in Queue : " << Q1.Count() << endl << endl;

    Q1.dequeue();
    Q1.dequeue();
    Q1.display();

    cout << "Total elements in Queue : " << Q1.Count() << endl << endl;

    return 0;
}
