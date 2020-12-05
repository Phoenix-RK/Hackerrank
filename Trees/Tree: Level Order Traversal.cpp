//Phoenix_RK


/*
https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

Given a pointer to the root of a binary tree, you need to print the level order traversal of this tree. In level-order traversal, nodes are visited level by level from left to right. Complete the function  and print the values in a single line separated by a space.

For example:

     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  
For the above tree, the level order traversal is .

Input Format

You are given a function,

void levelOrder(Node * root) {

}
Constraints

 Nodes in the tree  

Output Format

Print the values in a single line separated by a space.

Sample Input

     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4  
Sample Output

1 2 5 3 6 4

Explanation

We need to print the nodes level by level. We process each level from left to right.
Level Order Traversal: .


*/


#include <bits/stdc++.h>	

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/
    int height(Node* root)
    {
        if(root==NULL)
            return 0;
        
        return 1+max(height(root->left),height(root->right));
    }

    void print(Node *root,int level)
    {
        if(root==NULL)
            return ;
        if(level==0)
        {
            cout<<root->data<<" ";
            return;
        }
        print(root->left,level-1);
        print(root->right,level-1);
    }
    void levelOrder(Node * root) {

        if(root==NULL)
            return ;
            
        int h=height(root);
        
        for(int i=0;i<h;i++)
        {
            print(root,i);
        }

    }

}; //End of Solution

