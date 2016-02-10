/*
 * BreadthFisrtPaths.h
 *
 *  Created on: 8 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_BREADTHFIRSTPATHS_H_
#define BASICLISTGRAPH_BREADTHFIRSTPATHS_H_

#include <list>
#include "AdjListGraph.h"

namespace std {

class BreadthFirstPaths {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	int * edgeTo;	// edgeTo[v] last edge on s - v path
	int count;		// number of vertices connected to s
	int s;			// source vertex

	void bfs(AdjListGraph & g, int v);

public:
	BreadthFirstPaths(AdjListGraph & g, int s);
	virtual ~BreadthFirstPaths();

	bool hasPathTo(int v);
	list<int> pathTo(int v);
	int numConnected();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_BREADTHFIRSTPATHS_H_ */
