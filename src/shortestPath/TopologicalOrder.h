/*
 * TopologicalOrder.h
 *
 *  Created on: 7 juny 2016
 *      Author: roure
 */

#ifndef SHORTESTPATH_TOPOLOGICALORDER_H_
#define SHORTESTPATH_TOPOLOGICALORDER_H_

#include <deque>

#include "EdgeWeightedDigraph.h"

namespace std {
class TopologicalOrder {
private:
	bool * visited;  // marked[v] true if there is a s - v path

	deque<int> revPost;

	void dfs(EdgeWeightedDigraph & g, int v);

public:
	TopologicalOrder(EdgeWeightedDigraph & g);
	virtual ~TopologicalOrder();

	//used deque because it's got the iterator defined
	deque<int> & topologicalOrder();  // When the directed graph is a DAG then the reversePostOrder is a topological sort

};

} /* namespace std */



#endif /* SHORTESTPATH_TOPOLOGICALORDER_H_ */
