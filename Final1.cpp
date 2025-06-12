#include <iostream>
using namespace std;

class Node {
public:
    int taskID;
    Node* next;

    Node(int id) {
        taskID = id;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
        cout << "Pushed task ID: " << id << " onto stack." << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Nothing to undo." << endl;
            return;
        }
        cout << "Popped task ID: " << top->taskID << " from stack." << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void display() {
        Node* temp = top;
        cout << "Current Stack (Top to Bottom): ";
        while (temp != nullptr) {
            cout << temp->taskID << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int id) {
        Node* newNode = new Node(id);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued task ID: " << id << " to queue." << endl;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Dequeued task ID: " << front->taskID << " from queue." << endl;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = front;
        cout << "Current Queue (Front to Rear): ";
        while (temp != nullptr) {
            cout << temp->taskID << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* getFront() {
        return front;
    }
};
void sortLinkedList(Node* head) {
    if (!head) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->taskID > ptr1->next->taskID) {
                swap(ptr1->taskID, ptr1->next->taskID);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    // Display sorted list
    cout << "Sorted Task IDs: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->taskID << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Stack taskStack;
    Queue taskQueue;

    cout << "=== Stack Operations ===" << endl;
    taskStack.push(501);
    taskStack.push(503);
    taskStack.push(502);
    taskStack.display();
    taskStack.pop();
    taskStack.display();

    cout << "\n=== Queue Operations ===" << endl;
    taskQueue.enqueue(701);
    taskQueue.enqueue(703);
    taskQueue.enqueue(702);
    taskQueue.display();
    taskQueue.dequeue();
    taskQueue.display();

    cout << "\n=== Sorting Task IDs ===" << endl;
    sortLinkedList(taskQueue.getFront());

    return 0;
}

