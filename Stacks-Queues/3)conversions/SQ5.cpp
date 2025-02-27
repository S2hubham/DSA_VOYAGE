#include <bits/stdc++.h>
using namespace std;

// Postfix to Prefix

void Postfix_Prefix(string exp)
{
    int i = 0;
    stack<string> st;
    while(i < exp.size()){
        char c = exp[i];
        if(isalnum(c)){
            st.push(string(1, c));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string con = c + t2 + t1;
            st.push(con);
        }
        i++;
    }
    cout<<"Prefix -> "<<st.top();
    st.pop();
}

int main() {
    vector<string> test_cases = {
        "abc*+",
        "ab+c*",
        "abcd^e-*+",
        "abc*d/+",
        "abc*d/ef^-g*-h+",
        "ab+cd+*",
        "abc^^",
        "abc*+d+",
        "abc-d+e/*",
        "abc*+d+",
        "abc*d/ef^-g*-h+",
        "hmq74-^^^"
    };
    

    for (const string &exp : test_cases) {
        cout<<"Postfix -> "<<exp<<endl;
        Postfix_Prefix(exp);
        cout << endl << endl;
    }

    return 0;
}
