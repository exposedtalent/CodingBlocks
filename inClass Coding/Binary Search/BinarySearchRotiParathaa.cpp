// https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
// mid  = s + e / 2

int numPratasCookedByACook(int ranks, int timelimit){
    int cnt = 0;
    int time = 0;
    int i = 1;
    while(time <= timelimit){
        time += i*ranks;
        if(time > timelimit){
            return cnt;
        }
        i++;
        cnt++;
    }
    return cnt;
}
bool numParatas(int l, int* ranks, int timelimit){
    int num = 0;
    for(int i = 0; i < l; i ++){
        num += numPratasCookedByACook(ranks[i], timelimit);
    }
    return num;
}
int getMindTime(int p, int l, int* ranks){
    int s = 0;
    int e = INT_MAX;
    int ans =e;
    while(s < e){
        int mid = s + (e-s) /2;
        // can l cooks with givens ranks cook p paratas in m amt. of time
        //  or
        //  how many paratas can l cooks witth the given ranks cook in m amt. of ttime?

        if(numParatas(l, ranks, mid ) >= p){
            // s[, e] - >[s, m-1]
            ans = mid;
            e= mid-1;
        }
        else{
            //  [s, e] -> [m+1 , e]
            s= mid +1;
        }
    }
}
int main(){
    
    int t;
    cin >>t;
    int p , l;
    int *ranks = new int[l];
    while(t--){
        cin >> p >>l;
        for(int i = 0; i < l ; i++){
            cin >> ranks[i];
        }
        cout << getMindTime(p , l , ranks) << endl;
    }

    
}