/*
 * DirectedCycle.h
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#ifndef SRC_GRAPH_CYCLE_H_
#define SRC_GRAPH_CYCLE_H_

#include "DigraphAdjList.h"
#include <stack>

namespace std {

class Cycle {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	int * edgeTo;	// edgeTo[v] last edge on s - v path
	stack<int> cycle; // empty if there is no cycle

	void dfs(AdjListGraph & g, int u, int v);
	bool hasSelfLoop(AdjListGraph &g);
	bool hasParallelEdges(AdjListGraph &g);

public:
	Cycle(AdjListGraph & g);
	virtual ~Cycle();

	bool hasCycle();
	stack<int> & getCycle();
};


} //std

#endif /* SRC_GRAPH_CYCLE_H_ */
