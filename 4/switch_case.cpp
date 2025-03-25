#include <iostream>
using namespace std;
int main(int argc, char *argv[]){
    int x{};
    cout << "Enter Number: ";
    cin >> x;

    switch (x) {
        case 1:
        cout << "You entered 1" << endl;
        break;

        case 1:
        cout << "You entered 2" << endl;
        break;

        default:
        cout << "You entred unknown number" << endl;
    }
    return 0;

}