#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helpRamu(){
    int  c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int n,m;
    cin >> n >> m;

    vector<int> rick(n), cabs(m);
    for(int i=0;i < n; i++){
        cin >> rick[i];
    }

    for(int i=0;i < m; i++){
        cin >> cabs[i];
    }

    int cosUsingc4 = c4;
    int cosUsingc3 = (n > 0) * c3 + (m > 0) * c3;
    
    int costOfCabs = 0, costOfRick = 0;
    for(int i=0;i <n; i++){
        costOfRick = min(rick[i] * c1, c2);

    }
    costOfRick =  min(costOfRick, c3);
    

    for(int i=0;i < m; i++){
        costOfCabs = min(cabs[i] * c1,  c2);

    }
    costOfCabs =  min(costOfCabs, c3);
    
    // int final = min(min(costOfCabs + costOfRick , cosUsingc3), cosUsingc4);
    int finalCost = min({costOfRick +  costOfCabs, cosUsingc3, cosUsingc4});
    cout << finalCost << endl;

}

int main(){
    
    return 0;
}

