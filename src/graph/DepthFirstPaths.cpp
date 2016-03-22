/*
 * DepthFirstPaths.cpp
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#include "DepthFirstPaths.h"
#include <iostream>

namespace std {

DepthFirstPaths::DepthFirstPaths(AdjListGraph & g, int s) {
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	edgeTo = new int[g.getOrder()];
	this->s = s;
	dfs(g,s);
}

DepthFirstPaths::~DepthFirstPaths() {
	delete[]  visited;
	delete[]  edgeTo;
}

void DepthFirstPaths::dfs(AdjListGraph & g, int v) {
	visited[v] = true;
	for (auto & w : g.adj(v)) {
		if (!visited[w]) {
			edgeTo[w] = v;
			dfs(g,w);
		}
	}
}


bool DepthFirstPaths::hasPathTo(int v) {
	return visited[v];
}

list<int> DepthFirstPaths::pathTo(int v) {
	list<int> path;

	if (!hasPathTo(v)) {
		path.push_back(-1);
		return path; //there is no path
	}

	for (int x = v; x !=s; x=edgeTo[x]) {
		path.push_back(x);
	}
	path.push_back(s);

	return path;
}


int DepthFirstPaths::numConnected() {
	return this->count;
}


} /* namespace std */
