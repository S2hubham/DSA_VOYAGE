#include <bits/stdc++.h>
using namespace std;

// postfix to infix
void postfix_Infix(string exp)
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
            string con = "(" + t2 + c + t1 + ")";
            st.push(con);
        }
        i++;
    }

    cout<<"Infix -> "<<st.top();
}

int main() {
    vector<string> test_cases = {
        "ab+c*",        
        "ab*c+",        
        "abcd-*+",      
        "abc^de-fg*/-h*", 
        "ab+cd+*",      
        "abc^^",        
        "abc*d/-e+",    
        "abc-+de/*",    
        "abc*+d+",      
        "abc^d/e-fg*-h*", 
        "hmq74-^^^",     
    };

    for (const string &exp : test_cases) {
        cout << "Postfix -> " << exp << endl;
        postfix_Infix(exp);
        cout << endl << endl;
    }

    return 0;
}

