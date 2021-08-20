/* 
    You are given a coins with denomination find the min change you need to given

    ex : coins[] = [1,7,10]  target = 15
    ans  : 7
*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minCoin(vector<int>& coins, int n){

    int minC = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(n-coins[i] >= 0){
            minC =  min(minC, minCoin(coins, n-coins[i]));
        } 
    }
    return minC == INT_MAX ? minC : 1 + minC;

}

int minCoinTopDown(vector<int>& coins, int n, vector<int>& dp){

    if(n == 0) return dp[n] = 0;

    if(dp[n] != -1) return dp[n];

    int minC = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(n-coins[i] >= 0){
            minC =  min(minC, minCoinTopDown(coins, n-coins[i], dp));
        } 
    }
    int ans = minC == INT_MAX ? minC : 1 + minC;
    return dp[n] == ans;

}

int minConBottomUp(vector<int>& coins, int n){
    vector<int>dp(n+1);
    dp[0] = 0;

    for(int j = 1; j <= n;j++){
        // dp[i] = f(i) = min num of coins required to get the change 
        int minC = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            if(j-coins[i] >= 0){
                minC =  min(minC, dp[j-coins[i]]);
            }    
        }
        dp[j] = minC == INT_MAX ? minC : 1+ minC;
    }
    return dp[n];
}
int main(){
    vector<int> coins;
    coins.push_back(1); //
    coins.push_back(7); //
    coins.push_back(10); //
    int n = 15;

    vector<int> dp(n+1, -1);

    cout << minConBottomUp(coins, n);

    minCoin(coins, n);
}