#include <iostream>
#include <vector>
#include <string>
#include <algorithm>   //stores func. like max()
using namespace std;
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        //128 as standard ascii has 128
        vector<int> lastSeen(128, -1);  // //stores the last char
        int maxLen = 0;    //max. substring length
        int start = 0;     //starting index of curr window
        for (int end = 0; end < (int)s.size(); end++){   //goes through string char by char
            char c = s[end];   //gets char at end pos.
            if (lastSeen[c] >= start){   //checks for duplicate
                start = lastSeen[c] + 1;  //move start
            }
            lastSeen[c] = end;  //stores curr. pos as char's last occurence
            maxLen = max(maxLen, end - start + 1);  //calculates curr window length
        }
        return maxLen;
    }
};
int main(){
    Solution obj;
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "Length of longest substring: "
         << obj.lengthOfLongestSubstring(s);
    return 0;
}
