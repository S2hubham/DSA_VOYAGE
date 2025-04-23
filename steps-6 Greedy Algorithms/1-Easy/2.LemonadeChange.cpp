#include<bits/stdc++.h>
using namespace std;

// Lemonade change
bool func(vector<int> bills){
    int five = 0, ten = 0;  // no need to have twenty as we are not returning it
    for(int i = 0; i < bills.size(); i++){
        int cash = bills[i];
        if(cash == 5){
            five += 1;
        }
        else if(cash == 10){
            if(five){
                five -= 1;
                ten += 1;
            }
            else{
                return false;
            }
        }
        else{
            if(five && ten){
                five -= 1;
                ten -= 1;
            }
            else if(five >= 3){
                five -= 3;
            }
            else{
                return false;
            }
        }
    }
    return true;

    // TC : O(n)
    // SC : O(1)
}


int main(){
    vector<int> bills = {5, 5, 5, 10, 20};
    vector<int> bills1 = {5, 5, 10, 10, 20};
    if(func(bills1)){
        cout<<"All customers satisfied";
    }
    else{
        cout<<"Not satisfied";
    }
    return 0;
}