class Solution {
public:

    int m, n;

    void sink(vector<vector<char>>& grid, int r, int c){
        if ( r<0 || c<0 || r>=m || c>=n || grid[r][c] == '0') return;
        
        grid[r][c] = '0';

        sink(grid, r+1, c);
        sink(grid, r-1, c);
        sink(grid, r, c+1);
        sink(grid, r, c-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int  islands = 0;
        m = grid.size();
        n = grid[0].size();

    
        for (int r=0; r<m; r++){
            for (int c=0; c<n; c++){
                if (grid[r][c] == '1'){
                    islands++;
                    sink(grid, r, c);
                }
            }
        }

        return islands;
    }
};


/*
Approach:
- Treat the grid as a graph where each cell is a node.
- An island = a group of horizontally/vertically connected '1's.
- Traverse every cell in the grid.
- When a '1' is found, increment island count.
- Run DFS from that cell to visit all connected land.
- During DFS, mark visited land cells as '0' to avoid recounting.
- Each DFS call removes one full island.

Time Complexity: O(m × n)

Space Complexity: O(m × n) worst case
*/
