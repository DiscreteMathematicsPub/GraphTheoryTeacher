/*
 * DepthFirstPaths.h
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_DEPTHFIRSTPATHS_H_
#define BASICLISTGRAPH_DEPTHFIRSTPATHS_H_

#include <list>
#include "AdjListGraph.h"

namespace std {

class DepthFirstPaths {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	int * edgeTo;	// edgeTo[v] last edge on s - v path
	int count;		// number of vertices connected to s
	int s;			// source vertex

	void dfs(AdjListGraph & g, int v);

public:
	DepthFirstPaths(AdjListGraph & g, int s);
	virtual ~DepthFirstPaths();

	bool hasPathTo(int v);
	list<int> pathTo(int v);
	int numConnected();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_DEPTHFIRSTPATHS_H_ */
