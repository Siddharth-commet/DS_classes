#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int d) {
        data = d;
        left = right = nullptr;
    }
};

/* ------------------ BINARY TREE TRAVERSALS ------------------ */

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/* ---------------------------- BST ---------------------------- */

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

/* Search recursive */
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

/* Search non-recursive */
Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

/* Max element */
Node* maxElement(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

/* Min element */
Node* minElement(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

/* In-order successor */
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right)
        return minElement(target->right);

    Node* suc = nullptr;
    while (root) {
        if (target->data < root->data) {
            suc = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else break;
    }
    return suc;
}

/* In-order predecessor */
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left)
        return maxElement(target->left);

    Node* pre = nullptr;
    while (root) {
        if (target->data > root->data) {
            pre = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else break;
    }
    return pre;
}

/* ------------------------- DELETE NODE ------------------------ */

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minElement(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

/* ------------------- MAX DEPTH & MIN DEPTH -------------------- */

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l > r ? l : r) + 1;
}

int minDepth(Node* root) {
    if (!root) return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (l == 0 || r == 0) return l + r + 1;
    return (l < r ? l : r) + 1;
}

/* -------------------- CHECK IF TREE IS BST -------------------- */

bool isBSTUtil(Node* root, int minV, int maxV) {
    if (!root) return true;

    if (root->data <= minV || root->data >= maxV)
        return false;

    return isBSTUtil(root->left, minV, root->data) &&
           isBSTUtil(root->right, root->data, maxV);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

/* ------------------------------- MAIN -------------------------- */

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 20);

    cout << "Preorder: ";
    preorder(root);
    cout << "\n";

    cout << "Inorder: ";
    inorder(root);
    cout << "\n";

    cout << "Postorder: ";
    postorder(root);
    cout << "\n";

    Node* s1 = searchRec(root, 12);
    if (s1) cout << "Found 12 (recursive)\n";

    Node* s2 = searchNonRec(root, 15);
    if (s2) cout << "Found 15 (non-recursive)\n";

    cout << "Max element: " << maxElement(root)->data << "\n";
    cout << "Min element: " << minElement(root)->data << "\n";

    Node* target = searchRec(root, 12);
    cout << "In-order successor of 12: " << inorderSuccessor(root, target)->data << "\n";
    cout << "In-order predecessor of 12: " << inorderPredecessor(root, target)->data << "\n";

    cout << "Max depth: " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n";

    cout << "Is BST: " << isBST(root) << "\n";

    root = deleteNode(root, 10);

    cout << "Inorder after deleting 10: ";
    inorder(root);
    cout << "\n";

    return 0;
}
