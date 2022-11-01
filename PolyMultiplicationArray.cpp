#include<iostream>
using namespace std;

class poly
{
public:
    int coeff;
    int expo;
    int mul(poly p1[],poly p2[],poly p3[],int n1,int n2)
    {
        int i,j,k,next3,flag;
        int ex,co;
        i = next3 = 0;

        while(i<n1)
        {
            j=0;
            while(j<n2)
            {
                ex = p1[i].expo+p2[j].expo;
                co = p1[i].coeff*p2[j].coeff;
                k = flag = 0;

                while(k<next3 && !flag)
                {
                    if(p3[k].expo==ex)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        k++;
                    }
                }

                if(flag==1)
                {
                    p3[k].coeff = p3[k].coeff+co;
                }
                else
                {
                    p3[next3].expo = ex;
                    p3[next3].coeff = co;
                    next3++;
                }
                j++;
            }
            i++;
        }
        return next3;
    }
    void display(poly p3[], int t3)
    {
        for(int i=0;i<t3;i++)
        {
            if(i==(t3-1))
                cout << p3[i].coeff << "x^" << p3[i].expo;
            else
                cout << p3[i].coeff << "x^" << p3[i].expo << " + ";
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
        cin >> A[i].coeff;
        cin >> A[i].expo;
    }

    cout << "Enter cofficients and exponent of 2nd polynomial : " << endl;

    for(int i=0;i<n;i++)
    {
        cin >> B[i].coeff;
        cin >> B[i].expo;
    }

    cout << "P1 : ";
    obj.display(A,m);

    cout << "P2 : ";
    obj.display(B,n);
    int terms = obj.mul(A,B,C,m,n);

    cout << "P3 : ";
    obj.display(C,terms);

    return 0;

}
