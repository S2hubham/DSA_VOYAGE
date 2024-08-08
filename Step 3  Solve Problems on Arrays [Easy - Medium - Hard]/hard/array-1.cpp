#include<bits/stdc++.h>
using namespace std;

// pascal's triangle
// type 1 : find element from row and col
long long nCr(int row, int col){
    long long res = 1;

    for(int i = 0; i < col; i++){
        res = res * (row - i);
        res = res / (i + 1);
    }
    return res;
}

// type 2 : print thw whole row
vector<int> row(int N){
    vector<int> ans;
    for(int i = 1; i <= N; i++){
        ans.push_back(nCr(N - 1, i - 1));
    }
    return ans;
}


// type 3 : whole pascal triangle 
void pascal_triangle(int N){
    vector<vector<int>> ans;
    for(int i = 1; i <= N; i++){
        ans.push_back(row(i));
    }
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele << " ";
        }
        cout<<"\n";
    }
}


int main(){
    // nCr(5, 3);
    // row(5);
    pascal_triangle(5);

    return 0;
}