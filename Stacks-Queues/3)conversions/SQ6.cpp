#include <bits/stdc++.h>
using namespace std;

// Prefix to Postfix 
void Prefix_Postfix(string exp)
{
    int i = exp.size()-1;
    stack<string> st;
    while(i >= 0){
        char c = exp[i];
        if(isalnum(c)){
            st.push(string(1, c));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string con = t1 + t2 + c;
            st.push(con);
        }
        i--;
    }
    cout<<"Postfix -> "<<st.top();
    st.pop();
}

int main() {
    vector<string> test_cases = {
        "+a*bc",
        "*+abc",
        "+a*b-^cde",
        "+a/*bcd",
        "+-a*-/*bcd^efgh",
        "*+ab+cd",
        "^a^bc",
        "++a*bcd",
        "*/-abcde",
        "++a*bcd",
        "+-a*-/*bcd^efgh",
        "^h^m^q-74"
    };    

    for (const string &exp : test_cases) {
        cout<<"Prefix -> "<<exp<<endl;
        Prefix_Postfix(exp);
        cout << endl << endl;
    }

    return 0;
}
