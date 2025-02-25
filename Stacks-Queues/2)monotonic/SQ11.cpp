#include <bits/stdc++.h>
using namespace std;

// Maximal rectangle
int func(vector<int> arr)
{
    stack<int> st;
    int maxRowArea = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            int ele = st.top();
            st.pop();
            int nse = i;
            int pse = (!st.empty()) ? st.top() : -1;
            int area = arr[ele] * (nse - pse - 1);
            maxRowArea = max(maxRowArea, area);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int ele = st.top();
        st.pop();
        int nse = arr.size();
        int pse = (!st.empty()) ? st.top() : -1;
        int area = arr[ele] * (nse - pse - 1);
        maxRowArea = max(maxRowArea, area);
    }

    return maxRowArea;
}

void maximal_rect(vector<vector<int>> matrix)
{
    // brute
    vector<vector<int>> arr(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int col = 0; col < matrix[0].size(); col++)
    {
        int ele = 0;
        for (int row = 0; row < matrix.size(); row++)
        {
            ele += matrix[row][col];
            if (matrix[row][col] == 0)
            {
                ele = 0;
            }
            arr[row][col] = ele;
        }
    }

    int maxArea = 0;
    for(int i = 0; i < arr.size(); i++){
        maxArea = max(maxArea, func(arr[i]));
    }

    cout << "Area of rectangle with maxx 1's is : " << maxArea;


    // TC : O(n x m) + O(n x 2m) one for new array, one for histogram
    // SC : O(n x m) + O(m) one for new array, one for stack
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    maximal_rect(arr);
    return 0;
}