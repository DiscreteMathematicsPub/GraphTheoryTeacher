/*
 * BreadthFisrtPaths.h
 *
 *  Created on: 8 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_DIJKSTRASP_H_
#define BASICLISTGRAPH_DIJKSTRASP_H_

#include <list>
#include <queue>
#include "EdgeWeightedDigraph.h"

namespace std {

class VertexDistance {
private:
	int vertex;
	double distance;

public:
	VertexDistance(int v, double d);
	bool operator<(const VertexDistance& right) const;

	int getVertex();
	double getDistance();
};

class DijkstraSP {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	WeightedArc ** edgeTo;	// edgeTo[v] last edge on s - v path
	double * distTo; // distTo[v] the distance form s to v

	int count;		// number of vertices connected to s
	int s;			// source vertex

	priority_queue<VertexDistance *> pq;

	void bfs(EdgeWeightedDigraph & g, int v);
	void relax (EdgeWeightedDigraph & g, VertexDistance *v);

public:
	DijkstraSP(EdgeWeightedDigraph & g, int s);
	virtual ~DijkstraSP();

	bool hasPathTo(int v);
	list<WeightedArc *> pathTo(int v);
	int numConnected();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_BREADTHFIRSTPATHS_H_ */
