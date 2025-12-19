#include <iostream>

int main()
{
    int target;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    size_t size = sizeof(A) / sizeof(A[0]);
    std::cout << "Enter the number:\n";
    std::cin >> target;
    for (int i = 0; i < size; i++) {
        if (target == A[i]) {
            // std::cout << "Number is found";
        }
    }

    int l = 0;
    int r = size - 1;
    while (l < r) {
        int mid = (l + r) / 2;

        if (A[mid] == target) {
            std::cout << "Number is found";
            break;
        }

        if (A[mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return 0;
}