/*
 * ConnectedCompoents.cpp
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#include "ConnectedComponents.h"
#include <iostream>

namespace std {

ConnectedComponents::ConnectedComponents(AdjListGraph & g) {
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	id = new int[g.getOrder()];
	count = 0;

	for (int s=0; s < g.getOrder(); s++) {
		if (!visited[s]) {
			dfs(g,s);
			count++;
		}
	}
}

ConnectedComponents::~ConnectedComponents() {
	delete[] visited;
	delete[] id;
}

void ConnectedComponents::dfs(AdjListGraph & g, int v) {
	visited[v] = true;
	id[v] = count;
	for (auto & w : g.adj(v)) {
		if (!visited[w]) {
			dfs(g,w);
		}
	}
}


bool ConnectedComponents::connected(int v, int w) {
	return id[v]==id[w];
}


int ConnectedComponents::numberComponents() {
	return this->count;
}

int ConnectedComponents::componentId(int v) {
	return id[v];
}


} /* namespace std */
