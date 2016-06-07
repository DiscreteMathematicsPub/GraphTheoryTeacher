/*
 * TopologicalOrder.cpp
 *
 *  Created on: 7 juny 2016
 *      Author: roure
 */

#include "TopologicalOrder.h"
#include <iostream>

namespace std {

TopologicalOrder::TopologicalOrder(EdgeWeightedDigraph & g) {
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	for (int v=0; v<g.getOrder(); v++) {
		if (!visited[v]) dfs(g,v);
	}
}

TopologicalOrder::~TopologicalOrder() {
	delete[]  visited;
}

void TopologicalOrder::dfs(EdgeWeightedDigraph & g, int v) {

	visited[v] = true;
	for (auto & arc : g.adj(v)) {
		if (!visited[arc->getTo()]) {
			dfs(g,arc->getTo());
		}
	}
	revPost.push_front(v); // used as a stack
}

deque<int> & TopologicalOrder::topologicalOrder() {
	return revPost;
}


} /* namespace std */



