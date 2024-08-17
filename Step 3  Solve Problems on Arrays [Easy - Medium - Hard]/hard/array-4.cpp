#include<bits/stdc++.h>
using namespace std;

// 4 sum problem

// aproach
// 1 - four loops
// 2 - haashing for fourth loop
// 3 - two pointer approach

void four_sum_prob(vector<int> arr, int target){
    // brute force 
    // idea : use four loops
    /* int n = arr.size();
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                for(int l = k+1; l < n; l++){
                    long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
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
    } */
    // TC : ~O(n^4 logm)
    // SC : O(m) one for set and other for list


    // better
    // idea : use hashing for instead of fourth loop declare hashset before third loop and check for fourth element
    /* int n = arr.size();
    set<vector<int>> st;
    // first loop
    for(int i = 0; i < n; i++){
        // second loop
        for(int j = i+1; j < n; j++){
            set<long long> hashset;
            // third loop
            for(int k = j+1; k < n; k++){
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long fourth = target - sum;
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {arr[i], arr[j], arr[k], int(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    } */
    //where N is the size of the input array and M is the number of unique quadruplets
    //TC : ~O(n^3 logm)
    // n^3 for three loop and logm for insertion of quadruplets in set 
    //SC : O(n + m) 
    //n is space used by hashset in inner loop and m is the number of unique quadruplets in set


    // optimal
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1; j < n; j++){
            if(j > i + 1 && arr[j] == arr[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l){
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum < target){
                    k++;
                }
                else if(sum > target){
                    l--;
                }
                else{
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++, l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                }
            }
        }
    }
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
    // TC : O(n^3)
    // SC : O(number of quads)

}

int main(){
    vector<int> arr = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    four_sum_prob(arr, 9);
    return 0;
}