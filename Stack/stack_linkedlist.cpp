#include <iostream>
using namespace std;

// Node structure for stack
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push a single value
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Push multiple values
    void pushMultiple() {
        int n, value;
        cout << "How many values do you want to push? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter value " << (i + 1) << ": ";
            cin >> value;
            push(value);
        }

        cout << n << " values pushed successfully to stack." << endl;
    }

    // Pop value
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        Node* temp = top;
        cout << top->data << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }

    // Display stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Peek top value
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack s;
    int choice, value;

    // Show menu once
    cout << "----- STACK (Linked List) MENU -----" << endl;
    cout << "1. Push Single Value" << endl;
    cout << "2. Push Multiple Values" << endl;
    cout << "3. Pop" << endl;
    cout << "4. Display" << endl;
    cout << "5. Peek (Top)" << endl;
    cout << "6. Exit" << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pushMultiple();
                break;

            case 3:
                s.pop();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Top element: " << s.peek() << endl;
                break;

            case 6:
                cout << "Exiting program." << endl;
                exit(0);

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

