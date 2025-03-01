#include <bits/stdc++.h>
using namespace std;

// sliding window maximum
vector<int> sliding_window(vector<int> arr, int k)
{
    // brute force
    /* vector<int> wind;
    for(int i = 0; i <= arr.size()-k; i++){
        int maxele = arr[i];
        for(int j = i; j < k+i; j++){
            maxele = max(maxele, arr[j]);
        }
        wind.push_back(maxele);
    }
    return wind; */

    // TC : O(n^2)
    // SC : O(n-k+1)



    // better
    deque<int> dq;
    vector<int> wind;
    for(int i = 0; i < arr.size(); i++){
        if(!dq.empty() && dq.front() <= i - k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.front()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1){
            wind.push_back(arr[dq.front()]);
        }
    }
    return wind;

    // TC : O(2n)  traversal + push/pop
    // SC : O(k) + O(n-k)  dq + wind 
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 2, 1, 6};
    vector<int> ans = sliding_window(arr, 3);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
