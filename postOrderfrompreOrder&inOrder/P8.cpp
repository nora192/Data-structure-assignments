#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(char val)
    {
        data = val;
        left = right = NULL;
    }

};

Node *createTrea(string preorder,string inorder)  //A BFGC    //FB A GC
{                                                //0  12|34     01 2 34
    if (preorder == "" && inorder == "")       //      2:2       L i  R
    {                                              //  L:R       2    2
        return NULL;
    }

        Node *root = new Node(preorder[0]);               //first char in preorder is a root
        int ndx = inorder.find(preorder[0]);                //get index of the root in inorder string 2
        int strlength = inorder.length() - (ndx + 1);     //5-3=2 number of chars in the right of string
        root->left = createTrea(preorder.substr(1,ndx), inorder.substr(0,ndx));   //BF  FB
        root->right = createTrea(preorder.substr(ndx+1,strlength), inorder.substr(ndx+1,strlength));  //GC  GC

        return root;
}

void Postorder(Node* r) // left--> right->root
{
    if (r == NULL)
        return;
    Postorder(r->left);
    Postorder(r->right);
    cout << r->data ;
}


void printPostOrder (string preorder, string inorder)
{
    Node *result = createTrea(preorder, inorder);
    Postorder(result);
}


int main()
{
    //testCase_1
    printPostOrder ( "ABDEC", "DBEAC");
    cout << endl;
    //testCase_2
    printPostOrder ( "ABDECF", "DBEAFC");
    cout << endl;
    //testCase_3
    printPostOrder ( "ABDECFG", "DBEAFCG");
    cout << endl;
    //testCase_4
    printPostOrder ( "ABCGDEF", "GCBDAFE");
    cout << endl;
    //testCase_5
    printPostOrder ( "ABDHIECFJGKL", "HDIBEAFJCKGL");
}



