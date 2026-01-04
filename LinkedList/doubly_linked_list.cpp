#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Doubly linked list class
class DoublyLinkedList {
public:
    Node* start;
    Node* temp;
    Node* current;
    Node* previous;

    // Constructor
    DoublyLinkedList() {
        start = NULL;
    }

    // Create doubly linked list
    void createLinkedList() {
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int data;
            cout << "Enter data for node " << i << ": ";
            cin >> data;

            temp = new Node();
            temp->data = data;
            temp->next = NULL;
            temp->prev = NULL;

            if (start == NULL) {
                start = temp;
            } else {
                current = start;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = temp;
                temp->prev = current;
            }
        }
    }

    // Display doubly linked list
    void displayLinkedList() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        current = start;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Insert at beginning
    void insertAtBeginning() {
        int data;
        cout << "Enter data for new node: ";
        cin >> data;

        temp = new Node();
        temp->data = data;
        temp->next = start;
        temp->prev = NULL;

        if (start != NULL) {
            start->prev = temp;
        }

        start = temp;
    }

    // Insert at end
    void insertAtEnd() {
        int data;
        cout << "Enter data for new node: ";
        cin >> data;

        temp = new Node();
        temp->data = data;
        temp->next = NULL;

        if (start == NULL) {
            temp->prev = NULL;
            start = temp;
        } else {
            current = start;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
            temp->prev = current;
        }
    }

    // Insert at specific position
    void insertAtSpecificPosition() {
        int pos, data;
        cout << "Enter position for new node: ";
        cin >> pos;
        cout << "Enter data for new node: ";
        cin >> data;

        if (pos == 1) {
            insertAtBeginning();
            return;
        }

        temp = new Node();
        temp->data = data;

        current = start;
        for (int i = 1; i < pos - 1; i++) {
            if (current == NULL) {
                cout << "Position out of range" << endl;
                return;
            }
            current = current->next;
        }

        temp->next = current->next;
        temp->prev = current;

        if (current->next != NULL) {
            current->next->prev = temp;
        }

        current->next = temp;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        current = start;
        start = start->next;

        if (start != NULL) {
            start->prev = NULL;
        }

        delete current;
        cout << "First node deleted" << endl;
    }

    // Delete from end
    void deleteFromEnd() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        current = start;
        while (current->next != NULL) {
            current = current->next;
        }

        if (current->prev != NULL) {
            current->prev->next = NULL;
        } else {
            start = NULL;
        }

        delete current;
        cout << "Last node deleted" << endl;
    }

    // Delete at specific position
    void deleteAtSpecificPosition() {
        int pos;
        cout << "Enter position of node to delete: ";
        cin >> pos;

        if (pos < 1 || start == NULL) {
            cout << "Invalid position" << endl;
            return;
        }

        current = start;
        for (int i = 1; i < pos; i++) {
            if (current == NULL) {
                cout << "Position out of range" << endl;
                return;
            }
            current = current->next;
        }

        if (current->prev != NULL) {
            current->prev->next = current->next;
        } else {
            start = current->next;
        }

        if (current->next != NULL) {
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Node deleted from given position" << endl;
    }

    // Display even data
    void displayEvenData() {
        current = start;
        while (current != NULL) {
            if (current->data % 2 == 0) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Display odd data
    void displayOddData() {
        current = start;
        while (current != NULL) {
            if (current->data % 2 != 0) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Find max value
    void findMaxValue() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        int maxVal = start->data;
        current = start->next;
        while (current != NULL) {
            if (current->data > maxVal) {
                maxVal = current->data;
            }
            current = current->next;
        }

        cout << "Maximum value: " << maxVal << endl;
    }

    // Find min value
    void findMinValue() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        int minVal = start->data;
        current = start->next;
        while (current != NULL) {
            if (current->data < minVal) {
                minVal = current->data;
            }
            current = current->next;
        }

        cout << "Minimum value: " << minVal << endl;
    }

    // Search for value
    void searchValue() {
        int val;
        cout << "Enter value to search: ";
        cin >> val;

        current = start;
        bool found = false;
        while (current != NULL) {
            if (current->data == val) {
                found = true;
                break;
            }
            current = current->next;
        }

        if (found) {
            cout << "Value found" << endl;
        } else {
            cout << "Value not found" << endl;
        }
    }

    // Sort doubly linked list
    void sortLinkedList() {
        if (start == NULL || start->next == NULL) {
            cout << "List empty or only one node, no sorting needed" << endl;
            return;
        }

        current = start;
        while (current != NULL) {
            Node* index = current->next;
            while (index != NULL) {
                if (current->data > index->data) {
                    int t = current->data;
                    current->data = index->data;
                    index->data = t;
                }
                index = index->next;
            }
            current = current->next;
        }

        cout << "Sorted Linked List: ";
        displayLinkedList();
    }
};

// Main menu
int main() {
    DoublyLinkedList list;
    int choice;

    cout << "Enter 1 to create list" << endl;
    cout << "Enter 2 to display list" << endl;
    cout << "Enter 3 to insert at end" << endl;
    cout << "Enter 4 to insert at beginning" << endl;
    cout << "Enter 5 to insert at specific position" << endl;
    cout << "Enter 6 to delete from end" << endl;
    cout << "Enter 7 to delete from beginning" << endl;
    cout << "Enter 8 to delete from specific position" << endl;
    cout << "Enter 9 to sort the list" << endl;
    cout << "Enter 10 to search value" << endl;
    cout << "Enter 11 to display even data" << endl;
    cout << "Enter 12 to display odd data" << endl;
    cout << "Enter 13 to find max value" << endl;
    cout << "Enter 14 to find min value" << endl;
    cout << "Enter 15 to exit" << endl;

    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                list.createLinkedList();
                break;

            case 2: 
                list.displayLinkedList();
                break;

            case 3: 
                list.insertAtEnd();
                break;

            case 4: 
                list.insertAtBeginning();
                break;

            case 5: 
                list.insertAtSpecificPosition();
                break;

            case 6: 
                list.deleteFromEnd();
                break;

            case 7: 
                list.deleteFromBeginning();
                break;

            case 8: 
                list.deleteAtSpecificPosition();
                break;

            case 9: 
                list.sortLinkedList();
                break;

            case 10: 
                list.searchValue();
                break;

            case 11: 
                cout << "Even data: ";
                list.displayEvenData();
                break;

            case 12: 
                cout << "Odd data: ";
                list.displayOddData();
                break;

            case 13: 
                list.findMaxValue();
                break;

            case 14: 
                list.findMinValue();
                break;

            case 15: 
                exit(0);
                break;

            default: 
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}

