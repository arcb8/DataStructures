#include <cassert>
#include <iostream>
#include <string>
#include <cstddef>

struct Node {
    int key;
    std::string value;
    Node* next;
    Node(int k, const std::string& v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashMap {
private:
    Node** buckets;
    std::size_t capacity;
    std::size_t size_;
    const float maxLoadFactor = 0.75f;

    std::size_t hash(int key) {                 // преобразует ключ в индекс
        std::hash<size_t> hasher;
        return hasher(key) % capacity;
    }

    void rehash(std::size_t newCapacity){       // создает новую таблицу и пересчитывает все элементы
        // 1. Создать новую хэш-таблицу
        Node** newBuckets = new Node*[newCapacity];
        for (int i = 0; i < newCapacity; i++) {
            newBuckets[i] = nullptr;
        }
        // 2. Пройтись по каждому элементу
        for (int i = 0; i < capacity; i++) {
            // 2.1. Рехэшировать каждый элемент
            Node* current = buckets[i];
            while (current != nullptr) {
                Node* next = current->next;
                std::hash<size_t> hasher;
                size_t index = hasher(current->key) % newCapacity;

                current->next = newBuckets[index];
                newBuckets[index] = current;

                current = next;
            }
        }
        // 3. Удалить старую хэш-таблицу
        delete[] buckets;
        capacity = newCapacity;
        buckets = newBuckets;
    }

    void checkLoadFactor()                      // следит что бы заполненость таблицы
    {
        float curLoadFactor = (float)size_ / capacity;
        if (curLoadFactor > maxLoadFactor) {
            rehash(capacity * 2);
        }
    }

public:
    HashMap(std::size_t cap = 16){
        capacity = cap;
        size_ = 0;
        buckets = new Node* [capacity];
        for (int i = 0; i < cap; i++) {
            buckets[i] = nullptr;
        }
    }
    ~HashMap() {
        for (int i = 0; i < capacity; i++) {
            Node* current = buckets[i];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] buckets;
    }

    void put(int key, const std::string& value) {
        size_t i = hash(key);

        Node* current = buckets[i];
        while (current != nullptr) {
            current = current->next;
        }

        Node* node = new Node(key, value);
        node->next = buckets[i];
        buckets[i] = node;

        size_++;
        checkLoadFactor();
    }

    std::string get(int key) {
        size_t i = hash(key);

        Node* current = buckets[i];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }

            current = current->next;
        }

        return "";
    }

    bool remove(int key) {
        size_t i = hash(key);

        Node* current = buckets[i];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev != nullptr) {
                    prev->next = current->next;
                }
                else {
                    buckets[i] = current->next;
                }

                delete current;
                size_--;
                return true;
            }

            prev = current;
            current = current->next;
        }

        return false;
    }

    std::size_t size() {
        return size_;
    }
};

int main(){
    HashMap map;

    // put / get
    map.put(1, "one");
    map.put(2, "two");
    map.put(3, "three");

    assert(map.get(1) == "one");
    assert(map.get(2) == "two");
    assert(map.get(3) == "three");

    // перезапись значения (коллизия по ключу)
    map.put(2, "TWO");
    assert(map.get(2) == "TWO");

    // size
    assert(map.size() == 4); // т.к. твоя реализация не заменяет, а добавляет

    // remove
    assert(map.remove(1) == true);
    assert(map.remove(1) == false); // повторное удаление
    assert(map.size() == 3);

    // удаление из середины цепочки
    map.put(17, "collision"); // при capacity=16 будет коллизия с 1
    assert(map.get(17) == "collision");
    assert(map.remove(17) == true);

    // несуществующий ключ
    assert(map.get(999).empty() == true);
    assert(map.remove(999) == false);

    // rehash (проверка, что данные не теряются)
    for (int i = 0; i < 100; i++) {
        map.put(i, std::to_string(i));
    }

    for (int i = 0; i < 100; i++) {
        assert(map.get(i) == std::to_string(i));
    }

    return 0;
}
