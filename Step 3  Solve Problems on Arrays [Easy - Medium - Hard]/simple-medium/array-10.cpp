#include<bits/stdc++.h>
using namespace std;

// rearrange elements by sign
void rearrange_ele(int arr[], int n){
    // -----brute force
    /* vector<int> pos;
    vector<int> neg;
    for(int i = 0 ; i < n; i++){  //TC : O(n)
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i = 0; i < n/2; i++){  //TC : O(n)
        arr[2*i] = pos[i];
        arr[2*i + 1] = neg[i];
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    // TC : O(n + n/2)
    // SC : O(n) */

    // optimal
    /* vector<int> ans(n, 0);
    int positive = 0, negative = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] < 0){
            ans[negative] = arr[i];
            negative += 2;
        }
        else{
            ans[positive] = arr[i];
            positive += 2;
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<ans[i]<<" ";
    }

    // TC : O(n)
    // SC : O(n) */


    // variety 2 (if they are unequal in size)
    // (fall back to brute force)
    vector<int> pos;
    vector<int> neg;
    // get all elements in positively and negatively divided
    for(int i = 0; i < n; i++){  
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    // rearrange them in ans array
    // if neg array is less in size
    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        int lastIndex = 2 * neg.size();
        for(int i = neg.size(); i < pos.size(); i++){
            arr[lastIndex] = pos[i];
        }
    }
    // if pos array is less in size or both are equal
    else{
        for(int i = 0; i < pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i + 1] = neg[i];
        }
        int lastIndex = 2 * pos.size();
        for(int i = pos.size(); i < neg.size(); i++){
            arr[lastIndex] = neg[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    // TC : O(2n)   (one n for transferring another n for shifting( its for worst case if only poos || neg array is present))
    // SC : O(n)
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rearrange_ele(arr, n);
    return 0;
}

/* 
(for equal neg and pos elements only)
--brute 
maintain two arrays pos and neg 
traverse through array
    if neg element then store it to neg
    else store it to pos
take loop till i < n/2
    at (2*i) position place pos element in arr
    at (2*i+1) position place neg element in arr


----better / optimal
maintain array ans of same size and place 0 at all positions
init:
    positive -> 0
    negative -> 1
traverse through arr 
    if neg element store at negative index in ans and increment negative by 2
    if pos element store at positive index in ans and increment positive by 2

(if it contains unequal elements)
maintain two arrays pos and neg 
traverse through array
    if neg element then store it to neg
    else store it to pos
check whose size is less pos or neg array
    loop till size of small array
    at (2*i) position place pos element in arr
    at (2*i+1) position place neg element in arr
    //for remaining elements
    calculate lastIndex = twice of small array size
    loop from small array size till end and place remaining elements in the ans array


 */