#include<iostream>
using namespace std;

class poly
{
public:
    int c;
    int e;
    int add (poly p1[],poly p2[],poly p3[],int t1,int t2)
    {
        int i,j,k;
        i=j=k=0;
        int t3;
        while(i<t1 && j<t2)
        {
            if(p1[i].e == p2[j].e)
            {
                p3[k].c = p1[i].c + p2[j].c;
                p3[k].e = p1[i].e;
                i++;j++;k++;
            }
            if(p1[i].e>p2[j].e)
            {
                p3[k].c = p1[i].c;
                p3[k].e = p1[i].e;
                i++;k++;
            }
            else
            {
                p3[k].c = p2[j].c;
                p3[k].e = p2[j].e;
                j++;k++;
            }
        }
        while(i<t1)
        {
            p3[k].c = p1[i].c;
            p3[k].e = p1[i].e;
            i++;k++;
        }
        while(i<t2)
        {
            p3[k].c = p2[j].c;
            p3[k].e = p2[j].e;
            j++;k++;
        }
        t3=k;
        return t3;
    }
    void display(poly p3[], int t3)
    {
        for(int i=0;i<t3;i++)
        {
            if(i==(t3-1))
                cout << p3[i].c << "x^" << p3[i].e;
            else
                cout << p3[i].c << "x^" << p3[i].e << " + ";
        }
        cout << endl;
    }
};

int main()
{
    poly obj;
    poly A[10],B[10],C[10];
    int m,n;

    cout << "Enter the size of first polynomial :"<< endl;
    cin >> m;
    cout << "Enter the size of second polynomial :"<< endl;
    cin >> n;

    cout << "Enter cofficients and exponent of 1st polynomial : " << endl;

    for(int i=0;i<m;i++)
    {
        cin >> A[i].c;
        cin >> A[i].e;
    }

    cout << "Enter cofficients and exponent of 2nd polynomial : " << endl;

    for(int i=0;i<n;i++)
    {
        cin >> B[i].c;
        cin >> B[i].e;
    }

    cout << "P1 : ";
    obj.display(A,m);

    cout << "P2 : ";
    obj.display(B,n);
    int terms = obj.add(A,B,C,m,n);

    cout << "P3 : ";
    obj.display(C,terms);

    return 0;

}
