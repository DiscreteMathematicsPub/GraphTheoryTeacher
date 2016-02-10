/*
 * DepthFirstPaths.cpp
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#include "DepthFirstPaths.h"

namespace std {

DepthFirstPaths::DepthFirstPaths(AdjListGraph & g, int s) {
	visited = new bool[g.getSize()];
	edgeTo = new int[g.getSize()];
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
