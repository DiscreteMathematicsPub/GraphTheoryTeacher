/*
 * BreadthFisrtPaths.h
 *
 *  Created on: 8 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_BREADTHFIRSTPATHSDIGRAPH_H_
#define BASICLISTGRAPH_BREADTHFIRSTPATHSDIGRAPH_H_

#include <list>
#include "EdgeWeightedDigraph.h"

namespace std {

class BreadthFirstPathsDigraph {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	WeightedArc ** edgeTo;	// edgeTo[v] last edge on s - v path
	int count;		// number of vertices connected to s
	int s;			// source vertex

	void bfs(EdgeWeightedDigraph & g, int v);

public:
	BreadthFirstPathsDigraph(EdgeWeightedDigraph & g, int s);
	virtual ~BreadthFirstPathsDigraph();

	bool hasPathTo(int v);
	list<WeightedArc *> pathTo(int v);
	int numConnected();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_BREADTHFIRSTPATHS_H_ */
