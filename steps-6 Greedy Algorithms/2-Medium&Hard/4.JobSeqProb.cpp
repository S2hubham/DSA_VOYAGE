#include<bits/stdc++.h>
using namespace std;

// Job sequencing Problem
bool customComparator(const vector<int>& a, const vector<int>& b) {
    return a[2] > b[2]; 
}


void func(vector<vector<int>> arr){
    // step 1
    sort(arr.begin(), arr.end(), customComparator);
    // sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b) {
    //     return a[2] > b[2];
    // });


    // step 2
    int maxDeadLine = 0, n = arr.size();
    for(int i = 0; i < n; i++){
        maxDeadLine = max(maxDeadLine, arr[i][1]);
    }
    vector<int> newArr(maxDeadLine, -1);

    // step 3
    int maxProf = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        int id = arr[i][0];
        int deadLine = arr[i][1];
        int profit = arr[i][2];

        for(int j = deadLine-1; j >= 0; j--){
            if(newArr[j] == -1){
                newArr[j] = id;
                maxProf += profit;
                cnt++;
                break;
            }
        }
    }

    for(int i = 0; i < newArr.size(); i++){
        cout<<newArr[i]<<" ";
    }
    cout<<endl;

    cout<<"No. of jobs completed : "<<cnt<<endl;

    cout<<"Max Profit is : "<<maxProf;
    return;


    // TC : O(nlogn + n + n * maxDeadLine)
    // SC : O(maxDeadLine)
}


int main(){
    vector<vector<int>> jobs = {  // 2, 127
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 1, 15}
    };    
    vector<vector<int>> jobs1 = {   // 3, 90
        {1, 4, 20},
        {2, 1, 10},
        {3, 2, 40},
        {4, 2, 30}
    };
    vector<vector<int>> jobs2 = {  // 6, 322
        {1, 4, 20},
        {2, 5, 60},
        {3, 6, 70},
        {4, 6, 65},
        {5, 4, 25},
        {6, 2, 80},
        {7, 2, 10},
        {8, 2, 22}
    };
    func(jobs);
    return 0;
}   