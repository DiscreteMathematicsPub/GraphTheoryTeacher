/*
 * DigraphAdjList.cpp
 *
 *  Created on: 22 març 2016
 *      Author: roure
 */

#include "DigraphAdjList.h"
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



DigraphAdjList::DigraphAdjList(int order) {
	adjacent =  new list<int>[order];
	this->order = order;
	size = 0;
}

DigraphAdjList::DigraphAdjList(string fileName) {
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

DigraphAdjList::~DigraphAdjList() {
	delete[] adjacent;
}


int DigraphAdjList::getSize() {
	return size;
}

int DigraphAdjList::getOrder() {
	return order;
}

void DigraphAdjList::addEdge(int v, int w) {
	if (v < 0 || v >= order || w <0 || w >= order) {
		throw invalid_argument("Invalid argument");
	}
	adjacent[v].push_back(w);
	size++;
}


list<int> & DigraphAdjList::adj(int v) const{
	if (v < 0 || v >= size)  {
		throw invalid_argument ("Invalid argument");
	}
	return adjacent[v];
}

DigraphAdjList DigraphAdjList::reverse(DigraphAdjList dg) {
	DigraphAdjList rev(dg.getOrder());

	for (int v = 0; v < dg.getOrder(); v++) {
		for (auto &w : adjacent[v]) {
			addEdge(w,v);
		}
	}
	return rev;
}

string DigraphAdjList::toString() {
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



