#include <bits/stdc++.h>
using namespace std;

// Infix to postfix
int priority(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '-' || c == '+') return 1;
    return -1;
}

bool isRightAssociative(char c){
    return(c == '^');
}

void I_P(string exp)
{
    int i = 0;
    string ans;
    stack<char> st;
    while(i < exp.size()){
        char c = exp[i];
        // if operand add to ans directly
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
            while (!st.empty() && 
                (priority(c) < priority(st.top()) || (priority(c) == priority(st.top()) && !isRightAssociative(c)))) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }

        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout<<"Postfix -> "<<ans;
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
        "h^m^q^(7-4)"
    };

    for (const string &exp : test_cases) {
        cout<<"Infix -> "<<exp<<endl;
        I_P(exp);
        cout << endl << endl;
    }

    return 0;
}


// To handle right associative '^'
/* 
while loop explanation -> 
If the incoming operator (c) has lower precedence than the stack top, pop operators.
If the incoming operator (c) has the same precedence as the stack top:
    Left Associative (like + - * /) → Pop
    Right Associative (like ^) → Do NOT pop, instead push it onto the stack.
*/





/* 

flow : 
Start reading the infix expression character by character.

If the character is an operand (a-z, A-Z, 0-9)
→ Append it directly to the result (postfix expression).

If the character is an opening parenthesis ‘(’
→ Push it onto the stack.

If the character is a closing parenthesis ‘)’
→ Pop from the stack and append to the result until an opening parenthesis ‘(’ is found.
→ Pop and discard the opening parenthesis.

*If the character is an operator (+, -, , /, ^, etc.)
→ While the stack is not empty, check precedence and associativity:

If the operator has lower precedence than the operator on the top of the stack, pop the stack and append to the result.
If the operator has the same precedence as the top of the stack:
If it is left associative (like +, -, *, /), pop the stack and append to the result.
If it is right associative (like ^), do not pop; just push it onto the stack.
→ Push the incoming operator onto the stack.
After processing all characters in the infix expression
→ Pop all remaining operators from the stack and append them to the result.

Print the final postfix expression.

*/