/*
 * SymbolGraph.h
 *
 *  Created on: 19 maig 2016
 *      Author: roure
 */

#ifndef GRAPH_SYMBOLGRAPH_H_
#define GRAPH_SYMBOLGRAPH_H_

#include <unordered_map>

namespace std {

class SymbolGraph {
private:
	unordered_map <string, int> stringIndex;  // vertices index
	string * keys; // reverse index
	AdjListGraph  &g;

public:
	// fileName: the name of the file where the graph is defined
	// sp: separator character
	SymbolGraph(string fileName, char separator);

	bool contains(string v); //returns whether the graph has a vertex with the given name v
	int index(string v); // returns the index of vertex with given name
	string name(int v); // returns the name of vertex with given index
	AdjListGraph & getGraph(); //returns the graph

	virtual ~SymbolGraph();
};

} /* namespace std */



#endif /* GRAPH_SYMBOLGRAPH_H_ */
