#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data = 0) {
        this->data = data;
        left = right = NULL;
    }
};

class Tree {
public:
    int idx=-1;
    Node* root=NULL;

    Tree() {
        //Node* root = new Node();
    }

    Node* setroot(Node* node){
        root = node;
        return root;
    }
    Node* BuildTreePreOrder(vector<int> &preOrder){
        idx++;
        if (preOrder[idx]==-1)      
        {
            return NULL;
        };

        Node* node = new Node(preOrder[idx]);
        node->left = BuildTreePreOrder(preOrder);
        node->right = BuildTreePreOrder(preOrder);

        return setroot(node);
        
    }

    void PrintTreeInPreOrder(Node* root){
        if(root==nullptr){
            return;
        }
        cout<<root->data;
        PrintTreeInPreOrder(root->left);
        PrintTreeInPreOrder(root->right);
    }

    void levelOrderTraversal(Node* root){
        queue<Node*> q1;
        if(root==NULL)return;
        q1.push(root);
        while (q1.size()>0)
        {
            Node* currNode = q1.front();
            cout<<currNode->data;
            q1.pop();
            if (currNode->left!=NULL)
            {
                q1.push(currNode->left);
            }
            if(currNode->right!=NULL){
                q1.push(currNode->right);
            } 
        }
    }

    void levelOrderTraversalWithNewLine(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // marker for end of first level

    while (!q.empty()) {

        Node* currNode = q.front();
        q.pop();

        if (currNode == NULL) {
            cout << endl;  // end of a level

            // if queue still has nodes, push NULL for next level
            if (!q.empty())
                q.push(NULL);

            continue;  // go to next iteration
        }

        cout << currNode->data << " ";

        if (currNode->left != NULL)
            q.push(currNode->left);

        if (currNode->right != NULL)
            q.push(currNode->right);
    }
}

    void showTree(){
        cout<<root->data<<endl;
    }
};


int height() {
    return 0; // temporary
}

int main() {
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Tree t1;
    cout<<t1.BuildTreePreOrder(preOrder)->data<<endl;
    t1.showTree();
    t1.PrintTreeInPreOrder(t1.root);
    cout<<endl;
    t1.levelOrderTraversal(t1.root);
    t1.levelOrderTraversalWithNewLine(t1.root);
    return 0;
}
