#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// BST class
class BST {
private:
    Node* root;

    // Recursive insert
    Node* insert(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        else
            cout << "Value already exists in BST!" << endl;
        return node;
    }

    // Recursive search
    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val)
            return node;
        if (val < node->data)
            return search(node->left, val);
        return search(node->right, val);
    }

    // Find minimum value node (for deletion)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Recursive delete
    Node* remove(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->data)
            node->left = remove(node->left, val);
        else if (val > node->data)
            node->right = remove(node->right, val);
        else {
            // Node with only one child or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Traversals
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
    BST() {
        root = nullptr;
    }

    void insertValue(int val) {
        root = insert(root, val);
        cout << val << " inserted into BST.\n";
    }

    void deleteValue(int val) {
        if (search(root, val)) {
            root = remove(root, val);
            cout << val << " deleted from BST.\n";
        } else {
            cout << "Value not found in BST!\n";
        }
    }

    void searchValue(int val) {
        Node* result = search(root, val);
        if (result)
            cout << "Value " << val << " found in BST.\n";
        else
            cout << "Value " << val << " not found in BST.\n";
    }

    void inorderTraversal() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorderTraversal() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorderTraversal() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

// Main function
int main() {
    BST bst;
    int choice, val;

    cout << "========== BINARY SEARCH TREE MENU ==========" << endl;
    cout << "1. Insert Value" << endl;
    cout << "2. Delete Value" << endl;
    cout << "3. Search Value" << endl;
    cout << "4. Inorder Traversal" << endl;
    cout << "5. Preorder Traversal" << endl;
    cout << "6. Postorder Traversal" << endl;
    cout << "7. Exit" << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                bst.insertValue(val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                bst.deleteValue(val);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                bst.searchValue(val);
                break;
            case 4:
                bst.inorderTraversal();
                break;
            case 5:
                bst.preorderTraversal();
                break;
            case 6:
                bst.postorderTraversal();
                break;
            case 7:
                cout << "Exiting program." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

