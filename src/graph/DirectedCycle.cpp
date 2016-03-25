/*
 * DirectedCycle.cpp
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#include "DirectedCycle.h"
#include <iostream>

namespace std {

DirectedCycle::DirectedCycle(DigraphAdjList & g) {
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	edgeTo = new int[g.getOrder()];
	onStack = new bool[g.getOrder()];
	for (int v=0; v<g.getOrder(); v++) {
		dfs(g,v);
	}
}

DirectedCycle::~DirectedCycle() {
	delete[]  visited;
	delete[]  edgeTo;
	delete[]  onStack;
}

void DirectedCycle::dfs(DigraphAdjList & g, int v) {
	onStack[v] = true;
	visited[v] = true;
	for (auto & w : g.adj(v)) {
		if(this->hasCycle()) {
			return;
		}
		else if (!visited[w]) {
			edgeTo[w] = v;
			dfs(g,w);
		}
		else if (onStack[w]) {
			for (int x = v; x!=w; x=edgeTo[x]) {
				cycle.push(x);
			}
			cycle.push(w);
			cycle.push(v);
		}
	}
	onStack[v]=false;
	//emptyStackCycle();
}

bool DirectedCycle:: hasCycle() {
	return !cycle.empty();
}

stack<int> & DirectedCycle:: getCycle() {
	return cycle;
}


void DirectedCycle:: emptyStackCycle() {
	while (!cycle.empty()) {
		cycle.pop();
	}
}

} /* namespace std */



