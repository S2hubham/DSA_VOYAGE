#include <bits/stdc++.h>
using namespace std;

// remove k digits
string rem_k_dig(string num, int k)
{
    // edge case 1 : when num == k
    if(num.size() == k) return "0";

    stack<char> st;
    for(int i = 0; i < num.size(); i++){
        while(!st.empty() && st.top() > num[i] && k > 0){
            st.pop();
            k -= 1;
        }
        st.push(num[i]);
    }

    // edge case 2 : if num is in increasing order the remove last k values
    while(k > 0){
        st.pop();
        k -= 1;
    }

    if(st.empty()) return "0";

    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    // edge case 3 : trim all starting zeros
    int lead = 0;
    while (lead < ans.size() && ans[lead] == '0') {
        lead++;
    }
    ans = (lead == ans.size()) ? "0" : ans.substr(lead);


    return ans;

    // TC : O(2n)
    // SC : O(3n)
    // refer book
}

int main()
{
    string num = "1432219";
    string num1 = "10200";
    string num2 = "10";
    string ans = rem_k_dig("0001234", 2);
    cout<<"Smallest number is : "<<ans;
    return 0;
}

// understand the for of solving 