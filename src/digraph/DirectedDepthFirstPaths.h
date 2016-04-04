/*
 * DepthFirstPaths.h
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_DIRECTED_DEPTHFIRSTPATHS_H_
#define BASICLISTGRAPH_DIRECTED_DEPTHFIRSTPATHS_H_

#include <list>
#include "DigraphAdjList.h"

namespace std {
class DirectedDepthFirstPaths {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	int * edgeTo;	// edgeTo[v] last edge on s - v path
	int count;		// number of vertices connected to s
	int s;			// source vertex

	void dfs(DigraphAdjList & g, int v);

public:
	DirectedDepthFirstPaths(DigraphAdjList & g, int s);
	virtual ~DirectedDepthFirstPaths();

	bool hasPathTo(int v);
	list<int> pathTo(int v);
	int numConnected();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_DIRECTED_DEPTHFIRSTPATHS_H_ */
