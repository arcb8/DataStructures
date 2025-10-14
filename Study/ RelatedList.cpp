#include <iostream>
#include <assert.h>

struct Node {
    Node* next;
    int data;
    Node(int _data) {
        data = _data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    LinkedList(int _value) {
        push_front(_value);
    }
    // O(1)
    void push_front(int value) {
        Node* node = new Node(value);

        if (head == nullptr) tail = node;
        else node->next = head;

        head = node;
    }
    // O(1)
    void push_back(int value) {
        Node* node = new Node(value);

        if (tail == nullptr) head = node;
        else tail->next = node;

        tail = node;
    }

    Node* find(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    void insert(size_t index, int value) {
        Node* current = find(index);
        if (current != nullptr) {
            Node* node = new Node(value);
            if (current == tail) tail = node;
            node->next = current->next;
            current->next = node;
        }

    }

    void remove(size_t index) {
        Node* current = head;
        int pos = 0;
        while (pos < index-1) {
            pos++;
            current = current->next;
        }
        Node* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
    }

    int size() {
        Node* current = head;
        int i = 0;
        while (current != nullptr) {
            i++;
            current = current->next;
        }
        return i;
    }

    void display() {
        Node* current = head;
        std::cout << "[ 1 -> 2 -> -3 -> “nullptr” ]";
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};



int main()
{
    LinkedList list(10);

    // ✅ Начальное состояние
    assert(list.size() == 1);
    assert(list.find(10) != nullptr);

    // ✅ push_front
    list.push_front(5);
    assert(list.size() == 2);
    assert(list.find(5) != nullptr);
    assert(list.find(10) != nullptr);

    // ✅ push_back
    list.push_back(20);
    list.push_back(30);
    assert(list.size() == 4);
    assert(list.find(20) != nullptr);
    assert(list.find(30) != nullptr);

    // ✅ insert (middle)
    list.insert(10, 15);
    assert(list.size() == 5);
    assert(list.find(15) != nullptr);
    assert(list.find(20) != nullptr);

    // ✅ remove (middle)
    list.remove(1); // удаляем элемент с индексом 1 (10)
    assert(list.size() == 4);
    assert(list.find(5) != nullptr);
    assert(list.find(15) != nullptr);
    assert(list.find(20) != nullptr);

    // ✅ find (существующий)
    Node* found = list.find(20);
    assert(found != nullptr);
    assert(found->data == 20);

    // ✅ find (не существующий)
    assert(list.find(100) == nullptr);

    // ✅ remove(0) — удаление головы
    list.remove(0);
    assert(list.size() == 3);
    assert(list.find(15) != nullptr);

    std::cout << "✅ All tests passed.\n";

    return 0;
}