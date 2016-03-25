/*
 * DirectedCycle.h
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#ifndef SRC_GRAPH_DIRECTEDCYCLE_H_
#define SRC_GRAPH_DIRECTEDCYCLE_H_

#include "DigraphAdjList.h"
#include <stack>

namespace std {

class DirectedCycle {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	bool * onStack;	 // onStack[v] true if v is in edgeTo (belongs to the path)
	int * edgeTo;	// edgeTo[v] last edge on s - v path
	stack<int> cycle; // empty if there is no cycle

	void dfs(DigraphAdjList & g, int v);
	void emptyStackCycle();

public:
	DirectedCycle(DigraphAdjList & g);
	virtual ~DirectedCycle();

	bool hasCycle();
	stack<int> & getCycle();
};


} //std

#endif /* SRC_GRAPH_DIRECTEDCYCLE_H_ */
