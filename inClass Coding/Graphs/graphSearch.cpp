// This is the code for searching the graph and also making a graph of any type

#include<iostream>
#include<list>
#include<unordered_set>
#include<map>
#include<queue>
#include<stack>
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
        
        void dfsHelper(T u, unordered_set<T>& visited){
            visited.insert(u);
            cout << u << " ";
            for(T neighbor : neighborMap[u]){
                if(visited.find(neighbor) == visited.end()){
                    dfsHelper(neighbor, visited);
                }
            }
        }
        void recursiveDFS(T s){
            unordered_set<T> visited;
            cout << "dfs(" << s << ") : ";
            dfsHelper(s, visited);
        }
        //  DFS
        void iterativeDFS(T s){
            stack<T> stack;
            unordered_set<T> visited;

            stack.push(s);
            visited.insert(s);

            cout << "dfs(" << s << ") : ";

            while(!stack.empty()){
                T top = stack.top(); stack.pop();
                cout << top << " ";
                for(T neighbor : neighborMap[top]){
                    if(visited.find(neighbor) == visited.end()){
                        stack.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }
        //  BFS this generates the shortest path from the source to all the vertices 
        void iterativeBFS(T s){
            queue<T> q;
            unordered_set<T> visited;

            q.push(s);
            visited.insert(s);

            cout << "bfs(" << s << ") : ";
            
            while(!q.empty()){
                T top = q.front(); q.pop();
                cout << top << " ";
                for(T neighbor : neighborMap[top]){
                    if(visited.find(neighbor) == visited.end()){
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
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

    g.recursiveDFS(0);
    cout << endl;
    g.iterativeDFS(0);
    cout << endl;
    g.iterativeBFS(0);

    return 0;
}
