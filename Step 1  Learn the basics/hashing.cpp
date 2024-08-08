#include <bits/stdc++.h>
using namespace std;

// using array
// number hashing using array
void hashing_n(int arr[], int n)
{
    // precompute
    int hash[13] = {0}; //{0} this is given in local scope only and not in global scope if needed to assign 0 to all indices
    int num;
    for (int i = 0; i < n; i++)
    {
        num = arr[i];
        hash[num] += 1;
    }

    int q;
    cin >> q;
    // goes till 0 i.e. false condition
    while (q--)
    {
        int query;
        cin >> query;
        cout << hash[query] << endl;
    }
}

// character hashing using array(only for specified characters)
void hashing_c(string s)
{
    // precompute
    //(char - 'A' or 'a') is required
    int hash[26] = {0};
    char c;
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
        hash[c - 'A'] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << hash[c - 'A'] << endl;
    }
}

// character hashing using array(any characters)
void hashing_u(string s)
{
    // precompute
    int hash[256] = {0};
    char num;
    for (int i = 0; i < s.size(); i++)
    {
        num = s[i];
        hash[num] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
}

// using map
// more effecient way to store number greater than 1e7
void eff_hashing_n(int arr[], int n)
{
    // precompute
    unordered_map<int, int> hash; // unordered used due to TC:O(1)
    int num;
    for (int i = 0; i < n; i++)
    {
        num = arr[i];
        hash[num]++; // value is done ++ for a key
    }

    int q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        cout << hash[query] << endl;
    }

    for (auto it : hash)
    {
        cout << it.first << "->" << it.second << endl;
    }
}
// string hashing using map
void eff_hashing(string s)
{
    unordered_map<char, int> hash;
    // precompute
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // fetch
        cout << hash[c] << endl;
    }

    for (auto it : hash)
    {
        cout << it.first << "->" << it.second << endl;
    }
}

void frequencycount(vector<int> &arr, int N, int P)
{
    // Step 1: Create a hash map to store frequencies.
    unordered_map<int, int> hash;

    // Step 2: Traverse the array and count the frequencies.
    for (int i = 0; i < N; i++)
    {
        if (arr[i] <= N)
        {
            hash[arr[i]]++;
        }
    }

    // Step 3: Modify the original array with the frequencies.
    for (int i = 1; i <= N; i++)
    {
        arr[i - 1] = hash[i];
    }
}

int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // hashing_n(arr, n);
    // eff_hashing_n(arr, n);

    // string s;
    // cin>>s;
    // hashing_u(s);
    // eff_hashing(s);

    // vector<int> arr = {2, 3, 2, 3, 5};
    // int N = arr.size();
    // int P = 5; // Example value for P, not used in the function

    // // Function call
    // frequencycount(arr, N, P);

    // // Output the modified array
    // for (int i = 0; i < N; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}
