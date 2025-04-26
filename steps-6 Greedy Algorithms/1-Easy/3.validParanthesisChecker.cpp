#include<bits/stdc++.h>
using namespace std;

// valid paranthesis string
bool helper_rec(string s, int i, int cnt){
    // base case 
    if(cnt < 0) return false;
    if(i >= s.size()){
        return (cnt == 0);
    }

    if(s[i] == '('){
        return helper_rec(s, i+1, cnt+1);
    }
    else if(s[i] == ')'){
        return helper_rec(s, i+1, cnt-1);
    }
    else{
        return (helper_rec(s, i+1, cnt-1) || helper_rec(s, i+1, cnt+1) || helper_rec(s, i+1, cnt));
    }
}


bool helper_min_max(string s){
    int min = 0, max = 0;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];

        if(c == '('){
            min++;
            max++;
        }
        else if(c == ')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }

        if(min < 0) min = 0;  // make range positive
        if(max < 0) return false;   // starting or contains more ending brackets
    }
    return (min == 0);
}

void func(string s){
    // brute force
    /* if(helper_rec(s, 0, 0)){
        cout<<"Valid paranthesis";
    }
    else{
        cout<<"Invalid paranthesis";
    } */

    // TC : O(3^n)
    // SC : O(n)


    // better 
    if(helper_min_max(s)){
        cout<<"Valid paranthesis";
    }
    else{
        cout<<"Invalid paranthesis";
    }
    
    // TC : O(n)
    // SC : O(1)
}


int main(){
    string s = "(*()";
    string s1 = "(**(";
    func(s1);
    return 0;
}