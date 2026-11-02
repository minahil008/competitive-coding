#include <iostream>
#include <stack>
using namespace std;
class Queue{
private:
    stack<int> s1;   //incoming stack: will hold integers
    stack<int> s2;   //outgoing stack: elements are removed from here
public:
    void push(int x){
        s1.push(x);   //push x to s1
    }
    int pop(){
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());  //take top of s1 and push into s2
                s1.pop();
            }
        }
        int val = s2.top();  //if s2 is not empty
        s2.pop();
        return val;
    }
    int peek(){  //same as pop
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty(){
        return s1.empty() && s2.empty();  //if both stacks are empty
    }
};
int main() {
    Queue q;
    int choice;
    while (true) {
        cout << "1.Push\t";
        cout << "2.Pop\t";
        cout << "3.Peek\t";
        cout << "4.Empty\t";
        cout << "5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            int x;
            cout << "Enter value to push: ";
            cin >> x;
            q.push(x);
            cout << "Pushed " << x << endl;
        }
        else if (choice == 2) {
            if (q.empty()) {
                cout << "Queue is empty, cannot pop.\n";
            } else {
                cout << "Popped: " << q.pop() << endl;
            }
        }
        else if (choice == 3) {
            if (q.empty()) {
                cout << "Queue is empty, cannot peek.\n";
            } else {
                cout << "Front: " << q.peek() << endl;
            }
        }
        else if (choice == 4) {
            cout << "Is empty: " << (q.empty() ? "true" : "false") << endl;
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice, try again.\n";
        }
    }
    return 0;
}
