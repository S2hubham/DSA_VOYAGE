#include <bits/stdc++.h>
using namespace std;
#define SIZE 10


// asteroid collisions
vector<int> asteroid(vector<int> arr){
    vector<int> st;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){
            st.push_back(arr[i]);
        }
        else{
            while(!st.empty() && st.back() > 0 && st.back() < abs(arr[i])){
                st.pop_back();
            }
            if(!st.empty() && st.back() == abs(arr[i])){
                st.pop_back();
            }
            else if(st.empty() || st.back() < 0){
                st.push_back(arr[i]);
            }
        }
    }
    return st;
}

int main(){
    vector<int> arr1 = {4, 7, 1, 1, 2, -3, -7, 17, 15, -19, -20, 70};
    vector<int> arr2 = {4, 7, 1, 1, 2, -3, -7, 17, 15, -19};
    vector<int> arr3 = {4, 7, 1, 1, 2, -3, -7, 17, 15, -19, -30};
    vector<int> arr4 = {4, 7, 1, 1, 2, -3, -7, 17, 15};

    vector<int> ans = asteroid(arr1);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
} 