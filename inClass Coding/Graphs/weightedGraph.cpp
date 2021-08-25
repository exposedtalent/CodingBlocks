// This is the code for searching the graph and also making a graph of any type

#include<iostream>
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
class graph{
    bool directed;
    map<T, list<pair<T, int> > > neighborMap;

    public:
        graph(bool directed=false){
            this->directed = directed;
        }

        void addEdge(T u, T v, int weight) {
            neighborMap[u].push_back({v, weight}); // Could also use make_pair
            if(!directed) neighborMap[v].push_back({u, weight}); 
        }

        void print(){
            for(pair<T , list<pair <T, int> > > p : neighborMap){
                cout << p.first << " : ";
                for(pair<T , int> neighbor : p.second){
                    cout << "( " <<  neighbor.first << " " << neighbor.second << endl;
                }
                cout << endl;
            }
        }
        
};

int main(){
    graph<int>g;
    g.addEdge(0, 1 , 2);     
    g.addEdge(0, 4, 3);     
    g.addEdge(1, 2, 4);     
    g.addEdge(1, 3, 5);     
    g.addEdge(2, 3, 1);     
    g.addEdge(3, 4 , 4);     

    
    g.print();

    return 0;
}
