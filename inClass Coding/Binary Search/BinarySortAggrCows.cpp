// https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<algorithm>
using namespace std;
// mid  = s + e / 2
bool canYouPlace(int n, int c, int*pos, int m){

    // you can place the first cow in the 1st stall
    int prev = pos[0];
    int numCowsPlaced = 1;
    for(int i =1; i< n; i++){
        // can i place the next cow in the ith stall
        if(pos[i]- prev >= m){
            //  you can place the cow
            prev = pos[i];
            numCowsPlaced++;
            if(numCowsPlaced == c){
                return true;
            }
        }
    }
    return false;
}

int largestMinDist(int n, int c, int* pos){
    int s =1;
    int e = pos[n-1] - pos[0];
    int ans;
    while(s <= e){
        int m = s + (e-s) /2;
        if(canYouPlace(n,c,pos,m)){
            // you can place c cows in n stalls
            // save the ans, and move to the right 
            // [s,e] -> [m+1, e]
            ans = m;
            s = m+1;
        }
        else{
            // you cannot place c cows in n stalls
            // move to the left
            // [s,e] -> [s,m-1]
            e = m-1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    int n,c;
    while(t--){
        
        cin >> n >>c;
        int pos[n];
        for(int i =0;  i < n ; i++){
            cin >> pos[i];
        }
        sort(pos,pos+n);
        cout << largestMinDist(n,c,pos) << endl;


    }
    
}