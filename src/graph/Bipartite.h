/*
 * Bipartite.h
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#ifndef SRC_GRAPH_BIPARTITE_H_
#define SRC_GRAPH_BIPARTITE_H_

#include "AdjListGraph.h"
#include <stack>

namespace std {

class Bipartite {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	bool * color; //
	int * edgeTo;	// edgeTo[v] last edge on s - v path
	stack<int> cycle; // empty if there is no cycle
	bool isBi;

	void dfs(AdjListGraph & g, int v);

public:
	Bipartite(AdjListGraph & g);
	virtual ~Bipartite();

	bool isBipartite();
	bool getColor(int v);
	bool hasCycle();
	stack<int> & oddCycle();
};


} //std

#endif /* SRC_GRAPH_BIPARTITE_H_ */
