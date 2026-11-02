#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>>& grid, int r, int c){
    int m = grid.size();
    int n = grid[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1'){   //stopping base case
        return;
    }
    grid[r][c] = '0';
    dfs(grid, r - 1, c);  //up
    dfs(grid, r + 1, c);  //down
    dfs(grid, r, c - 1);  //left
    dfs(grid, r, c + 1);  //right
}
int numIslands(vector<vector<char>>& grid) {
//number of rows and columns:
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == '1') {
                count++;
                dfs(grid, r, c);
            }
        }
    }
    return count;
}
int main() {
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    cout << "Enter the grid:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int result = numIslands(grid);
    cout << "Output: " << result << endl;
    return 0;
}
