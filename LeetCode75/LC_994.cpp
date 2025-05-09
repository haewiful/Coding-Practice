class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes=0;
        int oranges=0;

        queue<pair<int,int>> q;
        // add rotten orange to queue
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==2) {
                    q.push(pair(i, j));
                } else if(grid[i][j]==1) oranges++;
            }
        }

        if(oranges==0) return 0;

        while(!q.empty()) {
            int level = q.size();
            minutes++;
            for(int i=0; i<level; i++) {
                auto [row, col] = q.front();
                q.pop();
                oranges-= addNext(grid, q, row, col);
                if(oranges==0) return minutes;
            }
        }
        return -1;
    }

    int addNext(vector<vector<int>>& grid, queue<pair<int,int>>& q, int i, int j) {
        int count=0;
        if(i>0 && grid[i-1][j]==1) { // up
            q.push(pair(i-1, j));
            grid[i-1][j]=2;
            count++;
        }
        if(i<grid.size()-1 && grid[i+1][j]==1) { // down
            q.push(pair(i+1, j));
            grid[i+1][j]=2;
            count++;
        }
        if(j>0 && grid[i][j-1]==1) { // left
            q.push(pair(i, j-1));
            grid[i][j-1]=2;
            count++;
        }
        if(j<grid[0].size()-1 && grid[i][j+1]==1) { // right
            q.push(pair(i, j+1));
            grid[i][j+1]=2;
            count++;
        }
        return count;
    }

};
