class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()) {
            int room = q.front();
            q.pop();
            for(int key : rooms[room]) {
                if(!visited[key]) {
                    q.push(key);
                    visited[key]=true;
                }
            }
        }
        return all_of(visited.begin(), visited.end(), [](bool b) { return b; });
    }
};
