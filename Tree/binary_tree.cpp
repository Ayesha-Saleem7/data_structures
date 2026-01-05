#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
private:
    Node* root;

    Node* createNode() {
        int value;
        cout << "Enter data (-1 for no node): ";
        cin >> value;
        if (value == -1) return nullptr;

        Node* newNode = new Node{value, nullptr, nullptr};
        cout << "Enter left child of " << value << endl;
        newNode->left = createNode();
        cout << "Enter right child of " << value << endl;
        newNode->right = createNode();

        return newNode;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    void createTree() {
        root = createNode();
        cout << "Binary Tree created successfully.\n";
    }

    void showInorder() {
        if (!root) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void showPreorder() {
        if (!root) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }

    void showPostorder() {
        if (!root) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int choice;

    // Menu displayed only once
    cout << "========== BINARY TREE MENU ==========\n";
    cout << "1. Create Binary Tree\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Preorder Traversal\n";
    cout << "4. Postorder Traversal\n";
    cout << "5. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.createTree();
                break;
            case 2:
                tree.showInorder();
                break;
            case 3:
                tree.showPreorder();
                break;
            case 4:
                tree.showPostorder();
                break;
            case 5:
                cout << "Program terminated.\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

