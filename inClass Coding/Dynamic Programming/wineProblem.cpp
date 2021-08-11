/*
    you are given n wines and you can sell the wine from extreme

*/

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& wine, int i, int j, int y){
    
    if(i == j){
        return wine[i] * y;
    }
    // you are in the y'th year, you can sell either the ith wine or the jth wine

    // you sell the ith wine
    int x1 = maxProfit(wine, i+1, j , y+1 );
    // you sell the jth wine
    int x2 = maxProfit(wine, i, j-1, y+1);

    return max(y * wine[i] + x1, y * wine[j] + x2);
}

int maxProfitTopDown(vector<int>& wine, int i, int j, int y, vector<vector<int> >& dp){
    
    if(i == j){
        return dp[i][j] = wine[i] * y;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // you are in the y'th year, you can sell either the ith wine or the jth wine

    // you sell the ith wine
    int x1 = maxProfitTopDown(wine, i+1, j , y+1, dp);
    // you sell the jth wine
    int x2 = maxProfitTopDown(wine, i, j-1, y+1, dp);

    return dp[i][j] = (y * wine[i] + x1, y * wine[j] + x2);
}

int maxProfitBottomUp(vector<int>& wine){
    int n = wine.size();

    vector<vector<int> > dp(n, vector<int>(n));

    for(int i =0; i < n; i++){
        dp[i][i] = n * wine[i];
    }

    for(int i = n-2; i >= 0 ; i --){
        for(int j = i+1; i < n ; i ++){
            
            int y = n - (j -i);
            dp[i][j] = max(wine[i] * y + dp[i+1][j], wine[j]* y + dp[i][j-1]);
        }
    }
    return dp[0][n-1];

}

int main(){

    vector<int> wine;
    wine.push_back(2);
    wine.push_back(3);
    wine.push_back(5);
    wine.push_back(1);
    wine.push_back(4);

    int n = wine.size();
    cout << maxProfit(wine, 0, n-1, 1) << endl;

    vector<vector<int> > dp(n, vector<int>(n,-1));

    cout<< maxProfitTopDown(wine, 0, n-1, 1, dp) << endl;
    cout << maxProfitBottomUp(wine) << endl;

}
