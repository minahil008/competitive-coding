#include <iostream>
#include <vector>
#include <algorithm>  //Gives min() and max() functions
using namespace std;
int largestArea(vector<int> & heights){  //array of bar heights
    int n = heights.size();
    int max_area = 0;  //largest(best) rectangle area found
    for (int i = 0; i < n; i++){  //from starting bar
        int min_h = heights[i];   //min_h=>min. height so far rest to heights[i] bcz only one bar is present right now (==min)
        for (int j = i; j < n; j++){  //goes right one bar at a time
            min_h = min(min_h, heights[j]);   //keeps the shorter bar (old min or new bar)
            max_area = max(max_area, min_h * (j-i+1));  // min_h = height,(j-i+1) = width of rectangle (+1 for endpoints) => area=height*width
        }
    }
    return max_area;
}
int main(){
    int n;
    cout << "Enter number of bars: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter the bar heights: ";
    for (int i = 0; i < n; i++){
        cin >> heights[i];
    }
    int result = largestArea(heights);
    cout << "Output: " << result << endl;
    return 0;
}
