/*
 * Cycle.cpp
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#include "Cycle.h"
#include <iostream>

namespace std {

Cycle::Cycle(AdjListGraph & g) {
	if (hasSelfLoop(g)) return;
	if (hasParallelEdges(g)) return;

	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	edgeTo = new int[g.getOrder()];
	for (int v=0; v<g.getOrder(); v++) {
		if (!visited[v])
			dfs(g, -1, v);
	}
}

Cycle::~Cycle() {
	delete[]  visited;
	delete[]  edgeTo;
}

void Cycle::dfs(AdjListGraph & g, int u, int v) {
	visited[v] = true;
	for (auto & w : g.adj(v)) {
		if(this->hasCycle()) {
			return;
		}
		else if (!visited[w]) {
			edgeTo[w] = v;
			dfs(g, v, w);
		}
		else if (w != v) { //disregard reverse of edge leading to v
			for (int x = v; x!=w; x=edgeTo[x]) {
				cycle.push(x);
			}
			cycle.push(w);
			cycle.push(v);
		}
	}
}

bool Cycle:: hasCycle() {
	return !cycle.empty();
}

stack<int> & Cycle:: getCycle() {
	return cycle;
}


} /* namespace std */



