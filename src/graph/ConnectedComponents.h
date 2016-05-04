/*
 * DepthFirstPaths.h
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_CC_H_
#define BASICLISTGRAPH_CC_H_

#include <list>
#include "AdjListGraph.h"

namespace std {

class ConnectedComponents {
private:
	bool * visited;  // marked[v] true if there is a s - v path
	int * id;		// stores the component number the i-th vertex belongs to
	int count;

	void dfs(AdjListGraph & g, int v);

public:
	ConnectedComponents(AdjListGraph & g);
	virtual ~ConnectedComponents();

	bool connected(int v, int w);
	int componentId(int v);
	int numberComponents();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_DEPTHFIRSTPATHS_H_ */
