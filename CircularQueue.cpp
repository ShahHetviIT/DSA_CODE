#include<iostream>
using namespace std;

class Queue
{
    int Front;
    int rear;
    int arr[5];
    int itemctr=0;

public:
    Queue()
    {
        Front = rear = -1;

        for(int i=0;i<5;i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(rear == -1 && Front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if((rear+1)%5==Front)
            return true;
        else
            return false;
    }

    void enqueue(int val)
    {
        if(isFull())
            cout << "Queue is Full!!" << endl;
        else if(isEmpty())
        {
            Front = rear = 0;
            arr[rear] = val;
            itemctr++;
        }
        else
        {
            rear = (rear+1)%5;
            arr[rear] = val;
            itemctr++;
        }
    }

    void dequeue()
    {
        if(isEmpty())
            cout << "Queue is Empty!!" << endl;
        else if(Front == rear)
        {
            cout << arr[Front] << " is dequeued." << endl;
            arr[Front] = 0;
            Front = rear = -1;
            itemctr--;
        }
        else
        {
            cout << arr[Front] << " is dequeued." << endl;
            arr[Front] = 0;
            Front = (Front+1)%5;
            itemctr--;
        }
    }

    int Count()
    {
        return itemctr;
    }

    void display()
    {
        cout << endl << "All values in the Queue are : " << endl;
        for(int i=0;i<5;i++)
        {
            cout << arr[i] << " ";
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

    Q1.enqueue(60);

    cout << "Total values : " << Q1.Count() << endl;

    Q1.dequeue();
    Q1.dequeue();

    Q1.display();

    cout << "Total values : " << Q1.Count() << endl;

    Q1.enqueue(60);
    Q1.enqueue(70);
    Q1.dequeue();

    Q1.display();

    cout << "Total values : " << Q1.Count() << endl;

    return 0;

}
