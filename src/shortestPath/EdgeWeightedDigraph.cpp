/*
 * AdjListGraph.cpp
 *
 *  Created on: 4 febr. 2016
 *      Author: roure
 */

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "EdgeWeightedDigraph.h"

namespace std {
template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }



EdgeWeightedDigraph::EdgeWeightedDigraph(int order) {
	adjacent =  new list<WeightedArc *>[order];
	this->order = order;
	size = 0;
}

EdgeWeightedDigraph::EdgeWeightedDigraph(string fileName) {
	int v,u, nl;
	double w;
	string line;

	ifstream file;
	file.open(fileName);

	//read order
	file >> order;

	//read size (num lines)
	file >> nl;
	getline(file, line); // reading to the end of the second line
	size = 0;

	adjacent =  new list<WeightedArc *>[order];

	for (int i=0; i<nl; i++) {
		//cout << i << " :::  ";
		getline(file, line);
		istringstream iss(line);
		iss >> u >> v >> w;
		//cout << u << " " << v << " " << w << endl;
		addArc(new WeightedArc(u,v,w));
	}

}

EdgeWeightedDigraph::~EdgeWeightedDigraph() {
	delete[] adjacent;
}


int EdgeWeightedDigraph::getSize() {
	return size;
}

int EdgeWeightedDigraph::getOrder() {
	return order;
}

void EdgeWeightedDigraph::addArc(WeightedArc *e) {
	adjacent[e->getFrom()].push_back(e);
	size++;
}


list<WeightedArc *> & EdgeWeightedDigraph::adj(int v) const{
	if (v < 0 || v >= size)  {
		throw invalid_argument ("Invalid argument");
	}
	return adjacent[v];
}

string EdgeWeightedDigraph::toString() {
	string result;

	result = NumberToString(order) + "\n";
	result.append(NumberToString(size) + "\n");

	for (int i=0; i<order; i++) {
		result.append(NumberToString(i) + ": ");
		for (auto v : adjacent[i]) {
			ostringstream s;
			s  << *v;
			result.append(s.str() + ", ");
		}
		result.append("\n");
	}


	return result;
}
} /* namespace std */
