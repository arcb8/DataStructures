#include <cassert>
#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* head;
    Node* tail;
    size_t size;

public:
    Queue() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~Queue() {
        clear();
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
    }

    int dequeue() {
        if (empty()) {
            std::cout << "Queue is empty" << std::endl;
        }
        else {
            Node* tmp = head;
            head = head->next;
            int value = tmp->data;

            delete tmp;

            size--;

            if (head == nullptr) {
                tail = nullptr;
            }
            return value;
        }
    }

    int front() const { // выводит значение из head
        if (empty()) {
            std::cout << "Queue is empty" << std::endl;
        }
        else {
            return head->data;
        }
    }

    bool empty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void clear() {
        while (!empty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    // 1. Очередь изначально пустая
    assert(q.empty());
    assert(q.getSize() == 0);

    // 2. Добавление одного элемента
    q.enqueue(10);
    assert(!q.empty());
    assert(q.getSize() == 1);
    assert(q.front() == 10);

    // 3. Добавление нескольких элементов
    q.enqueue(20);
    q.enqueue(30);
    assert(q.getSize() == 3);
    assert(q.front() == 10);

    // 4. Удаление элементов (FIFO)
    assert(q.dequeue() == 10);
    assert(q.front() == 20);
    assert(q.getSize() == 2);

    assert(q.dequeue() == 20);
    assert(q.dequeue() == 30);
    assert(q.empty());
    assert(q.getSize() == 0);

    // 5. Проверка корректной работы после очистки
    q.enqueue(100);
    q.enqueue(200);
    q.clear();
    assert(q.empty());

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
