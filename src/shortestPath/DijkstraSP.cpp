/*
 * BreadthFisrtPaths.cpp
 *
 *  Created on: 8 febr. 2016
 *      Author: roure
 */

#include "DijkstraSP.h"

#include <limits>
#include<iostream>
#include<stdio.h>

namespace std {

void printPriorityQ(priority_queue<VertexDistance *, vector<VertexDistance *>, VertexDistanceComparison> &s)
{
    if(s.empty())
    {
        cout << endl;
        return;
    }
    VertexDistance * x= s.top();
    s.pop();
    cout << x->getVertex() << " " << x->getDistance() << " , ";

    printPriorityQ(s);
    s.push(x);
 }


DijkstraSP::DijkstraSP(EdgeWeightedDigraph & g, int s) {
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	edgeTo = new WeightedArc *[g.getSize()];
	for (int i=0; i<g.getSize(); i++) {
		edgeTo[i]=NULL;
	}

	distTo = new double[g.getSize()];
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
	delete[]  distTo;
}

void DijkstraSP::bfs(EdgeWeightedDigraph & g, int v) {

	pq.push(new VertexDistance(v,0));

	while (!pq.empty()) {
		printPriorityQ(pq);

		VertexDistance * w = pq.top();
		pq.pop();

		if (!visited[w->getVertex()]) {
			visited[w->getVertex()] = true;
			relax(g, w->getVertex());
		}

		delete w;
	}
}

void DijkstraSP::relax(EdgeWeightedDigraph & g, int v) {
	//this should be relax
	cout << "Relax vertex: " << v << endl;
	for (auto arc : g.adj(v)) {
		if (!visited[arc->getTo()]) { //we may have repeated vertices in the queue
			if(	distTo[arc->getTo()] > distTo[v] + arc->getWeight()) {
				distTo[arc->getTo()] = distTo[v] + arc->getWeight();
				edgeTo[arc->getTo()] = arc;
				pq.push(new VertexDistance(arc->getTo(), distTo[arc->getTo()]));
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


int DijkstraSP::distanceTo(int v) {
	return distTo[v];
}


} /* namespace std */
