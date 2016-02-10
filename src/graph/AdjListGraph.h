/*
 * AdjListGraph.h
 *
 *  Created on: 4 febr. 2016
 *      Author: roure
 */

#ifndef BASICLISTGRAPH_ADJLISTGRAPH_H_
#define BASICLISTGRAPH_ADJLISTGRAPH_H_

#include <list>
#include <string>

namespace std {

class AdjListGraph {
private:
	int order;  // number of vertex
	int size; // number of edges
	list<int> * adjacent;

public:
	AdjListGraph(int size);
	AdjListGraph(string fileName);

	int getSize(); //edges
	int getOrder(); //vertex
	void addEdge(int v, int w);
	list<int> & adj(int v) const;
	int degree (int v);
	string toString();


	virtual ~AdjListGraph();
};

} /* namespace std */

#endif /* BASICLISTGRAPH_ADJLISTGRAPH_H_ */
