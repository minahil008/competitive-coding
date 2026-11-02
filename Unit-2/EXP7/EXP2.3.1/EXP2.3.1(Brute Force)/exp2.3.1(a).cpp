#include <iostream>
using namespace std;
int addDigits(int num){
    while (num >= 10){   //loop till num still has two or more digits
        int total = 0;   //collect the digit sum
        while (num > 0){
            total += num % 10;   //dividing by 10 leaves the last digit as the remainder
            num /= 10;   //chops off the last digit by leaving after decimal part
        }
        num = total;
    }
    return num;
}
int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int result = addDigits(num);
    cout << "Output: " << result << endl;
    return 0;
}
