// This is a implementation of graph using doubly linked list

#include<iostream>
#include<list>
using namespace std;

class graph{
    int v;
    list<int>* arr;
    bool directed;
    public:
        graph(int v, bool directed=false){
            this->v = v;
            arr = new list<int>[v];

        }
        void addEdge(int u, int v) {
            arr[u].push_back(v);
            if(directed == false) arr[v].push_back(u);
        }

        void print(){
            for(int i = 0; i <v;i++){
                cout<< i << " : ";
                for(int neighbor : arr[i]){
                    cout<< neighbor << " ";
                }
                cout << endl;
            }
        }
};

int main(){

    graph g(5, true);
    g.addEdge(0, 1);     
    g.addEdge(0, 4);     
    g.addEdge(1, 2);     
    g.addEdge(1, 3);     
    g.addEdge(2, 3);     
    g.addEdge(3, 4);     

    g.print();
    return 0;
}
