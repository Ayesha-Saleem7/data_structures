#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear;
    int size;

public:
    Queue() {
        front = -1;
        rear = -1;
        size = 100;
    }

    // Enqueue single value
    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % size;
        arr[rear] = value;

        cout << value << " enqueued to queue." << endl;
    }

    // Enqueue multiple values
    void enqueueMultiple() {
        int n, value;
        cout << "How many values do you want to enqueue? ";
        cin >> n;

        if ((rear + n) >= size) {
            cout << "Queue Overflow! Cannot enqueue " << n << " values." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter value " << (i + 1) << ": ";
            cin >> value;

            if (front == -1) {
                front = 0;
            }

            rear = (rear + 1) % size;
            arr[rear] = value;
        }

        cout << n << " values enqueued successfully to queue." << endl;
    }

    // Dequeue value
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << arr[front] << " dequeued from queue." << endl;

        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % size;
        }
    }

    // Display queue elements
    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    // Peek front value
    int peek() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    int choice, value;

    // Show menu once
    cout << "----- QUEUE MENU -----" << endl;
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

