#include <bits/stdc++.h>
using namespace std;

// Infix to postfix
int priority(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '-' || c == '+') return 1;
    return -1;
}

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

void Infix_Prefix(string exp)
{
    int i = 0;
    string ans;
    stack<char> st;
    string rev = reverse(exp);
    while(i < rev.size()){
        char c = rev[i];
        if(isalnum(c)){
            ans += c;
        }
        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            // even if it is '^' pop if again '^' is encountered (this is diff in pre and post from infix)
            if(c == '^'){
                while (!st.empty() && (priority(c) <= priority(st.top()))) {
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while (!st.empty() && (priority(c) < priority(st.top()))) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }

        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    ans = reverse(ans);

    cout<<"Prefix -> "<<ans;
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

    for (const string &exp : test_cases) {
        cout<<"Infix -> "<<exp<<endl;
        Infix_Prefix(exp);
        cout << endl << endl;
    }

    return 0;
}
