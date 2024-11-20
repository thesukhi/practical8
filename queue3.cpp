 #include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (rear == nullptr) {
            // If the queue is empty
            front = rear = newNode;
        } else {
            // Add the new node at the rear
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            // If the queue becomes empty, update rear as well
            rear = nullptr;
        }

        cout << temp->data << " dequeued from the queue." << endl;
        delete temp;
    }

    // Print operation
    void print() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        cout << "Queue destroyed." << endl;
    }
};

// Main function
int main() {
    Queue queue;
    int choice, value;

    while (true) {
        cout << "\n--- Queue Operations ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.print();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
[13:01, 20/11/2024] Sukhbir Singh⚜️: #include <iostream>
#define MAX_SIZE 5 // Define the size of the circular queue
using namespace std;

class CircularQueue {
private:
    int arr[MAX_SIZE]; // Array to store queue elements
    int front, rear;   // Pointers for front and rear of the queue

public:
    // Constructor to initialize the circular queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if ((rear + 1) % MAX_SIZE == front) {
            // Queue is full
            cout << "Queue is full. Cannot enqueue " << value << "." << endl;
            return;
        }
        if (front == -1) {
            // First element being inserted
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; // Update rear in a circular manner
        }
        arr[rear] = value;
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1) {
            // Queue is empty
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from the queue." << endl;
        if (front == rear) {
            // Queue becomes empty after removing the last element
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; // Update front in a circular manner
        }
    }

    // Print operation
    void print() {
        if (front == -1) {
            // Queue is empty
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break; // Stop when we reach the rear
            i = (i + 1) % MAX_SIZE; // Move to the next index circularly
        }
        cout << endl;
    }
};

// Main function
int main() {
    CircularQueue queue;
    int choice, value;

    while (true) {
        cout << "\n--- Circular Queue Operations ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.print();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}