class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int total=0;
        vector<bool> visited(isConnected.size(), false);
        queue<int> q;
        for(int i=0; i<isConnected.size(); i++) {
            if(visited[i]==false) {
                total++;
                q.push(i);
            }
            while(!q.empty()) {
                int city = q.front();
                q.pop();
                for(int i=0; i<isConnected[city].size(); i++) {
                    if(!visited[i]) {
                        if(isConnected[city][i]==1) {
                            q.push(i);
                            visited[i]=true;
                        }
                    }
                }
            }
        }
        return total;
    }
};
