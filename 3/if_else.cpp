#include <iostream>

int main(int argc, char *argv[])
{
    int x{};
    std::cout << "Enter a number";
    std::cin >> x;
    if (x >= 0) {
        std::cout << "you entered a positive integer!" << std::endl;
    } else {
        std::cout << "you entered a negtive integer!" << std::endl;
    }
    
    return 0;
}