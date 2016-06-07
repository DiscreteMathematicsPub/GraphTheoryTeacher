/*
 * AcyclicSP.cpp
 *
 *  Created on: 6 juny 2016
 *      Author: roure
 */
#include "AcyclicSP.h"
#include <limits>
#include<iostream>
#include<stdio.h>

namespace std {

AcyclicSP::AcyclicSP(EdgeWeightedDigraph& g, int s) {
	edgeTo = new WeightedArc *[g.getSize()];
	for (int i=0; i<g.getSize(); i++) {
		edgeTo[i]=NULL;
	}

	distTo = new double[g.getSize()];
	for (int i=0; i<g.getSize(); i++) {
		distTo[i]= numeric_limits<double>::max();
	}
	distTo[s] = 0;

	topological = new TopologicalOrder(g);
	for (auto v: topological->topologicalOrder()) {
		relax(g,v);
	}
}

AcyclicSP::~AcyclicSP() {
	delete[]  edgeTo;
	delete[]  distTo;
}

bool AcyclicSP::hasPathTo(int v) {
	return distTo[v] < numeric_limits<double>::max();
}

list<WeightedArc*> AcyclicSP::pathTo(int v) {
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

int AcyclicSP::distanceTo(int v) {
	return distTo[v];
}

void AcyclicSP::relax(EdgeWeightedDigraph& g, int v) {
	cout << "Relax vertex: " << v << endl;
	for (auto arc : g.adj(v)) {
		if(	distTo[arc->getTo()] > distTo[v] + arc->getWeight()) {
			distTo[arc->getTo()] = distTo[v] + arc->getWeight();
			edgeTo[arc->getTo()] = arc;
		}
	}
}


}
