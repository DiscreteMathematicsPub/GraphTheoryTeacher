//============================================================================
// Name        : Desesperate.cpp
// Author      : Josep
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>

#include "graph/AdjListGraph.h"
#include "graph/DigraphAdjList.h"
#include "graph/DepthFirstPaths.h"
#include "graph/DirectedDepthFirstPaths.h"
#include "graph/BreadthFirstPaths.h"
#include "graph/DirectedCycle.h"

using namespace std;

void printPath (list<int> &l, int endVertex) {
	std::list<int>::reverse_iterator iterator;
	for (iterator = l.rbegin(); iterator != l.rend(); ++iterator) {
		cout << *iterator;
		if (*iterator != endVertex)
			cout << " --> ";
	}
}

void printStack(stack<int> &s)
{
    if(s.empty())
    {
        cout << endl;
        return;
    }
    int x= s.top();
    s.pop();
    printStack(s);
    s.push(x);
    cout << x << " ";
 }

int main() {
	/*
	AdjListGraph g(3);

	g.addEdge(0,1);
	g.addEdge(0,2);


	list<int> & l= g.adj(0);

	list<int>::iterator pos, end;
	pos = l.begin();
	while (pos != l.end()) {
		cout << *pos << ", ";
		++pos;
	}
	cout << endl;


	for (auto &elem : l) {
		cout << elem << ", ";
	}
	cout << endl;

	string r = g.toString();
	cout << "g: \n" << r << endl;


	//tinyClassExample //hola
	AdjListGraph k("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyClassExample.txt");
	cout << "k: \n" << k.toString() << endl;
	cout << "order: " << k.getOrder() << endl;

*/
	/*
	 * Depth First Path
	 */
/*
	DepthFirstPaths dfp = DepthFirstPaths(k,0);
	for (int i = 0; i < k.getOrder(); i++)  {
		list<int> paths = dfp.pathTo(i);
		cout << endl << "Depth First Path. From 0 to " << i << ":  ";
		printPath(paths, i);
	}
	cout <<endl;
*/
	/*
	 * Breadth First Path
	 */
	/*
	BreadthFirstPaths bfp = BreadthFirstPaths(k,0);
	for (int i = 0; i < k.getOrder(); i++)  {
		list<int> paths = bfp.pathTo(i);
		cout << endl << "Breadth First Path. From 0 to " << i << ":  ";
		printPath(paths, i);
	}

*/
	/*
	 * Digraph
	 */
	//tinyDG
	DigraphAdjList k("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyDGnoCycle.txt");
	cout << "k: \n" << k.toString() << endl;
	cout << "order: " << k.getOrder() << endl;
	cout << "size: " << k.getSize() << endl;

	/*
	 * Directed Depth First Path
	 */
	DirectedDepthFirstPaths dfp = DirectedDepthFirstPaths(k,0);
	for (int i = 0; i < k.getOrder(); i++)  {
		list<int> paths = dfp.pathTo(i);
		cout << endl << "Directed Depth First Path. From 0 to " << i << ":  ";
		printPath(paths, i);
	}
	cout <<endl;

	DirectedCycle dcycle = DirectedCycle(k);
	if (dcycle.hasCycle()) {
		printStack(dcycle.getCycle());
		cout << endl;
	}
	else {
		cout << "There is no directed cycle" << endl;
	}

	return 0;
}
