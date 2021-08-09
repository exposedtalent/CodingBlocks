#include<iostream>

using namespace std;
int fibTopDown(int n, int* dp){

    // base case 
    if(n==0 || n == 1) return dp[n] = n;

    // Loookup
    if(dp[n] != -1){
        //  you already saw this so just return the prev result
        return dp[n];
    }
    // you have not yet solved the f(n)
    return dp[n] = fibTopDown(n-1, dp) + fibTopDown(n-2,dp);
}
int fibo(int n){
    if(n ==0 || n ==1) return n;

    return fibo(n-1) + fibo(n-2);
}

int fiboBottomUp(int n){
    if(n ==0 || n == 1) return n;
    
    int *dp = new int[n+1];
    for(int i = 0; i <= n;i++){
        dp[i] = -1;
    }

    dp[0] = 0;
    dp[1] =1 ;
    for(int i  = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
// BEST PROGRAM TC : O(n), SC : O(1)
int fiboBottomUpSpaceOptmizer(int n){

    if(n ==0 || n == 1) return n;

    int a = 0, b =1;

    for(int i  = 2; i <= n; i++){
        int c = b + a;
        a = b;
        b = c;
    }
    return b;
}
int main(){

    int n  = 42;
    int *dp = new int[n+1];
    for(int i = 0; i <= n;i++){
        dp[i] = -1;
    }
    cout << fiboBottomUp(n) << endl;
    cout << fiboBottomUpSpaceOptmizer(n) << endl;
    cout << fibTopDown(n, dp) << endl;
    // cout << fibo(n) << endl;

}