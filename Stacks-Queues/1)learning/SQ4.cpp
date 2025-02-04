#include <bits/stdc++.h>
using namespace std;
#define SIZE 10


// balanced paranthesis
bool bal_par(string s){
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(c == '{' || c == '[' || c == '('){
            st.push(c);
        }
        else{
            if(st.empty()) return false;
            char x = st.top();
            if((c == ']' && x == '[') || (c == '}' && x == '{') || (c == ')' && x == '(')){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();

    // TC : O(n)
    // SC : O(n)
}


int main(){
    string str1 = "()[{}()]";      // balanced
    string str2 = "()[{}(])";      // unbalanced
    if(bal_par("))))))))))))")){
        cout<<"Balanced paranthesis";
    }
    else{
        cout<<"Unbalanced paranthesis";
    }
    return 0;
}