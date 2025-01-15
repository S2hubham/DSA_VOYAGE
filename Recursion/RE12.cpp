#include <bits/stdc++.h>
using namespace std;

//  return all subsequences 

void func(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int i, int n)
{
    if (i == n) 
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[i]);
    func(nums, temp, ans, i + 1, n);
    temp.pop_back();
    func(nums, temp, ans, i + 1, n);

    // TC : O(n/2 * 2^n) ~= O(n * 2^n)
    // SC : O(n * 2^n)
}


vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> temp;
    func(nums, temp, ans, 0, nums.size());
    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<vector<int>> ans = subsets(arr);

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].empty())
        {                 
            cout << "{}"; 
        }
        else
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}



/* 

SC : The ans vector stores all subsets. Since there are 2^𝑛 subsets, and each subset has an average size of O(n/2), the total space is O(n * 2^n)

TC : The ans vector stores all subsets. Since there are 2^𝑛 calls, and each subset has an average size of O(n/2), the total time req is O(n * 2^n)

 */