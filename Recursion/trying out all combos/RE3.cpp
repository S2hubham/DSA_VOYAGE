#include <bits/stdc++.h>
using namespace std;

// palindrome partitioning
bool isValid(string str, int start, int end){
    while(start < end){
        if(str[start] != str[end])  return false;
        start++, end--;
    }
    return true;
}

void func(string str, vector<vector<string>> &ans, vector<string> &temp, int idx){
    // base case
    if(idx == str.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = idx; i < str.size(); i++){
        if(isValid(str, idx, i)){
            temp.push_back(str.substr(idx, i-idx+1));
            func(str, ans, temp, i+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>> palid_parti(string str) {
    vector<vector<string>> ans;
    vector<string> temp;
    func(str, ans, temp, 0);
    return ans;
} 

int main() {
    string str = "aabb";
    vector<vector<string>> ans = palid_parti(str);
    for (int i = 0; i < ans.size(); i++){
        if (ans[i].empty()){                 
            cout << "{}"; 
        }
        else{
            for (int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
} 