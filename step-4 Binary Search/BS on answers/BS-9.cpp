#include <bits/stdc++.h>
using namespace std;

// book allocation

int allocation(vector<int> arr, int maxPages){
    int students = 1, pages = 0;
    for(int i = 0; i < arr.size(); i++){
        if((arr[i] + pages) <= maxPages){
            pages += arr[i]; 
        }
        else{
            students += 1;
            pages = arr[i];
        }
    }
    return students;
}

int books(vector<int> arr, int stud)
{  
    // edge case
    int n = arr.size();
    if(n < stud) return -1;    
    
    int maxi = INT_MIN, sum = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    int low = maxi, high = sum; 
    while (low <= high)
    {
        int mid = low + (high - low)/2;
        

        int val = allocation(arr, mid);

        if(val > stud){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
    
    // TC : O(log(sum-maxi) * N)
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24}; 
    cout <<"Minimum no. of pages allocated is : "<< books(arr, 4);
}


/* 



steps :
1 : edge case
2 : find range of maxpages that can be given 
    (if 1 stud then i can give all books i.e. summation(max) and max of array will be maxpages if 1 book for atleast one stud)
3 : find mid(maxpages) and check for no of students we get from that
4 : after getting val if val is less than req stud then we have allocated more pages and we should minimize the mid (reduce high)
                      if val is more than req stud then we have allocated less pages and we should maximize the mid (increase low)


 */