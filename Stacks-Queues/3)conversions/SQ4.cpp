#include <bits/stdc++.h>
using namespace std;

// Prefix to Infix
string reverse(string s){
    string rev;
    for(int i = s.size()-1; i >= 0; i--){
        char c = s[i];
        if(isalnum(c)){
            rev += c;
        }
        else if(c == '('){
            rev += ')';
        }
        else if(c == ')'){
            rev += '(';
        }
        else{
            rev += c;
        }
    }
    return rev;
}

void Prefix_Infix(string exp)
{
    int i = 0;
    stack<string> st;
    string rev = reverse(exp);
    while(i < rev.size()){
        char c = rev[i];
        if(isalnum(c)){
            st.push(string(1, c));
        }
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string con = "(" + t1 + c + t2 + ")";
            st.push(con);
        }

        i++;
    }
    rev = st.top();
    st.pop();
    // rev = reverse(rev);

    cout<<"Prefix -> "<<rev;
}

int main() {
    vector<string> test_cases = {
        "a+b*c",
        "(a+b)*c",
        "a+b*(c^d-e)",
        "a+b*c-d/e",
        "a+(b*c-(d/e^f)*g)*h",
        "(a+b)*(c+d)",
        "a^b^c",
        "a+b-c*d/e",
        "(a+b-c)*(d/e)",
        "a+b*c+d",
        "a+(b*c-(d/e^f)*g)*h",
        "h^m^q^(7-4)"
    };

    // for (const string &exp : test_cases) {
    //     cout<<"Infix -> "<<exp<<endl;
    //     Infix_Prefix(exp);
    //     cout << endl << endl;
    // }

    Prefix_Infix("++a*bcd");

    return 0;
}
