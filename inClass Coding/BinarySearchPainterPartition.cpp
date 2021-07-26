// https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<algorithm>
using namespace std;
// mid  = s + e / 2

int numPainter(int n, int* len, int tl){
    int numPainter = 1;
    int time = 0;
    for(int i =0; i < n;i ++){
        //  paint the ith board
        time += len[i];
        if(time> tl){
            //  aadd another painter to the job
            numPainter++;
            // this paaiter needs to resstaart painting the ith board
            time  = len[i];
        }
    }
    return numPainter;
}
int getMinTime(int k, int n, int* len){
    int sum, maxlen = 0;
    for(int i = 0; i <n; i++){
        sum=+ len[i];
        maxlen = max(maxlen, len[i]);
    }
    int s = maxlen;
    int e = sum;
    int ans = e;

    while(s <= e){
        int m = s +(e-s)/2;
        // can k paainter pain n boards in m amt. of time
        if(numPainter(n,len,m) <= k){
            //  k painter can paint n boards in m amt. time
            //  [s,e] -> [s,m-1]
            ans = m;
            e= m-1;
        }
        else{
            // k painters cannot paint n boaards in m amt. time
            //  [s,e] -> [m+1,e]
            s= m+1;
        }
    }
    return ans;
}
int main(){
    int k, n;
    cin >> k >> n;
    int len[n];
    for(int i = 0; i < n ; i++){
        cin >> len[i];
    }

    cout << getMinTime(k,n,len) << endl;
    
}