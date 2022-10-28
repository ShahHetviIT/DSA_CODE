#include<iostream>
using namespace std;

class poly;

class Term
{
    friend class poly;
    int coeff;
    int exp;
    Term *link;

public:
    Term(int c,int e)
    {
        coeff = c;
        exp = e;
        link = NULL;
    }
};

class poly
{
    Term *first;

public:
    poly()
    {
        first = NULL;
    }

    void insert_term(int c,int e)
    {
        if(first == NULL)
        {
            first = new Term(c,e);
        }
        else
        {
            Term *nm = new Term(c,e);
            Term *temp = first;

            while(temp->link!=NULL)
            {
                temp = temp->link;
            }

            temp->link = nm;
        }
    }

    void display()
    {
        Term *temp = first;

        while(temp!=NULL)
        {
            cout << temp->coeff << "x^" << temp->exp;
            if(temp->link!=NULL)
            {
                cout << " + ";
            }
            temp = temp->link;
        }
        cout << endl;
    }
    Term *getfirst()
    {
        return first;
    }
    void Addition(Term *f,Term *s)
    {
        Term *temp1 = f;
        Term *temp2 = s;

        while(temp1!=NULL&&temp2!=NULL)
        {
            if(temp1->exp==temp2->exp)
            {
                this->insert_term((temp1->coeff+temp2->coeff),temp1->exp);
                temp1 = temp1->link;
                temp2 = temp2->link;
            }
            else if(temp1->exp>temp2->exp)
            {
                this->insert_term(temp1->coeff,temp1->exp);
                temp1 = temp1->link;
            }
            else
            {
                this->insert_term(temp2->coeff,temp2->exp);
                temp2 = temp2->link;
            }
        }

        while(temp1!=NULL)
        {
            this->insert_term(temp1->coeff,temp1->exp);
            temp1 = temp1->link;
        }
        while(temp2!=NULL)
        {
            this->insert_term(temp2->coeff,temp2->exp);
            temp2 = temp2->link;
        }
    }
};


int main()
{
    poly P1,P2,P3;

    P1.insert_term(3,3);
    P1.insert_term(2,2);
    P1.insert_term(1,1);
    P1.insert_term(8,0);

    cout << "P1 :  ";
    P1.display();

    P2.insert_term(8,6);
    P2.insert_term(5,3);
    P2.insert_term(2,2);

    cout << "P2 :  ";
    P2.display();

    P3.Addition(P1.getfirst(),P2.getfirst());
    cout << "P3 :  ";
    P3.display();

    return 0;

}

