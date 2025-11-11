#include <iostream>

void countdown(int n) {
    if (n == 0) {
        std::cout << "Stop!" << std::endl;
        return;
    }
    std::cout << n << std::endl;
    countdown(n - 1);
}

int main()
{
    countdown(3);
    return 0;
}
