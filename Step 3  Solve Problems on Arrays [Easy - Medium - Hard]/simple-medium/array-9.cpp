#include<bits/stdc++.h>
using namespace std;
// DP on stock
// best time to buy and sell stock

/* void buy_sell(int arr[], int n) {
    int minPrice = arr[0];
    int maxProfit = 0;
    int buyPrice = arr[0];
    int sellPrice = arr[0];

    for (int i = 1; i < n; i++) {
        //check for maximum profit
        if (arr[i] - minPrice > maxProfit) {
            maxProfit = arr[i] - minPrice;
            sellPrice = arr[i];
            buyPrice = minPrice;
        }
        //set minimum price
        if (arr[i] < minPrice) {
            minPrice = arr[i];
            cout << "Bought at " << buyPrice << " sold at " << sellPrice << " with profit " << maxProfit << endl;
        }
    }
    
    cout << "Bought at " << buyPrice << " sold at " << sellPrice << " with profit " << maxProfit << endl;

    // TC : O(n)
    // SC : O(1)
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buy_sell(arr, n);
    return 0;
}
 */

/* 
init
    profit -> 0
    buying price -> arr[0]
    selling price -> arr[0]
    minimum price -> arr[0]

traverse through loop
- if(arr[i] - buy > profit)
    profit = arr[i] - buy
    sell = arr[i]
    buy = minimum price

- if(arr[i] < minimum price)
    minimum price = arr[i]

 */


vector<vector<int>> stockBuySell(vector<int> A, int n) {
    vector<vector<int>> result;
    
    if (n < 2) return result;
    
    int minPriceIndex = 0;
    int i = 1;
    
    while (i < n) {
        // Find Local Minima
        while (i < n && A[i] <= A[minPriceIndex]) {
            i++;
        }
        // If we reached the end
        if (i == n) break;
        
        int buy = minPriceIndex;
        
        // Find Local Maxima
        while (i < n && A[i-1] <= A[i]) {
            i++;
        }

        int sell = i - 1;
        
        result.push_back({buy, sell});
        
        // Update minPriceIndex for the next transaction
        if (i < n) {
            minPriceIndex = i;
        }
    }
    
    return result;

    // TC : O(n)
    // SC : O(1)
}


int main() {
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    vector<vector<int>> result = stockBuySell(prices, n);
    
    if (result.empty()) {
        cout << "No Profit" << endl;
    } else {
        for (auto &transaction : result) {
            cout << "Buy on day: " << transaction[0] << " Sell on day: " << transaction[1] << endl;
        }
    }
    
    return 0;
}

/* 
init : 
    minPriceIndex = 0
    i = 1
traverse through loop i < n
    find local minima (if i < n && arr[i] <= arr[minPriceIndex])
    (if not exist break)
    buyPrice = minPriceIndex
    find local maxima (if i < n && arr[i-1] <= arr[i])
    sellPrice = i-1
    push the pair
    minPrice = i (if i < n)


 */