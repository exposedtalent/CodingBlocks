// This is a implementation of graph using doubly linked list and map that would take any input

#include<iostream>
#include<list>
#include<map>
using namespace std;
template<typename T>
class graph{
    map<T, list<T> > neighborMap;
    bool directed;

    public:
        graph(bool directed=false){
            this->directed = directed;
        }

        void addEdge(T u, T v) {
            neighborMap[u].push_back(v);
            if(!directed) neighborMap[v].push_back(u);
        }

        void print(){
            for(pair<T , list<T> > p : neighborMap){
                cout << p.first << " : ";
                for(T neighbor : p.second){
                    cout << neighbor << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    graph<int>g;
    g.addEdge(0, 1);     
    g.addEdge(0, 4);     
    g.addEdge(1, 2);     
    g.addEdge(1, 3);     
    g.addEdge(2, 3);     
    g.addEdge(3, 4);     

    g.print();

    return 0;
}
