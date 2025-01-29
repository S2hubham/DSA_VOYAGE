#include <bits/stdc++.h>
using namespace std;

// rat in maze
void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[]){
    if(i == n-1 && j == n-1){
        ans.push_back(move);
        return;
    }

    string dir = "DLRU";

    for(int idx = 0; idx < 4; idx++){
        int nexti = i + di[idx];
        int nextj = j + dj[idx];

        if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1){
            vis[i][j] = 1;
            solve(nexti, nextj, m, n, ans, move + dir[idx], vis, di, dj);
            vis[i][j] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n){
    vector<vector<int>> vis(n, vector<int>(n, 0));
    vector<string> ans;
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, +1, 0};
    
    if(m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);

    return ans;
}

int main() {
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<vector<int>> m2 = {{1, 1}, {0, 1}};
    int n = m.size();
    vector<string> ans = findPath(m2, n);

    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
} 