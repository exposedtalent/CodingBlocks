#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int minStep(int n){

    // base case
    if(n == 1) return 0;

    int op1 = INT_MAX, op2 = INT_MAX;
    if(n%2 == 0){
        op1 = minStep(n/2);
    }
    if(n%3 == 0){
        op2 = minStep(n/3);
    }
    int op3 = minStep(n-1);

    return 1+ min({op1, op2, op3});
}


int minStepTopDown(int n, int* dp){
    // base case
    if(n == 1) return 0;

    //loopup case
    if(dp[n] != -1){
        return dp[n];
    }

    int op1 = INT_MAX, op2 = INT_MAX;
    if(n%2 == 0){
        op1 = minStepTopDown(n/2, dp);
    }
    if(n%3 == 0){
        op2 = minStepTopDown(n/3, dp);
    }
    int op3 = minStepTopDown(n-1, dp);

    return dp[n]+ min({op1, op2, op3});
}

int minStepBottomUp(int n){
    int * dp = new int[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }

    dp[1] = 0;
    for(int i = 2; i <= n; i++){
        int op1 = INT_MAX;
        if(i%2 == 0) op1 = dp[i/2];
        int opt2 = INT_MAX;
        if(i%3 == 0) op2 = dp[i/3];
        int op3  = dp[i-1];

        dp[i] = 1 + min({op1,op2,op3});
    }
    return dp[n];

}


int main(){
    int n = 10;
    cout << minStep(n) << endl;

    int * dp = new int[n+1];
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }

    cout << minStepTopDown(n,dp) << endl;
    cout << minStepBottomUp(n) << endl;


} 