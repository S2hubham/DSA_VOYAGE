#include <bits/stdc++.h>
using namespace std;

// onilne stock span problem
class StockSpanner{
    vector<int> arr;
    stack<pair<int, int>> st;
    int ind = -1;

public:
    StockSpanner(){
        // arr = {};
        ind = -1;
    }

    /* int next(int val){
        arr.push_back(val);
        int count = 1;
        for(int i = arr.size()-2; i >= 0; i--){
            if(arr[i] <= val){
                count++;
            }
            else{
                break;
            }
        }
        return count;
    } */


    int next(int val){
        ind = ind + 1;
        while(!st.empty() && st.top().first <= val){
            st.pop();
        }
        int span = ind - ((!st.empty()) ? st.top().second : -1);
        st.push({val, ind});
        return span;
    }
};


vector<int> online_stock(vector<int> arr)
{
    // brute force
    /* StockSpanner sp;
    vector<int> span = {};
    for(int i = 0; i < arr.size(); i++){
        ans.push_back(sp.next(arr[i]));
    }
    return span; */

    // TC : O()
    // SC : O()


    // better 
    StockSpanner sp;
    vector<int> span = {};
    for(int i = 0; i < arr.size(); i++){
        span.push_back(sp.next(arr[i]));
    }
    return span;

    // TC : O(2n)
    // SC : O(n)
}

int main() {
    vector<int> arr = {7, 2, 1, 3, 3, 1, 8};
    vector<int> ans = online_stock(arr);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
