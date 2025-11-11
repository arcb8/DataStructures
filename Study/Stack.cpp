#include <algorithm>
#include <float.h>
#include <iostream>

class Stack {
private:
    int* data;      // динамический массив
    int capacity;   // текущая вместимость массива
    int topIndex;   // индекс вершины стека

    void resize() {
        // define new array
        int* new_data = new int[capacity * 2];
        // move elements
        for (int i = 0; i < capacity; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        // update fields
        data = new_data;
        capacity *= 2;
    }

public:
    Stack(int initialCapacity = 10) {
        capacity = initialCapacity;
        topIndex = 0;
        data = new int [capacity];
    }
    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "The stack doubles." << std::endl;
            resize();
        }
        data[topIndex] = value;
        topIndex++;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }

        topIndex--;
        return data[topIndex];
    }

    void clear() {
        topIndex = 0;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return data[topIndex - 1];
    }

    int count() {
        return topIndex;
    }

    bool isEmpty() {
        return topIndex == 0;

    }
    bool isFull() {
        return topIndex == capacity;
    }

    void print() {
        std::cout << "[ ";
        for (int i = 0; i < capacity; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "]\n";
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.print(); // Выведет: 30 20 10

    std::cout <<  "Top element: " << stack.peek() << std::endl; // 30
    std::cout << "Count: " << stack.count() << std::endl;      // 3

    stack.pop();
    stack.clear();
    stack.push(40);
    stack.push(30);
    stack.print(); // Выведет: 20 10
    std::cout << "Count: " << stack.count() << std::endl;

    return 0;
}