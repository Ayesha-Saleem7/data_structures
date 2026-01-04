#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int arr[100]; // maximum size of stack

public:
    Stack() {
        top = -1;
    }

    // Push single value
    void push(int value) {
        if (top >= 99) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << value << " pushed to stack." << endl;
    }

    // Push multiple values at once
    void pushMultiple() {
        int n, value;
        cout << "How many values do you want to push? ";
        cin >> n;

        if (top + n >= 100) {
            cout << "Stack Overflow! Cannot push " << n << " values." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter value " << (i + 1) << ": ";
            cin >> value;
            top++;
            arr[top] = value;
        }

        cout << n << " values pushed successfully to stack." << endl;
    }

    // Pop value from stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    // Display all stack elements
    void display() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Peek top element
    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    int choice, value;

    // Show menu only once
    cout << "----- STACK MENU -----" << endl;
    cout << "1. Push Single Value" << endl;
    cout << "2. Push Multiple Values" << endl;
    cout << "3. Pop" << endl;
    cout << "4. Display" << endl;
    cout << "5. Peek" << endl;
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

