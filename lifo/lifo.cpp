#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    void push(T value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    T peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack<int> stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    cout << "Top element: " << stack.peek() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;
}
