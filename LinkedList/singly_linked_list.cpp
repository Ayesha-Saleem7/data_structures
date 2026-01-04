#include <iostream>
using namespace std;

//Singly Linked List Implementation in C++

// Node structure
struct Node {
    int data;
    Node* link;
};

// Linked list class
class LinkedList {
public:
    Node* start;
    Node* temp;
    Node* current;
    Node* previous;

    LinkedList() {
        start = NULL;
    }
    
  // Create Linked List
    void createLinkedList() {
        int n;
        cout << "Enter the number of nodes: ";
        cin >> n;

        for (int i = 1; i <= n; i++) {
            int data;
            cout << "Enter data for node " << i << ": ";
            cin >> data;

            temp = new Node();
            temp->data = data;
            temp->link = NULL;

            if (start == NULL) {
                start = temp;
            } else {
                current = start;
                while (current->link != NULL) {
                    current = current->link;
                }
                current->link = temp;
            }
        }
    }
  
  // Display Linked List
    void displayLinkedList() {
        if (start == NULL) {
            cout << "List is empty" << endl;
        } else {
            current = start;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->link;
            }
            cout << endl;
        }
    }
 
 // Insert at End
    void insertAtEnd() {
        int data;
        cout << "Enter data: ";
        cin >> data;

        temp = new Node();
        temp->data = data;
        temp->link = NULL;

        if (start == NULL) {
            start = temp;
        } else {
            current = start;
            while (current->link != NULL) {
                current = current->link;
            }
            current->link = temp;
        }
    }
  
  // Insert at Beginning
    void insertAtBeginning() {
        int data;
        cout << "Enter data: ";
        cin >> data;

        temp = new Node();
        temp->data = data;
        temp->link = start;
        start = temp;
    }
    
  // Insert at Specific Position
    void insertAtSpecificPosition() {
        int pos, data;
        cout << "Enter position: ";
        cin >> pos;
        cout << "Enter data: ";
        cin >> data;

        if (pos == 1) {
            insertAtBeginning();
        } else {
            temp = new Node();
            temp->data = data;

            current = start;
            for (int i = 1; i < pos - 1; i++) {
                if (current->link == NULL) {
                    cout << "Position out of range" << endl;
                    return;
                }
                current = current->link;
            }

            temp->link = current->link;
            current->link = temp;
        }
    }

  // Delete from End
    void deleteFromEnd() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        current = previous = start;
        while (current->link != NULL) {
            previous = current;
            current = current->link;
        }

        previous->link = NULL;
        delete current;
        cout << "Last node deleted" << endl;
    }
  // Delete from Beginning
    void deleteFromBeginning() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        current = start;
        start = start->link;
        delete current;
        cout << "First node deleted" << endl;
    }
  
  // Delete at Specific Position
    void deleteAtSpecificPosition() {
        int pos;
        cout << "Enter position: ";
        cin >> pos;

        if (pos == 1) {
            deleteFromBeginning();
        } else {
            previous = NULL;
            current = start;

            for (int i = 1; i < pos; i++) {
                if (current == NULL) {
                    cout << "Position out of range" << endl;
                    return;
                }
                previous = current;
                current = current->link;
            }

            previous->link = current->link;
            delete current;
            cout << "Node deleted" << endl;
        }
    }
    
  // Sort Linked List
    void sortLinkedList() {
        if (start == NULL || start->link == NULL) {
            cout << "No sorting needed" << endl;
            return;
        }

        current = start;
        while (current != NULL) {
            previous = current->link;
            while (previous != NULL) {
                if (current->data > previous->data) {
                    int t = current->data;
                    current->data = previous->data;
                    previous->data = t;
                }
                previous = previous->link;
            }
            current = current->link;
        }

        cout << "List sorted" << endl;
    }
    
  // Display Even Data
    void searchValue() {
        int value;
        cout << "Enter value to search: ";
        cin >> value;

        current = start;
        while (current != NULL) {
            if (current->data == value) {
                cout << "Value found" << endl;
                return;
            }
            current = current->link;
        }

        cout << "Value not found" << endl;
    }
 
  // Display Even Data
    void displayEvenData() {
        current = start;
        while (current != NULL) {
            if (current->data % 2 == 0) {
                cout << current->data << " ";
            }
            current = current->link;
        }
        cout << endl;
    }
    
  // Display Odd Data
    void displayOddData() {
        current = start;
        while (current != NULL) {
            if (current->data % 2 != 0) {
                cout << current->data << " ";
            }
            current = current->link;
        }
        cout << endl;
    }

  // Find Maximum Value
    void findMaxValue() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        int max = start->data;
        current = start->link;

        while (current != NULL) {
            if (current->data > max) {
                max = current->data;
            }
            current = current->link;
        }

        cout << "Maximum value: " << max << endl;
    }

  // Find Minimum Value
    void findMinValue() {
        if (start == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        int min = start->data;
        current = start->link;

        while (current != NULL) {
            if (current->data < min) {
                min = current->data;
            }
            current = current->link;
        }

        cout << "Minimum value: " << min << endl;
    }
};

int main() {
    LinkedList list;
    int choice;

    cout << "1 Create List\n2 Display\n3 Insert End\n4 Insert Begin\n";
    cout << "5 Insert Position\n6 Delete End\n7 Delete Begin\n";
    cout << "8 Delete Position\n9 Sort\n10 Search\n";
    cout << "11 Display Even\n12 Display Odd\n";
    cout << "13 Find Max\n14 Find Min\n15 Exit\n";

    while (true) {
        cout << "Enter choice: ";
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
            list.displayEvenData();
            break;

        case 12:
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

        default:
            cout << "Invalid choice" << endl;
        }
    }
}

