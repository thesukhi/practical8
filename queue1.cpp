#include <iostream>
#define MAX_SIZE 100

class Queue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    // Enqueue operation
    void enqueue(int value) {
        if (rear == MAX_SIZE - 1) {
            std::cout << "Queue is full. Cannot enqueue " << value << "." << std::endl;
            return;
        }
        if (front == -1) {
            front = 0; // Set front when first element is inserted
        }
        arr[++rear] = value;
        std::cout << value << " enqueued into the queue." << std::endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }
        std::cout << arr[front] << " dequeued from the queue." << std::endl;
        front++;
        if (front > rear) {
            // Reset the queue when it's empty
            front = rear = -1;
        }
    }

    // Print the queue
    void print() {
        if (front == -1 || front > rear) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue queue;
    int choice, value;

    while (true) {
        std::cout << "\n--- Queue Operations ---" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Print" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue: ";
                std::cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.print();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}