#include<iostream>
#define SPACE 10
#include<queue>
using namespace std;

class BST;
class TreeNode
{
    friend class BST;
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v)
    {
        value = v;
        right = NULL;
        left = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }

    bool isTreeEmpty()
    {
        if(root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insertNode(int ele)
    {
        TreeNode *nm = new TreeNode(ele);
        if(root == NULL)
        {
            root = nm;
        }
        else
        {
            TreeNode *temp = root;
            while(temp!=NULL)
            {
                if(nm->value == temp->value)
                {
                    return;
                }
                else if((nm->value < temp->value) && (temp->left==NULL))
                {
                    temp->left = nm;
                }
                else if(nm->value < temp->value)
                {
                    temp = temp->left;
                }
                else if((nm->value > temp->value) && (temp->right==NULL))
                {
                    temp->right = nm;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    void print2D(TreeNode *r,int space)
    {
        if(r == NULL)
        {
            return;
        }

        space = space + SPACE;
        print2D(r->right,space);
        cout << endl;

        for(int i=0;i<space;i++)
        {
            cout << " ";
        }
        cout << r->value << endl;
        print2D(r->left,space);
    }

    void printPreorder(TreeNode *r)
    {
        if(r == NULL)
            return;

        cout << r->value << " ";
        printPreorder(r->left);
        printPreorder(r->right);

    }

    void printInorder(TreeNode *r)
    {
        if(r == NULL)
            return;

        printInorder(r->left);
        cout << r->value << " ";
        printInorder(r->right);
    }

    void printPostorder(TreeNode *r)
    {
        if(r == NULL)
            return;

        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->value << " ";
    }

    void levelOrder(TreeNode *r)
    {
        if(r == NULL)
            return;

        queue <TreeNode *> Q;
        Q.push(r);

        while(!Q.empty())
        {
            TreeNode *current = Q.front();
            cout << current->value << " ";

            if(current->left!=NULL)
                Q.push(current->left);
            if(current->right!=NULL)
                Q.push(current->right);

            Q.pop();
        }
    }
};

int main()
{
    BST obj;

    obj.insertNode(50);
    obj.insertNode(25);
    obj.insertNode(75);
    obj.insertNode(100);
    obj.insertNode(0);
    obj.insertNode(35);
    obj.insertNode(65);

    obj.print2D(obj.root,2);

    cout << "\nPre-order : ";
    obj.printPreorder(obj.root);

    cout << "\n\nIn-order : ";
    obj.printInorder(obj.root);

    cout << "\n\nPre-order : ";
    obj.printPostorder(obj.root);

    cout << "\n\nLevel-order : ";
    obj.levelOrder(obj.root);
}
