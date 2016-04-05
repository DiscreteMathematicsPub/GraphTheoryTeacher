/*
 * BreadthFisrtPaths.cpp
 *
 *  Created on: 8 febr. 2016
 *      Author: roure
 */

#include "DijkstraSP.h"

#include <limits>

namespace std {


DijkstraSP::DijkstraSP(EdgeWeightedDigraph & g, int s) {
	visited = new bool[g.getSize()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	edgeTo = new WeightedArc *[g.getSize()];
	for (int i=0; i<g.getSize(); i++) {
		edgeTo[i]=NULL;
	}

	distTo = new double* [g.getSize()];
	for (int i=0; i<g.getSize(); i++) {
		distTo[i]= numeric_limits<double>::max();
	}
	distTo[s] = 0;

	this->s = s;
	bfs(g,s);
}

DijkstraSP::~DijkstraSP() {
	delete[]  visited;
	delete[]  edgeTo;
}

void DijkstraSP::bfs(EdgeWeightedDigraph & g, int v) {

	visited[v] = true;
	pq.push(new VertexDistance(v,0));

	while (!pq.empty()) {
		int w = pq.top();
		pq.pop();
		for (auto arc : g.adj(w)) {
			if (!visited[arc->getTo()]) {
				edgeTo[arc->getTo()] = arc;
				visited[arc->getTo()] = true;
				pq.push(arc->getTo());
			}
		}
	}
}


bool DijkstraSP::hasPathTo(int v) {
	return visited[v];
}

list<WeightedArc *> DijkstraSP::pathTo(int v) {
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


int DijkstraSP::numConnected() {
	return this->count;
}


//////////////////////// Vertex Distance /////////////////
VertexDistance::VertexDistance(int v, double d) {
	vertex = v;
	distance = d;
}


bool VertexDistance::operator<(const VertexDistance& right) const {
	return right.distance < distance;
}

int VertexDistance::getVertex() { return vertex;}
double VertexDistance::getDistance() {return distance;}

} /* namespace std */
