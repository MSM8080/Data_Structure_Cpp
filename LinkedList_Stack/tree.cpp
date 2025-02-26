#include <iostream>
using namespace std;
//#define testcase0
//#define testcase1
// A binary tree node has data,
// left child and right child
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

//return the summation  of tree.
 int sum (node* node)
 {





 }
// Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(node* node)
{

}



// Helper function that allocates a new node
// with the given data and NULL left and right
// pointers.
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(
        sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Driver code
int main()
{
    #ifdef testcase0
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);

    cout<<"testcase 0"<<endl<<endl;
     cout<< "you expected output  : 52"<<endl;
     cout<< "your output : "<<sum(root)<<endl;

    struct node *root1 = newNode(26);
    root1->left = newNode(10);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(6);

    cout<< "you expected output  : 49"<<endl;
     cout<< "your output : "<<sum(root1)<<endl;

    struct node *root2 = newNode(26);


    cout<< "you expected output  : 26"<<endl;
     cout<< "your output : "<<sum(root2)<<endl;

    cout<< "you expected output  : 0"<<endl;
     cout<< "your output : "<<sum(NULL)<<endl;



    #endif // testcase0

    #ifndef testcase0
     #ifdef testcase1
    struct node *root = newNode(26);
    root->left = newNode(10);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->right->right = newNode(3);


    cout<<"testcase 1"<<endl<<endl;
     cout<< "you expected output  :The given tree is a SumTree "<<endl;
     cout<< "your output : ";
    if (isSumTree(root))
        cout << "The given tree is a SumTree " <<endl;
    else
        cout << "The given tree is not a SumTree "<<endl;
    cout<<endl;

    struct node *root1 = newNode(26);
    root1->left = newNode(10);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(3);
    root1->right->right = newNode(6);

    cout<< "you expected output  :The given tree is not a SumTree "<<endl;
    cout<< "your output : ";
    if (isSumTree(root1))
        cout << "The given tree is a SumTree "<<endl;
    else
        cout << "The given tree is not a SumTree "<<endl;
    #endif // testcase1
    #endif // testcase0
}
