#include <iostream>

int main()
{
    int n = 5;

    // |\

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    // /|

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j <= n - i - 1) {
                std::cout << " ";
            }
            else {
                std::cout << "*";
            }
        }
        std::cout << "\n";
    }

    // /\

    n = 7;

    for (int i = n/2; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= n - i - 1 && i >= j) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    // \/

    n = 7;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= n - i - 1 && i <= j) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
    return 0;
}

