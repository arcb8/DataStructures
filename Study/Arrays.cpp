#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            arr[i][j] = rand() % 10;
            std::cout << arr[i][j]  << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i == j) {
                std::cout << arr[i][j] << " ";
            }
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}