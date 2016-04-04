/*
 * DepthFirstPaths.h
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_DIRECTED_DEPTHFIRSTORDER_H_
#define BASICLISTGRAPH_DIRECTED_DEPTHFIRSTORDER_H_

#include <deque>

#include "../digraph/DigraphAdjList.h"

namespace std {
class DirectedDepthFirstOrder {
private:
	bool * visited;  // marked[v] true if there is a s - v path

	deque<int> pre;
	deque<int> post;
	deque<int> revPost;

	void dfs(DigraphAdjList & g, int v);

public:
	DirectedDepthFirstOrder(DigraphAdjList & g);
	virtual ~DirectedDepthFirstOrder();

	//used deque because it's got the iterator defined
	deque<int> & preOrder();
	deque<int> & postOrder();
	deque<int> & reversePostOrder();  // When the directed graph is a DAG then the reversePostOrder is a topological sort

};

} /* namespace std */

#endif /* BASICLISTGRAPH_DIRECTED_DEPTHFIRSTPATHS_H_ */
