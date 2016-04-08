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

void printPriorityQ(priority_queue<VertexDistance *> &s)
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
	visited = new bool[g.getSize()];
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
}

void DijkstraSP::bfs(EdgeWeightedDigraph & g, int v) {

	visited[v] = true;
	pq.push(new VertexDistance(v,0));

	while (!pq.empty()) {
		printPriorityQ(pq);

		VertexDistance * w = pq.top();
		pq.pop();

		relax(g, w);

		delete w;
	}
}

void DijkstraSP::relax(EdgeWeightedDigraph & g, VertexDistance *v) {
	//this should be relax
	cout << "Relax, vertexDistance: " << v->getVertex() << " " << v->getDistance() << endl;
	for (auto arc : g.adj(v->getVertex())) {
		//if (!visited[arc->getTo()] &&
		printf("dist(%i)=%4.2f > dist(%i)=%4.2f + dist(e)=%4.2f \n", arc->getTo(), distTo[arc->getTo()], v->getVertex(), distTo[v->getVertex()], arc->getWeight() );
		//		cout << "dist(w): " << distTo[arc->getTo()] << " > dist(v): " << distTo[v->getVertex()] << " + dist(e): " << v->getDistance() << endl;
		if(	distTo[arc->getTo()] > distTo[v->getVertex()] + arc->getWeight()) {
			distTo[arc->getTo()] = distTo[v->getVertex()] + arc->getWeight();
			edgeTo[arc->getTo()] = arc;
			visited[arc->getTo()] = true;
			printf("push: %i %4.2f \n", arc->getTo(), distTo[arc->getTo()] );
			pq.push(new VertexDistance(arc->getTo(), distTo[arc->getTo()]));
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
	printf("operator %2.4f < %2.4f \n", right.distance, distance);
	return right.distance < distance;
}

int VertexDistance::getVertex() { return vertex;}
double VertexDistance::getDistance() {return distance;}

} /* namespace std */
