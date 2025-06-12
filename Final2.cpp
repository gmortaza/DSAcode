#include <iostream>
using namespace std;

// Define structure of a node
struct Node {
    int fileID;
    Node* left;
    Node* right;

    Node(int id) {
        fileID = id;
        left = right = nullptr;
    }
};

// Class for BST operations
class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    // Insert a file ID into the BST
    Node* insert(Node* root, int id) {
        if (root == nullptr)
            return new Node(id);

        if (id < root->fileID)
            root->left = insert(root->left, id);
        else if (id > root->fileID)
            root->right = insert(root->right, id);
        return root;
    }

    // In-order traversal
    void inorder(Node* root) {
        if (root == nullptr) return;
        inorder(root->left);
        cout << root->fileID << " ";
        inorder(root->right);
    }

    // Pre-order traversal
    void preorder(Node* root) {
        if (root == nullptr) return;
        cout << root->fileID << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Post-order traversal
    void postorder(Node* root) {
        if (root == nullptr) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->fileID << " ";
    }

    // Search a file ID
    bool search(Node* root, int id) {
        if (root == nullptr) return false;
        if (root->fileID == id) return true;
        else if (id < root->fileID)
            return search(root->left, id);
        else
            return search(root->right, id);
    }

    // Find node with minimum value (used in deletion case 3)
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    // Delete a node from BST
    Node* deleteNode(Node* root, int id) {
        if (root == nullptr) return root;

        if (id < root->fileID)
            root->left = deleteNode(root->left, id);
        else if (id > root->fileID)
            root->right = deleteNode(root->right, id);
        else {
            // Case 1: No child
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: One child
            else if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            Node* temp = minValueNode(root->right);
            root->fileID = temp->fileID;
            root->right = deleteNode(root->right, temp->fileID);
        }
        return root;
    }
};
int main() {
    BST bst;

    // Insert new set of file IDs into the BST
    int fileIDs[] = {55, 25, 75, 15, 35, 65, 85};
    for (int id : fileIDs)
        bst.root = bst.insert(bst.root, id);

    cout << "Initial Inorder Traversal: ";
    bst.inorder(bst.root);
    cout << "\n";

    // Delete leaf node (15)
    cout << "Deleting leaf node (15)\n";
    bst.root = bst.deleteNode(bst.root, 15);
    bst.inorder(bst.root); cout << "\n";

    // Delete node with one child (25)
    cout << "Deleting node with one child (25)\n";
    bst.root = bst.deleteNode(bst.root, 25);
    bst.inorder(bst.root); cout << "\n";

    // Delete node with two children (55)
    cout << "Deleting node with two children (55)\n";
    bst.root = bst.deleteNode(bst.root, 55);
    bst.inorder(bst.root); cout << "\n";

    // Final traversals
    cout << "\nFinal Tree Traversals:\n";
    cout << "Inorder: "; bst.inorder(bst.root); cout << "\n";
    cout << "Preorder: "; bst.preorder(bst.root); cout << "\n";
    cout << "Postorder: "; bst.postorder(bst.root); cout << "\n";

    return 0;
}


