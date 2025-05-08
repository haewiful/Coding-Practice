/*
-- Notes --
> If you are passing a large array to a function, it's better to pass the pointer rather than copying the whole array for just that function. [ex) vector<bool> &visited]
> For large graphs, it's better to use adjacency list than adjacency matrix in terms of space complexity
*/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // make graph (adjacency list)
        vector<vector<int>> graph(n);
        for(vector<int> edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(-edge[0]);
        }

        vector<bool> visited(n, false);
        return dfs(graph, visited, 0);
    }

    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int node) {
        int result = 0;
        visited[node]=true;
        for(int adj : graph[node]) {
            if(!visited[abs(adj)]) {
                if(adj>0) result++;
                result += dfs(graph, visited, abs(adj));
            }
        }
        return result;
    }
};
