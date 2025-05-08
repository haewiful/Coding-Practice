class Solution {
public:
    struct Edge {
        string to;
        double value;
        Edge(string t, double v) : to(t), value(v) {}
    };

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // make graph
        unordered_map<string, vector<Edge>> graph;
        for(int i=0; i<equations.size(); i++) {
            vector<string> e = equations[i];
            Edge edge = Edge(e[1], values[i]);
            graph[e[0]].push_back(edge);
            Edge reverse = Edge(e[0], 1/values[i]);
            graph[e[1]].push_back(reverse);
        }

        vector<double> result;
        for(int i=0; i<queries.size(); i++) {
            vector<string> query = queries[i];
            if(graph.find(query[0])==graph.end() || graph.find(query[1])==graph.end()) {
                result.push_back(-1.0);
            } else if(query[0]==query[1]) {
                result.push_back(1.0);
            } else {
                result.push_back(dfs(query[0], query[1], graph, unordered_map<string, bool>()));
            }
        }

        return result;
    }

    double dfs(string node, string destination, unordered_map<string, vector<Edge>>& graph, unordered_map<string, bool> visited) {
        if(visited[node]) return -1.0;

        // recursive case
        visited[node]=true;
        double result=1.0;
        bool leaf = true;
        for(Edge edge : graph[node]) {
            if(edge.to == destination) {
                return edge.value;
            }
            double tmp = dfs(edge.to, destination, graph, visited);
            if(tmp>0) {
                result *= tmp*edge.value;
                return result;
            }
        }

        return -1.0;
    }
};
