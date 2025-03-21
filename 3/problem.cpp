#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int x, y, sum{};
    std::cout << "Enter two number";

    if (argc != 3) {
        printf("Invalid number of arguments\n");
        return 1;

    }

    x = atoi(argv[1]);
    y = atoi(argv[2]);

    if (x<y){
        sum = 0;
        while (x<y){
            sum += x;
            x++;
        }
        printf("sum: %d\n", sum);
    }
    
    return 0;
}