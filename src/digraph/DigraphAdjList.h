/*
 * DigraphAdjList.h
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#ifndef SRC_GRAPH_DIGRAPHADJLIST_H_
#define SRC_GRAPH_DIGRAPHADJLIST_H_

#include <list>
#include <string>

namespace std {

class DigraphAdjList {
private:
	int order;  // number of vertex
	int size; // number of edges
	list<int> * adjacent;

public:
	DigraphAdjList(int size);
	DigraphAdjList(string fileName);

	int getSize(); //edges
	int getOrder(); //vertex
	void addEdge(int v, int w);
	list<int> & adj(int v) const;
	int degree (int v);
	string toString();

	DigraphAdjList reverse(DigraphAdjList dg);


	virtual ~DigraphAdjList();
};

} /* namespace std */



#endif /* SRC_GRAPH_DIGRAPHADJLIST_H_ */
