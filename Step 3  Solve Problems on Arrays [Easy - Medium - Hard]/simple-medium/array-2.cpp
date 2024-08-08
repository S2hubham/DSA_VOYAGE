#include <bits/stdc++.h>
using namespace std;

// left rotate the array by one place
void l_rotate(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // TC : O(n)  due to for loop
    // SC : O(1)  due to temp (extra space)
    //  O(n)  due to array used
}

void Reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// left rotate the array by D place
void l_d_rotate(int arr[], int n, int d)
{
    // d = d % n; //take d in multiples of n

    // int temp[d];
    // //transferring d elements //TC : O(d)
    // for(int i = 0; i < d; i++){
    //     temp[i] = arr[i];
    // }

    // //shifting by d places   //TC : O(n-d)
    // for(int i = d; i < n; i++){
    //     arr[i - d] = arr[i];
    // }

    // //re-transsferring     //TC : O(d)
    // for(int i = n-d; i < n; i++){
    //     arr[i] = temp[i - (n-d)];
    // }

    // for(int i = 0; i < n; i++){
    //     cout<<arr[i]<<" ";
    // }

    // TC : O(n+d)
    // SC : O(d)  due to shifting of d elements in temp array

    // optimal to reduce SC
    d = d % n;
    Reverse(arr, 0, d - 1);
    Reverse(arr, d, n - 1);
    Reverse(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // TC : O(2n)
    // SC : O(1)
}

// right shift
void r_d_rotate(int arr[], int n, int d)
{
    d = d % n;
    Reverse(arr, 0, d - 1);
    Reverse(arr, d, n - 1);
    Reverse(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// shifting zeros to end
void shift(int arr[], int n)
{
    //----brute force
    /*
    //step-1
    vector<int> temp;
    for(int i = 0; i < n; i++){  // TC : O(n)
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    //step-2
    for(int i = 0; i < temp.size(); i++){   // TC : O(x)
        arr[i] = temp[i];
    }
    //step-3
    for(int i = temp.size(); i < n; i++){   // TC : O(n-x)
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }*/

    // TC : O(2n)
    // SC : O(x)

    // ----optimal in terms of space and time

    // step-1 check for zero is present or not
    /*int j = -1;
    for(int i = 0; i < n; i++){ //TC : O(x)
        if(arr[i] == 0){
            j = i;
            break;
        }
    }

    if(j == -1) return;
    //step-2 start swapping
    //(j points to 0 and i points to numbers)
    for(int i = j+1; i < n; i++){   //TC :O(n-x)
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }*/

    // TC : O(n)
    // SC : O(1)  as no extra space is taken than the same array
}
//NOTE : implementation of binary search should be done here for sorted array
void linear_search(int arr[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            cout << "found";
            return;
        }
    }
    cout << "not found";
    return;
}

// union and intersection
vector<int> Uni(vector<int> a, vector<int> b)
{
    //----brute force

    /* int n1 = a.size();
    int n2 = b.size();
    set<int> temp;
    for(int i = 0; i < n1; i++){  //TC : O(n1 logn)
        temp.insert(a[i]);
    }
    for(int i = 0; i < n2; i++){  //TC : O(n2 logn)
        temp.insert(b[i]);
    }
    vector<int> uni;
    for(auto it : temp){          //TC : O(n1 + n2)
        uni.push_back(it);
    }
    return uni; */

    // TC : O(n1 logn + n2 logn) + O(n1 + n2)
    // SC : O(n1 + n2) + O(n1 + n2)  //temp + uni(to return ans)

    //-----optimal
    int n1 = a.size();
    int n2 = b.size();
    vector<int> uni;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (uni.size() == 0 || uni.back() != a[i]) // if size is zero or if it is unique element
            {
                uni.push_back(a[i]);
            }
            i++;
        }
        else    
        {
            if (uni.size() == 0 || uni.back() != b[j]) // if size is zero or if it is unique element
            {
                uni.push_back(b[j]);
            }
            j++;
        }
    }
    // when second array gets emptied
    while (i < n1)
    {
        if (uni.size() == 0 || uni.back() != a[i]) // if size is zero or if it is unique element
        {
            uni.push_back(a[i]);
        }
        i++;
    }
    // when first array gets emptied
    while (j < n2)
    {
        if (uni.size() == 0 || uni.back() != b[j]) // if size is zero or if it is unique element
        {
            uni.push_back(b[j]);
        }
        j++;
    }
    return uni;

    //TC : O(n1 + n2) as only iterating through two arrays only
    //SC : O(n1 + n2) used to return the solution
}

//intersection of elements in arrays
vector<int> intersect(vector<int> a, vector<int> b){
    //---brute force 
    /*int n1 = a.size();
    int n2 = b.size();
    int visit[n2] = {0};
    vector<int> ans;
    //loop for each element of first array
    for(int i = 0; i < n1; i++){
        //loop for checking with second array elements
        for(int j = 0; j < n2; j++){
            if(a[i] == b[j] && visit[j] == 0){
                ans.push_back(a[i]);
                visit[j ] = 1;
                break;
            }
            //as array is sorted if greater number is found then break
            if(b[j] > a[i]){
                break;
            }
        }
    }
    return ans;*/

    //TC : O(n1 * n2)
    //SC : O(n2)  in this case


    //optimal due n1*n2 TC
    /*int n1 = a.size();
    int n2 = b.size();
    int i = 0; 
    int j = 0;
    vector<int> ans;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){ //take i to correct position to reduce comparisions
           i++; 
        }
        else if(b[j] < a[i]){ //take i to correct position to reduce comparisions
            j++;
        }
        //then compare
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;*/

    //TC : O(n1 + n2)
    //SC : O(1)
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // l_rotate(arr, n);
    // l_d_rotate(arr, n, 2);
    // shift(arr, n);
    // linear_search(arr, n, 40);

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {4, 5, 6, 7, 8};

    // vector<int> result = Uni(a, b);
    vector<int> result = intersect(a, b);

    cout << "Intersection of a and b is: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}