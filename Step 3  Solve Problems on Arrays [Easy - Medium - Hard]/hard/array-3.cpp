#include <bits/stdc++.h>
using namespace std;

// 3 sum problem

// approach
// 1 - three loops
// 2 - haashing for third loop
// 3 - three pointer approach


void three_sum_prob(vector<int> arr){
    // brute force
    //idea : get all triplets by three loops 
    /* set<vector<int>> st;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);   //TC : O(log n)
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }

    // TC : O(n^3)
    // SC : O(2 * number of triplets) */


    // better
    // idea : instead of third loop do hashing and store middle elements of i and j and check for arr[k] = -(arr[i] + arr[j])
    /* set<vector<int>> st;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        set<int> hashset;
        for(int j = i+1; j < n; j++){
            int third = -(arr[i] + arr[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {arr[i], arr[j], third}; // SC : O(no. of unique triplets)
                sort(temp.begin(), temp.end());
                st.insert(temp);   //TC : O(log n)
            }
            hashset.insert(arr[j]); // SC : O(n)
        }
    

    vector<vector<int>> ans(st.begin(), st.end()); // SC : O(no. of unique triplets)
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
    // TC : O(n^2 + log m)
    // SC : O(n) + O(2 x no. of unique triplets) */


    // optimal 
    // idea : same as above but sort the full array at start and keep three pointer start middle end
    /* vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());  // TC : O(nlogn)
    for(int i = 0; i < n; i++){    // TC : O(n)
        if(i > 0 && arr[i] == arr[i-1]){
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k){    // TC : ~O(n)
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k +1]) k--;
            }
        }
    }

    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    } */
    // TC : O(2n) + O(nlogn)
    // SC : O(number of unique triplets)

}

int main(){
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    three_sum_prob(arr);
    return 0;
}