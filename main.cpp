//
//  Created by Jonas Anseeuw
//  Copyright (c) 2014 Jonas Anseeuw. All rights reserved.
//

#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

class StrongComponents{
public:
	StrongComponents(const Graph<DIRECTED> &G):G(G), cnt(0), scnt(0),
	postI(G.numberOfVertices()), postR(G.numberOfVertices()), id(G.numberOfVertices(), -1){
		Graph<DIRECTED>R(G.numberOfVertices());
		reverse(G, R);
		for(int i=0; i<R.numberOfVertices(); i++){
			if(id[i] == -1) dfsR(R, i);
		}
		postR = postI; cnt=scnt=0;
		id.assign(G.numberOfVertices(), -1);
		for(int i=G.numberOfVertices()-1; i >= 0; i--){
			if(id[postR[i]] == -1){
				dfsR(G, postR[i]);
				scnt++;
			}
		}
	}
	int count() const { return scnt; }
	bool stronglyreachable(int v, int w) const{
		return (id[v] == id[w]);
	}
private:
	const Graph<DIRECTED> &G;
	int cnt, scnt;
	vector<int> postI, postR, id;
	void dfsR(const Graph<DIRECTED> &g, int w){
		id[w]=scnt;
		map<int,int>::const_iterator it = g[w].begin();
		while(it != g[w].end()){
			if(id[it->first] == -1) dfsR(g, it->first);
			it++;
		}
		postI[cnt++]=w;
	}
	void reverse(const Graph<DIRECTED> &G, Graph<DIRECTED> &R){
		for (int i=0; i<G.numberOfVertices(); i++){
			map<int,int>::const_iterator it = G[i].begin();
			while (it != G[i].end()){
				R.addEdge(it->first, i);
				it++;
			}
		}
	}
	
};

int main(int argc, char *argv[]){
	const int N=5;
	
	Graph<DIRECTED>g(N);
	
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	g.addEdge(2, 4);
	
	StrongComponents sc(g);
	cout<<"0 -> 2 is "; sc.stronglyreachable(0, 2) ? cout<<"" : cout<<"not"; cout<<" strongly reachable"<<endl;
	cout<<"0 -> 4 is "; sc.stronglyreachable(0, 4) ? cout<<"" : cout<<"not"; cout<<" strongly reachable"<<endl;
	
	
    return 0;
}
