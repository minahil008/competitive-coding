#include <iostream>
using namespace std;
int addDigits(int num){
    if (num == 0){   //handles special case of zero
        return 0;
    }
//this special case is taken cuz formula below breaks for zero

    return 1 + (num - 1) % 9;  //whole algo in single line, no loops needed
}
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int result = addDigits(num);
    cout << "Output: " << result << endl;
    return 0;
}
