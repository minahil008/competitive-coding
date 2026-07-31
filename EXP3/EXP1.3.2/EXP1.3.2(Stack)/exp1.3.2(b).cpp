#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int largestRectangleArea(vector<int> heights){  //no & bcz creating copy here
    heights.push_back(0);  //sentinel (fake value to have clean ending) value = 0 (bcz 0 is smaller than any other height) (makes sure after it reaches here, pop everything)
    stack<int> stk;  //empty stack for bar indices
    int max_area = 0;  //biggest area found so far
    int n = heights.size();
    for (int i = 0; i < n; i++){   //walk through every bar + the sentinel one at a time
        while (!stk.empty() && heights[i] < heights[stk.top()]){  //current bar is shorter than the top of stack
            int h_idx = stk.top();
            stk.pop();
            int left_boundary = stk.empty() ? -1 : stk.top();  //after popping, the now top bar is nearest to the bar popped on the left (-1=>one index before 0)
            int width = i-left_boundary-1;  //bars strictly between these ends  //i(shortest to right), left_boundary(shortest to left)
            max_area = max(max_area, heights[h_idx] * width);
        }
        stk.push(i);
    }
    return max_area;
}
int main(){
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the bar heights: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int result = largestRectangleArea(heights);
    cout << "Output: " << result << endl;
    return 0;
}
