/*
 * Bipartite.cpp
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#include "Bipartite.h"
#include <iostream>

namespace std {

Bipartite::Bipartite(AdjListGraph & g) {
	isBi = true;
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}
	color = new bool[g.getOrder()];

	edgeTo = new int[g.getOrder()];
	for (int v=0; v<g.getOrder(); v++) {
		if (!visited[v])
			color[v]=false;
			dfs(g, v);
	}
}

Bipartite::~Bipartite() {
	delete[]  visited;
	delete[]  edgeTo;
}

void Bipartite::dfs(AdjListGraph & g, int v) {
	visited[v] = true;
	for (auto & w : g.adj(v)) {
		if(this->hasCycle()) {
			return;
		}
		else if (!visited[w]) {
			edgeTo[w] = v;
			color[w] = !color[v];
			dfs(g, w);
		}
		else if (color[w] == color[v]) { //a odd cycle must be found
			isBi = false;
			for (int x = v; x!=w; x=edgeTo[x]) {
				cycle.push(x);
			}
			cycle.push(w);
			cycle.push(v);
		}
	}
}

bool Bipartite:: isBipartite() {
	return isBi;
}

bool Bipartite:: getColor(int v) {
	return color[v];
}

stack<int> & Bipartite:: oddCycle() {
	return cycle;
}

bool Bipartite:: hasCycle() {
	return !cycle.empty();
}


} /* namespace std */



