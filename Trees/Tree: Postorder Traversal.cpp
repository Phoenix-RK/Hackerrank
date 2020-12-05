//Phoenix_RK


/*
https://www.hackerrank.com/challenges/tree-postorder-traversal/problem


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

//recursive
/*
    void postOrder(Node *root) {
        if(!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }
*/
//2 stack
/*
    void postOrder(Node *root)
    {
        if(!root)
            return;
            
        stack<Node *> s;
        s.push(root);
        stack<int> traversal;
       
        while(!s.empty())
        {          
            Node* curr=s.top();
            s.pop();
            traversal.push(curr->data);
            
            if(curr->left)
                s.push(curr->left);
            if(curr->right)
                s.push(curr->right);
            
        }
        while(!traversal.empty())
        {
            cout<<traversal.top()<<" ";
            traversal.pop();
            
        }
    }
    */
    //1 stack
 void postOrder(Node *root)
    {
        if(!root)
            return;
            
        stack<Node *> s;
      
       
        while(!s.empty() || root!=NULL)
        {          
           if(root!=NULL)//go until left child is present
           {
               s.push(root);
               root=root->left;
           }
           else
           {
               Node* curr=s.top()->right; //get the right child of the top node (which will be the center)
               
               if(curr==NULL) //if there is no right child
               {
                   curr=s.top();
                   s.pop();
                   cout<<curr->data<<" "; //visit the node
                   
                   while(!s.empty() && curr==s.top()->right) //check if this curr node(which has been visited earlier) is the right child of the top node ..if its the right child, then it means that we have already visited the left child of the top node and thus its time to visit the top node
                   {
                       curr=s.top();
                       s.pop();
                       cout<<curr->data<<" "; 
                   }
               }
               else //if there is right child, then we have to repeat all the procedure like visiting left n right child of it, hence make it as the curr node
               {
                   root=curr;
               }
           }
            
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
  
	myTree.postOrder(root);
    return 0;
}

