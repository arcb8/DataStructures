#include <iostream>

class DynamicArray {
private:
    int capacity;
    int size;
    int* array;

    void resize() {
        int* new_array = new int [capacity * 2];
        for (int i = 0; i < capacity; i++) {
            new_array[i] = array[i];
        }

        delete[] array;

        array = new_array;
        capacity *= 2;
    }

public:
    DynamicArray(int _n) {
        capacity = _n;
        size = 0;
        array = new int [capacity];
    }


    // Метод который кладет значение по индексу
    void set_by_index(int i, int val) {
        if (i > capacity) {
            resize();
        }
        array[i] = val;
    }
    void fill() {
        for (int i = 0; i < capacity; i++) {
            std::cin >> array[i];
        }
    }

    void display() {
        std::cout << "[ ";
        for (int i = 0; i < capacity; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "]";
    }
    ~DynamicArray() {
        delete[] array;
    }
};

int main()
{
    // выделить память под n эл-тов
    DynamicArray* arr = new DynamicArray(5);

    arr->set_by_index(2, 4);
    arr->set_by_index(9, 4);
    arr->display();

    return 0;
}