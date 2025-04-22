#include<bits/stdc++.h>
using namespace std;

// Assign cookies
int satisfied(vector<int> greed, vector<int> s){
    sort(greed.begin(), greed.end());
    sort(s.begin(), s.end());

    int l = 0, r = 0, n1 = greed.size(), n2 = s.size();

    while(l < n2 && r < n1){
        if(s[l] >= greed[r]){
            r++;
        }
        l++;
    }

    return r;

    // TC : O(n log n + m log m + n1 + n2)  for sorting both arrays and traversal
    // SC : O(1)
}


int main(){
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};
    cout<<"Satisfied children are : "<<satisfied(greed, s);
    return 0;
}