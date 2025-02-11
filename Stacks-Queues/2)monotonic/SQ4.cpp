#include <bits/stdc++.h>
using namespace std;


// Number of NGEs to the right 
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
    // brute
    /* vector<int> nges(queries, 0);
    for (int i = 0; i < queries; i++) {
        int idx = indices[i];
        int cnt = 0;
        for (int j = idx + 1; j < arr.size(); j++) {
            if (arr[idx] < arr[j]) {
                cnt++;
            }
        }
        nges[i] = cnt;
    }
    return nges; */
}

int main() {
    int n, queries;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> queries;
    vector<int> indices(queries);
    for (int i = 0; i < queries; i++) {
        cin >> indices[i];
    }

    vector<int> result = count_NGE(n, arr, queries, indices);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
