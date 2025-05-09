/*
-- Notes --
> Next time, instead of vector<int> using std::pair will be much more better.
	Since we can use something like this
	pair<int, int> [i, j] = q.front();
*/

class Solution {
public:
    int n, m;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> q;
        m = maze.size();
        n = maze[0].size();

        nextPath(maze, q, entrance);
        int result=0;

        int level;
        while(!q.empty()) {
            level = q.size();
            result++;
            for(int i=0; i<level; i++) {
                vector<int> corr = q.front();
                q.pop();
                int row = corr[0];
                int col = corr[1];
                if(row==0 || col==0 || row==m-1 || col==n-1) {
                    return result;
                }
                nextPath(maze, q, corr);
            }
        }
        return -1;
    }

    void nextPath(vector<vector<char>>& maze, queue<vector<int>>& q, vector<int> corr) {
        int row = corr[0];
        int col = corr[1];
        maze[row][col] = '*'; // visited
        if(row>0 && maze[row-1][col]=='.') {
            maze[row-1][col]='*';
            q.push(vector<int>{row-1, col}); // up
        }
        if(row<m-1 && maze[row+1][col]=='.') {
            maze[row+1][col]='*';
            q.push(vector<int>{row+1, col}); // down
        }
        if(col>0 && maze[row][col-1]=='.') {
            maze[row][col-1]='*';
            q.push(vector<int>{row, col-1}); // left
        }
        if(col<n-1 && maze[row][col+1]=='.') {
            maze[row][col+1]='*';
            q.push(vector<int>{row, col+1}); // right
        }
    }
};
