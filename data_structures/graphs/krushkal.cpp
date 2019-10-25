#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define edge pair<int, int>

class Graph {
	vector<pair <int, edge> > G; // graph
	vector<pair <int, edge> > T; // MST
	int *parent;
	int V; // Number of vertices
public:
	Graph(int v) {
		parent = new int[V];
		for(int i=0; i<V; i++)
			parent[i] = i;
		
	G.clear();
	T.clear();
	}
	
	void AddWeightedEdge(int u, int v, int w) {
		G.push_back(make_pair(w,edge(u,v)));
	}
	
	int findSet(int i) {
		if( i == parent[i]) //if i is the parent of itself 
			return i;
		else 
			return findSet(parent[i]);
	}
	
	void unionSet(int u, int v) {
		parent[u] = parent[v];
	}
	
	void krushkal() {
		int i, uRep, vRep;
		sort(G.begin(), G.end()); // sort in increasing order
		for(i=0; i<G.size(); i++) {
			uRep = findSet(G[i].second.first); 
			vRep = findSet(G[i].second.second);	
			if (uRep != vRep) { // find if both are already not in same set
				T.push_back(G[i]); // if add to tree
				unionSet(uRep, vRep);
			}
		}
	}
	
	void print() {
		cout<<" Edge : Weight" <<endl;
		for(int i=0; i<T.size(); i++)
			cout<<T[i].second.first<<" - "<<T[i].second.second<<" : "<<T[i].first<<endl;
	}
};

int main() {
	Graph g(6);
	g.AddWeightedEdge(0, 1, 4);
    g.AddWeightedEdge(0, 2, 4);
    g.AddWeightedEdge(1, 2, 2);
    g.AddWeightedEdge(1, 0, 4);
    g.AddWeightedEdge(2, 0, 4);
    g.AddWeightedEdge(2, 1, 2);
    g.AddWeightedEdge(2, 3, 3);
    g.AddWeightedEdge(2, 5, 2);
    g.AddWeightedEdge(2, 4, 4);
    g.AddWeightedEdge(3, 2, 3);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(4, 2, 4);
    g.AddWeightedEdge(4, 3, 3);
    g.AddWeightedEdge(5, 2, 2);
    g.AddWeightedEdge(5, 4, 3);
	
	g.krushkal();
	g.print();
	return 0;
}
