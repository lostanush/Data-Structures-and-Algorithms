#include<iostream>
#include<stdexcept> // For std::runtime_error
using namespace std;

class Stack {
    class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
        Node(int data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
    Node* top;
    int maxSize;
    int currentSize;
public:
    Stack(int maxSize) {
        top = nullptr;
        this->maxSize = maxSize;
        currentSize = 0;
    }

    void push(int data) {
        if (currentSize == maxSize) {
            throw overflow_error("Stack overflow");
        }
        Node* newNode = new Node(data, top);
        top = newNode;
        currentSize++;
    }

    void pop() {
        if (top == nullptr) {
            throw underflow_error("Stack underflow");
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        currentSize--;
    }

    void display() {
        Node* ptr = top;
        cout << "Stack-LinkedList:";
        while (ptr != nullptr) {
            cout << " " << ptr->data;
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main() {
    try {
        Stack stack(3);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();

        // This will cause stack overflow
        stack.push(40); // Uncomment to test overflow exception
    } catch (const overflow_error& e) {
        cout << e.what() << endl;
    }

    try {
        Stack stack(3);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        stack.display();

        stack.pop();
        stack.display();

        stack.pop();
        stack.display();

        stack.pop();
        stack.display();

        // This will cause stack underflow
        stack.pop();
    } catch (const underflow_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
