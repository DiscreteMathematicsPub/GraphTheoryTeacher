/*
 * AdjListGraph.cpp
 *
 *  Created on: 4 febr. 2016
 *      Author: roure
 */

#include "AdjListGraph.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

namespace std {
template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }



AdjListGraph::AdjListGraph(int order) {
	adjacent =  new list<int>[order];
	this->order = order;
	size = 0;
}

AdjListGraph::AdjListGraph(string fileName) {
	int v,w, nl;
	string line;

	ifstream file;
	file.open(fileName);

	//read order
	file >> order;

	//read size (num lines)
	file >> nl;
	getline(file, line); // reading to the end of the second line
	size = 0;

	adjacent =  new list<int>[order];

	for (int i=0; i<nl; i++) {
		//cout << i << " :::  ";
		getline(file, line);
		istringstream iss(line);
		iss >> v >> w;
		//cout << v << " " << w << endl;
		addEdge(v,w);
	}

}

AdjListGraph::~AdjListGraph() {
	delete[] adjacent;
}


int AdjListGraph::getSize() {
	return size;
}

int AdjListGraph::getOrder() {
	return order;
}

void AdjListGraph::addEdge(int v, int w) {
	if (v < 0 || v >= order || w <0 || w >= order) {
		throw invalid_argument("Invalid argument");
	}
	adjacent[v].push_back(w);
	adjacent[w].push_back(v);
	size++;
}


list<int> & AdjListGraph::adj(int v) const{
	if (v < 0 || v >= order)  {
		throw invalid_argument ("Invalid argument");
	}
	return adjacent[v];
}

string AdjListGraph::toString() {
	string result;

	result = NumberToString(order) + "\n";
	result.append(NumberToString(size) + "\n");

	for (int i=0; i<order; i++) {
		result.append(NumberToString(i) + ": ");
		for (auto &v : adjacent[i]) {
			result.append(NumberToString(v) + " ");
		}
		result.append("\n");
	}


	return result;
}
} /* namespace std */
