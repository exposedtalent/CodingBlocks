// This is the code for searching the graph and also making a graph of any type

#include<iostream>
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<queue>
#include<stack>
#include<climits>
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

        void dijkstra(T s, T d){
            unordered_map<T, int> distanceMap;
            // Initialize the distance map to INF
            for(pair <T, list<pair<T, int > > >vertex : neighborMap) {
                t vertexName = vertex.first;
                distanceMap[vertexName] = INT_MAX;
            }
            // We know the source will be source to itself will be 0
            distanceMap[s] = 0;
            // to keep track explored vertices
            unordered_set<T> explored;
            // To keep track of unexplored vertices
            set<pair<int, T> > minHeap;

            for(pair<T, int> vertex : distanceMap){
                T vertexName = vertex.first;
                int vertexDistance = vertex.second;
                minHeap.insert({vertexDistance, vertexName});
            }

            // Extract the min from minHeap 
            while(!minHeap.empty()){
                // get the min and delete it
                pair<int, T> minVertex = *(minHeap.begin());
                minHeap.erase(minHeap.begin());

                int minVertexDist = minVertex.first;
                T minVertexName = minVertex.second;

                for(pair<T, int> neighbor : neighborMap[minVertexName]){
                    T neighborName = neighbor.first;
                    int edgeWgt = minVertex.second;
                    if(explored.find(neighborName) == explored.end() && distanceMap[neighborName] > minVertexDist + edgeWgt){
                        // Edge between the minVertex and neighbour is tensed so relax it
                        // Find the node in the minHeap and delete it then  processed to add 
                        // Update the distance of the neighbour inside the minHeap
                        auto it = minHeap.find({distanceMap[neighborName], neighborName});
                        if(it != minHeap.end()) minHeap.erase(it);
                        minHeap.insert({distanceMap[neighborName], neighborName});
                        // Update the distance of the neighbour inside the distanceMap
                        distanceMap[neighborName] = minVertexDist + edgeWgt;

                    }
                } 
            }
            // For printing the distanceMap
            for(pair<T, int> vertex : distanceMap){
                T vertexName = vertex.first;
                int vertexDistance = vertex.second;
                cout << " ( " << vertexName << " , " << vertexDistance << " )" << endl;

            }
            cout << endl;
        }
        
};

int main(){
    graph<int>g;
    g.addEdge('A', 'B', 10);     
    g.addEdge('A', 'C', 3);     
    g.addEdge('B', 'C', 4);     
    g.addEdge('B', 'D', 5);     
    g.addEdge('C', 'D', 4);     
    g.addEdge('C', 'E', 4);             
    g.addEdge('D', 'E', 4);             


    g.print();

    return 0;
}
