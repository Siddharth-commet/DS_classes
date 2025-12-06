#include<iostream>
#include<vector>
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

Node* insert(Node* root, int val){
    if (root == NULL){
        return new Node(val);
    }
    if (val<root->data)
    {
        root->left=insert(root->left,val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;   
}
void PrintTreeInPreOrder(Node* root){
        if(root==nullptr){
            return;
        }
        cout<<root->data;
        PrintTreeInPreOrder(root->left);
        PrintTreeInPreOrder(root->right);
    }
void PrintTreeInInOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    PrintTreeInInOrder(root->left);   // visit left subtree
    cout << root->data << " ";        // visit node
    PrintTreeInInOrder(root->right);  // visit right subtree
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;
    for (int val:arr){
        root = insert(root,val);
    }
    return root;
}

Node* search(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(key < root->data){
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}


Node* inOrderSuccessor(Node* node){
    node = node->right;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Node* deleteNode(Node* root, int key){
//     root = search(root,key);
//     if (root==nullptr)
//     {
//         return NULL;
//     }

//     if (root->left==nullptr && root->right==nullptr)
//     {
//         delete root;
//     }

//     else if (root->left!=nullptr || root->right!=nullptr)
//     {
//         if (root->right!=nullptr && root->right!=nullptr)
//         {
//             Node* scNode= inOrderSuccessor(root);

//         }
//     }
// }

Node* delNode(Node* root, int key){
    if(root == nullptr){
        return NULL;
    }
    if(key<root->data){
        root->left=delNode(root->left,key);
    }
    else if(key>root->data){
        root->right=delNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* IS = inOrderSuccessor(root);
            root->data = IS->data;
            root->right = delNode(root->right,IS->data);
        }
    }
    return root;
}

int main(){
    vector<int> arr = {3,2,1,5,6,4};
    Node* root = buildBST(arr);
    PrintTreeInInOrder(root);
    //cout<<search(root, 9)<<endl;
    delNode(root,3);
    cout<<endl;
    PrintTreeInInOrder(root);
    return 0;
}