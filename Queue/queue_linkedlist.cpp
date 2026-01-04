#include <iostream>
using namespace std;

// Node structure for queue
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue single value
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Enqueue multiple values
    void enqueueMultiple() {
        int n, value;
        cout << "How many values do you want to enqueue? ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "Enter value " << (i + 1) << ": ";
            cin >> value;
            enqueue(value);
        }

        cout << n << " values enqueued successfully." << endl;
    }

    // Dequeue
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        Node* temp = front;
        cout << front->data << " dequeued from queue." << endl;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Display queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Peek front
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    Queue q;
    int choice, value;

    // Show menu once
    cout << "----- QUEUE (Linked List) MENU -----" << endl;
    cout << "1. Enqueue Single Value" << endl;
    cout << "2. Enqueue Multiple Values" << endl;
    cout << "3. Dequeue" << endl;
    cout << "4. Display" << endl;
    cout << "5. Peek (Front)" << endl;
    cout << "6. Exit" << endl;

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.enqueueMultiple();
                break;

            case 3:
                q.dequeue();
                break;

            case 4:
                q.display();
                break;

            case 5:
                cout << "Front element: " << q.peek() << endl;
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
