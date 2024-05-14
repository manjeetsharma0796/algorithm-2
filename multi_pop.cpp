#include <iostream>
using namespace std;
class Stack {
   private:
    int *arr;
    int capacity;
    int top;

   public:
    Stack(int size) {
        capacity = size;
        arr      = new int[capacity];
        top      = -1;  // Stack is initially empty
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = element;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;  // Returning -1 as an error code
        }
        return arr[top--];
    }
    void multiPop(int count) {
        if (count > top + 1) {
            cout << "Not enough elements in the stack\n";
            return;
        }
        top -= count;
    }
};
int main() {
    Stack stack(4);  // Creating a stack of capacity 5
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;
    stack.multiPop(2);
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;
    return 0;
}