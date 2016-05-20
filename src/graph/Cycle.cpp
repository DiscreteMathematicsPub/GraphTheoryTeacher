/*
 * Cycle.cpp
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#include "Cycle.h"
#include <iostream>

namespace std {

Cycle::Cycle(AdjListGraph &g) {
	visited = new bool[g.getOrder()];

	if (hasSelfLoop(g)) return;
	if (hasParallelEdges(g)) return;

	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	edgeTo = new int[g.getOrder()];
	for (int v=0; v<g.getOrder(); v++) {
		if (!visited[v])
			dfs(g, v, v);
		if (hasCycle()) return; //finish when cycle detected
	}
}

Cycle::~Cycle() {
	delete[]  visited;
	delete[]  edgeTo;
}

void Cycle::dfs(AdjListGraph & g, int v, int u) {
	visited[v] = true;
	cout << "dfs source v: " << v << " u: " << u << endl;
	for (auto & w : g.adj(v)) {
		if (!visited[w]) {
			edgeTo[w] = v;
			dfs(g, w, v);
			if (hasCycle()) return;  //returns from the recursive calls once a cycle is detected
		}
		else {
			// If we reach a visited node from v (the one being explored)
			// it means we have a cycle
			if (w != u) { //disregard reverse of edge leading to v
				cout << "cycle detected \n";
				for (int x = v; x!=w; x=edgeTo[x]) {
					cycle.push(x);
				}
				cycle.push(w);
				cycle.push(v);
				return; // returns when a cycle is detected
			}
		}
	}
}

bool Cycle:: hasCycle() {
	return !cycle.empty();
}

stack<int> & Cycle:: getCycle() {
	return cycle;
}

bool Cycle::hasSelfLoop(AdjListGraph &g) {
	for (int v=0; v < g.getOrder(); v++) {
		for (auto &w : g.adj(v)) {
			if (v==w) {
				cycle.push(v);
				cycle.push(v);
				return true;
			}
		}
	}
	return false;
}

bool Cycle::hasParallelEdges(AdjListGraph &g) {
	for (int v=0; v < g.getOrder(); v++) {
		// reset visited
		for (int i=0; i<g.getOrder(); i++) {
			visited[i]=false;
		}
		for (auto &w : g.adj(v)) {
			if (visited[w]) { //w visited twice from v
				cycle.push(v);
				cycle.push(w);
				cycle.push(v);
				return true;
			}
			visited[w] = true;
		}
	}
	return false;
}


} /* namespace std */



