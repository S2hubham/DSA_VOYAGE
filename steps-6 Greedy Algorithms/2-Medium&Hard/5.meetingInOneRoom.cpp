#include<bits/stdc++.h>
using namespace std;

// N meeting in one room
struct Data{
    int start;
    int end;
    int pos;
};

bool comparator(Data a, Data b){
    return a.end < b.end;
}

void func(vector<int> start, vector<int> end){
    int n = start.size();
    Data arr[n];

    for(int i = 0; i < n; i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].pos = i+1; 
    }

    sort(arr, arr + n, comparator);

    for (int i = 0; i < n; i++) {
        cout<<"Start: " << arr[i].start<< ", End: " << arr[i].end << ", Pos: " << arr[i].pos << endl;
    }
    cout<<endl;

    int cnt = 1, freetime = arr[0].end;
    vector<int> comp_order;
    comp_order.push_back(arr[0].pos);

    for(int i = 1; i < n; i++){
        if(arr[i].start > freetime){
            cnt++;
            freetime = arr[i].end;
            comp_order.push_back(arr[i].pos);
        }
    }

    cout<<"Number of meting done is : "<<cnt<<endl;
    cout<<"Order of meeting done is -> ";
    for(int i = 0; i < comp_order.size(); i++){
        cout<<comp_order[i]<<" ";
    }

    // TC : O(n + nlogn + n)
    // SC : O(3n) + O(n)
}


int main(){
    vector<int> start = {0, 3, 1, 5, 5, 8};
    vector<int> end = {5, 4, 2, 9, 7, 9};
    func(start, end);
    return 0;
}
