#include <bits/stdc++.h>
using namespace std;

// celebrity problem
int celebrity(vector<vector<int>> arr)
{
    // brute force
    /* int n = arr.size();
    vector<int> knowsMe(n, 0);
    vector<int> iKnow(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                iKnow[i] += 1;
                knowsMe[j] += 1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(knowsMe[i] == (n-1) && iKnow[i] == 0){
            return i;
        }
    }
    return -1; */

    // TC : O(n^2) + O(n)
    // SC : O(2n)


    // better
    int top = 0;
    int down = arr.size()-1;
    while(top < down){
        if(arr[top][down] == 1){
            top++;
        }
        else if(arr[down][top] == 1){
            down--;
        }
        else{
            top++; 
            down--;
        }
    }

    // if top has exceeded the down the there is no potential celb
    if(top > down) return -1;
    
    // if top == down then check for row and col i.e. iknows == 0 and knowsme == n-1
    for(int i = 0; i < arr.size(); i++){
        if(i == top) continue;
        if(arr[top][i] == 0 && arr[i][top] == 1){

        }
        else{
            return -1;
        }
    }

    return top;

    // TC : O(2n)
    // SC : O(1)
}

int main() {
    vector<vector<int>> arr = {{0, 1, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout<<"celebrity is : "<<celebrity(arr);

    return 0;
}
