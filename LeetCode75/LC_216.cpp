class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return comb(vector<bool>(10, false), k, n);
    }

    vector<vector<int>> comb(vector<bool> visited, int k, int n) {
        // base case
        vector<vector<int>> result;
        if(k==0 || n==0) return result;

        // recursive case
        // for each 1~n, i
            // if i is not visited, find all combination of k-1, n-i
            // add the result to the final result & make that i visited onwards
        for(int i=9; i>0; i--) {
            if(!visited[i]) {
                if(k==1 && i==n) {
                    vector<int> tmp(1, i);
                    result.push_back(tmp);
                    return result;
                }
                visited[i]=true;
                vector<vector<int>> tmp_r = comb(visited, k-1, n-i);
                for(vector<int> t : tmp_r) {
                    t.push_back(i);
                    result.push_back(t);
                }
            }
        }
        
        return result;
    }
};
