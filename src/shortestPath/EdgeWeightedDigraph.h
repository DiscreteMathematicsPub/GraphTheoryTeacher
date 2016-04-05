/*
 * AdjListGraph.h
 *
 *  Created on: 4 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_EDGEWEIGHTEDDIGRAPH_H_
#define BASICLISTGRAPH_EDGEWEIGHTEDDIGRAPH_H_

#include <list>
#include <string>
#include "WeightedArc.h"

namespace std {

class EdgeWeightedDigraph {
private:
	int order;  // number of vertex
	int size; // number of edges
	list<WeightedArc *> * adjacent;

public:
	EdgeWeightedDigraph(int size);
	EdgeWeightedDigraph(string fileName);

	int getSize(); //edges
	int getOrder(); //vertex
	void addArc(WeightedArc *e);
	list<WeightedArc *> & adj(int v) const;
	int degree (int v);
	string toString();


	virtual ~EdgeWeightedDigraph();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_ADJLISTGRAPH_H_ */
