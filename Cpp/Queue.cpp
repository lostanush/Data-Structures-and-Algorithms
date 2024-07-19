#include<iostream>
#include<vector>
using namespace std;

class Queue {
    int front = -1;
    int rear = -1;
    vector<int> v;
    int size;
public:
    Queue(){}
    void enqueue(int);
    void dequeue();
    void display();
};

void Queue::enqueue(int n) {
    if (rear == size - 1) {
        cout << "\nQueue is full.\n";
        return;
    } 
    else {
        front = 0;
        rear++;
        v.push_back(n); // Use push_back() to add elements to the vector
        cout << n << " enqueued successfully.\n\n";
        size++;
    }
}

void Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty, unable to dequeue.\n";
        return;
    } 
    else {
        cout << v[front] << " is dequeued from queue.\n\n";
        front++;
        size--;
    }
}

void Queue::display() {
    if (front == -1 && rear == -1) {
        cout << "Queue underflow.\n";
    } 
    else {
        cout << "\nQueue: ";
        for (int i = front; i <= rear; i++) {
            cout << v[i] << " ";
        }
        cout << "\n\n";
    }
}

int main() {
    int option;
    int num;
    Queue que;
    cout << "\n   MENU :: \n";
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nSelect option: ";
        cin >> option;
        switch(option) {
            case 1:
                cout << "Enter an element to enqueue: ";
                cin >> num;
                que.enqueue(num);
                break;
            case 2:
                que.dequeue();
                break;
            case 3:
                que.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid input\n";
                break;
        }
    } while (true);
    return 0;
}
