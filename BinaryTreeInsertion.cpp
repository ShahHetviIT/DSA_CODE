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
    BT()
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

    void insert_element(TreeNode *r,int ele)
    {
        char ch;
        TreeNode *nm = new TreeNode(ele);
        if(r == NULL)
        {
            root = r = nm;
            cout << ele << " is inserted." << endl << endl;
        }
        else
        {

            cout << "Where to insert " << ele << " left/right of " << r->value << " : ";
            cin >> ch;

            if(ch == 'r')
            {
                if(r->right == NULL)
                    r->right = nm;
                else
                    insert_element(r->right,ele);
            }
            else
            {
                if(r->left == NULL)
                    r->left = nm;
                else
                    insert_element(r->left,ele);
            }
            cout << ele << " is added " << ch << " of " << r->value << endl << endl;
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
    BT obj;

    obj.insert_element(obj.root,50);
    obj.insert_element(obj.root,25);
    obj.insert_element(obj.root,75);
    obj.insert_element(obj.root,100);
    obj.insert_element(obj.root,0);
    obj.insert_element(obj.root,35);
    obj.insert_element(obj.root,65);

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
