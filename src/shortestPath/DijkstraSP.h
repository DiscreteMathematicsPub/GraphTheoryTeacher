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
#include "VertexDistance.h"

namespace std {


class DijkstraSP {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	WeightedArc ** edgeTo;	// edgeTo[v] last edge on s - v path
	double * distTo; // distTo[v] the distance form s to v

	int s;			// source vertex

	//priority_queue<VertexDistance *> pq;
	priority_queue<VertexDistance *, vector<VertexDistance *>, VertexDistanceComparison> pq;

	void bfs(EdgeWeightedDigraph & g, int v);
	void relax (EdgeWeightedDigraph & g, int v);

public:
	DijkstraSP(EdgeWeightedDigraph & g, int s);
	virtual ~DijkstraSP();

	bool hasPathTo(int v);
	list<WeightedArc *> pathTo(int v);
	int distanceTo(int v);
};

} /* namespace std */

#endif /* BASICLISTGRAPH_BREADTHFIRSTPATHS_H_ */
