#include<bits/stdc++.h>
using namespace std;


// first and last occuring index

int lowerbound(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int upperbound(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}




int first(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high){
        int mid = (low +high)/2;
        if(arr[mid] == target){
            first = mid;
            high = mid -1;
        }
        else if(arr[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int second(vector<int> arr, int n, int target){
    int low = 0, high = n-1;
    int second = -1;
    while(low <= high){
        int mid = (low +high)/2;
        if(arr[mid] == target){
            second = mid;
            low = mid + 1;
        }
        else if(arr[mid] > target){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return second;
}

vector<int> first_last(vector<int> arr, int n, int target){
    // brute force
    /* int first = -1, last = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == target){
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }
    return {first, last}; */
    // TC : O(n)
    // SC : O(1)


    // optimal(lb and ub)
    /* int lb = lowerbound(arr, n, target);
    if( lb == n || arr[lb] != target){
        return {-1, -1};
    }
    int ub = upperbound(arr, n, target);
    return {lb, ub - 1}; */

    // TC : 2 X O(logn base2)
    // SC : O(1)


    // optimal(pure BS)
    /* int f = first(arr, n, target);
    if(f == -1) return {-1, -1};
    int s = second(arr, n, target);
    return {f, s}; */

    // TC : 2 X O(logn base2)
    // SC : O(1)
}



// find number of occurence along with duplicates
void occ(vector<int> arr, int n, int target){
    int f = first(arr, n, target);
    if(f == -1) cout<<"none";
    int s = second(arr, n, target);
    int occurence = s - f + 1;
    cout<<occurence;
}


int main(){
    vector<int> arr = {8, 9, 10, 12, 12, 12};
    int n = arr.size();
    int x = 8;

    // vector<int> ans = first_last(arr, n, 9);
    // cout << "First: " << ans[0] << ", Last: " << ans[1] << endl;
    occ(arr, n, 12);
}