//Phoenix_RK


/*

https://www.hackerrank.com/challenges/tree-preorder-traversal/problem


Complete the  function in your editor below, which has  parameter: a pointer to the root of a binary tree. It must print the values in the tree's preorder traversal as a single line of space-separated values.

Input Format

Our hidden tester code passes the root node of a binary tree to your preOrder function.





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

/* you only have to complete the function given below.  
Node is defined as  

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

    //preOrder recursive
    void preOrder(Node *root) {
        if(root==NULL)
            return ;
      
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
        
    }



//preOrder iterative
 void preOrder(Node *root) {
        if(root==NULL)
            return ;
        stack<Node*> s;
        s.push(root);
        while(!s.empty())
        {
            Node *node=s.top();
            s.pop();
            if(!node)
                continue;
            cout<<node->data<<" ";
            s.push(node->right);
            s.push(node->left);
        }        
    }


}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.preOrder(root);
    return 0;
}

