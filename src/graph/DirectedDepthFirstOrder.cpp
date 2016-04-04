/*
 * DepthFirstPaths.cpp
 *
 *  Created on: 5 febr. 2016
 *      Author: roure
 */

#include "DirectedDepthFirstOrder.h"
#include <iostream>

namespace std {

DirectedDepthFirstOrder::DirectedDepthFirstOrder(DigraphAdjList & g) {
	visited = new bool[g.getOrder()];
	for (int i=0; i<g.getOrder(); i++) {
		visited[i]=false;
	}

	for (int v=0; v<g.getOrder(); v++) {
		if (!visited[v]) dfs(g,v);
	}
}

DirectedDepthFirstOrder::~DirectedDepthFirstOrder() {
	delete[]  visited;
}

void DirectedDepthFirstOrder::dfs(DigraphAdjList & g, int v) {

	pre.push_back(v);  //used as a list

	visited[v] = true;
	for (auto & w : g.adj(v)) {
		if (!visited[w]) {
			dfs(g,w);
		}
	}

	post.push_back(v); // used as a list
	revPost.push_front(v); // used as a stack
}

deque<int> & DirectedDepthFirstOrder::preOrder() {
	return pre;
}

deque<int> & DirectedDepthFirstOrder::postOrder() {
	return post;
}

deque<int> & DirectedDepthFirstOrder::reversePostOrder() {
	return revPost;
}


} /* namespace std */
