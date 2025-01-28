#include <bits/stdc++.h>
using namespace std;

// kth permutation
string kPermut(int n, int k){
    vector<int> arr;
    string ans;

    k = k - 1;   //due to 0 based indexing
    int fact = 1;
    for(int i = 1; i < n; i++){   // TC : O(n)
        fact = fact * i;
        arr.push_back(i);
    }
    arr.push_back(n);

    while(true){       // TC : O(n^2)  due to erase and append operation
        int idx = k / fact;
        ans += to_string(arr[idx]);
        arr.erase(arr.begin() + idx);
        if(arr.size() == 1){
            ans += to_string(arr[0]);
            return ans;
        }
        k = k % fact;
        fact = fact / arr.size();
    }

    // TC : O(n^2)
}

int main() {
    cout<< kPermut(4, 17)<<endl;
    cout<< kPermut(3, 3);
    return 0;
} 