#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c){
    int m = grid.size();     //number of rows
    int n = grid[0].size();   //number of columns
/*r < 0: above the top edge
r >= m: below the bottom edge
c < 0; left of the left edge
c >= n: right of the right edge*///:
    if (r < 0 || r >= m || c < 0 || c >= n) return;
/*visited[r][c]: been here already
grid[r][c] == '0': this cell is water*///:
    if (visited[r][c] || grid[r][c] == '0') return;
    visited[r][c] = true;
    dfs(grid, visited, r - 1, c);  //up
    dfs(grid, visited, r + 1, c);  //down
    dfs(grid, visited, r, c - 1);   //left
    dfs(grid, visited, r, c + 1);  //right
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int count = 0;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {  //scan
            if (grid[r][c] == '1' && !visited[r][c]) {   //this cell is land AND hasn't visited it yet
                dfs(grid, visited, r, c);
                count++;
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
