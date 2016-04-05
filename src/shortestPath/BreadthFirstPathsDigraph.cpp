/*
 * BreadthFisrtPaths.cpp
 *
 *  Created on: 8 febr. 2016
 *      Author: roure
 */

#include "BreadthFirstPathsDigraph.h"

#include <queue>

namespace std {


BreadthFirstPathsDigraph::BreadthFirstPathsDigraph(EdgeWeightedDigraph & g, int s) {
	visited = new bool[g.getSize()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	edgeTo = new WeightedArc *[g.getSize()];
	for (int i=0; i<g.getSize(); i++) {
		edgeTo[i]=NULL;
	}
	this->s = s;
	bfs(g,s);
}

BreadthFirstPathsDigraph::~BreadthFirstPathsDigraph() {
	delete[]  visited;
	delete[]  edgeTo;
}

void BreadthFirstPathsDigraph::bfs(EdgeWeightedDigraph & g, int v) {
	queue<int> needToProcess;

	visited[v] = true;
	needToProcess.push(v);
	while (!needToProcess.empty()) {
		int w = needToProcess.front();
		needToProcess.pop();
		for (auto arc : g.adj(w)) {
			if (!visited[arc->getTo()]) {
				edgeTo[arc->getTo()] = arc;
				visited[arc->getTo()] = true;
				needToProcess.push(arc->getTo());
			}
		}
	}
}


bool BreadthFirstPathsDigraph::hasPathTo(int v) {
	return visited[v];
}

list<WeightedArc *> BreadthFirstPathsDigraph::pathTo(int v) {
	list<WeightedArc *> path;

	if (!hasPathTo(v)) {
		path.push_back(NULL);
		return path; //there is no path
	}

	for (int x = v; edgeTo[x] !=NULL; x=edgeTo[x]->getFrom()) {
		path.push_back(edgeTo[x]);
	}

	return path;
}


int BreadthFirstPathsDigraph::numConnected() {
	return this->count;
}


} /* namespace std */
