//============================================================================
// Name        : Main.cpp
// Author      : Josep
// Version     :
//============================================================================

#include <iostream>
#include <list>

#include "digraph/DigraphAdjList.h"
#include "digraph/DirectedCycle.h"
#include "digraph/DirectedDepthFirstOrder.h"
#include "digraph/DirectedDepthFirstPaths.h"
#include "graph/AdjListGraph.h"
#include "graph/DepthFirstPaths.h"
#include "graph/BreadthFirstPaths.h"
#include "graph/ConnectedComponents.h"
#include "graph/Bipartite.h"
#include "minSpanningTree/EdgeWeightedGraph.h"
#include "minSpanningTree/LazyPrimMST.h"
#include "shortestPath/EdgeWeightedDigraph.h"
#include "shortestPath/BreadthFirstPathsDigraph.h"
#include "shortestPath/DijkstraSP.h"

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

*/

	//tinyClassExample //hola
	AdjListGraph g("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyClassExample.txt");
	cout << "g: \n" << g.toString() << endl;
	cout << "order: " << g.getOrder() << endl;


	/*
	 * Depth First Path
	 */

	DepthFirstPaths dfp = DepthFirstPaths(g,0);
	for (int i = 0; i < g.getOrder(); i++)  {
		list<int> paths = dfp.pathTo(i);
		cout << endl << "Depth First Path. From 0 to " << i << ":  ";
		printPath(paths, i);
	}
	cout <<endl;

	/*
	 * Breadth First Path
	 */

	BreadthFirstPaths bfp = BreadthFirstPaths(g,0);
	for (int i = 0; i < g.getOrder(); i++)  {
		list<int> paths = bfp.pathTo(i);
		cout << endl << "Breadth First Path. From 0 to " << i << ":  ";
		printPath(paths, i);
	}
	cout << endl;


	/*
	 *  Connected Compoents
	 */

	AdjListGraph k("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyG.txt");
	ConnectedComponents cc(k);

	cout << "Number of connected components: " << cc.numberComponents() << endl;
	cout << "connected 0 - 4: " << cc.connected(0,4) << " id[0], id[4]: " << cc.componentId(0) << ", " << cc.componentId(4)<< endl;
	cout << "connected 0 - 7: " << cc.connected(0,7) << " id[0], id[7]: " << cc.componentId(0) << ", " << cc.componentId(7)<< endl;
	cout << endl;


	/*
	 * Bipartite
	 */
	//AdjListGraph g("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\bipartite.txt");
	AdjListGraph gbp("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyG.txt");
	Bipartite bp(gbp);
	for (int i=0; i<gbp.getOrder(); i++) {
		cout << i << " col: " << bp.getColor(i) << endl;
	}
	printStack(bp.oddCycle());



	/*
	 * Digraph
	 */
	//tinyDG
	/*
	DigraphAdjList k("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyDGnoCycle.txt");
	cout << "k: \n" << k.toString() << endl;
	cout << "order: " << k.getOrder() << endl;
	cout << "size: " << k.getSize() << endl;

*/
	/*
	 * Directed Depth First Path
	 */
	/*
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
*/
	// Digraph pre, post, reversePost orders
	DigraphAdjList dg("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyDGnoCycle.txt");
	DirectedDepthFirstOrder ddfo = DirectedDepthFirstOrder(dg);
	cout << "Preorder: ";
	for (auto &v : ddfo.preOrder()) {
		cout << v << ", ";
	}
	cout << endl;

	cout << "Postorder: ";
	for (auto &v : ddfo.postOrder()) {
		cout << v << ", ";
	}
	cout << endl;

	cout << "Reverse Post Order: ";
	for (auto &v : ddfo.reversePostOrder()) {
		cout << v << ", ";
	}
	cout << endl;


	/*
	 * Edge Weighted Graph
	 */

	//tinyEWG
	cout << endl;
	EdgeWeightedGraph tewg("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyEWG.txt");
	cout << "tewg: \n" << tewg.toString() << endl;
	cout << "order: " << tewg.getOrder() << endl;


	LazyPrimMST mstTree(tewg);
	cout << "MST: " << endl;
	for (auto e : mstTree.getMST()) {
		cout << *e << endl;

	}

	/*
	 * Edge Weighted DiGraph
	 */

	//tinyEWD
	cout << endl;
	EdgeWeightedDigraph tewd("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyEWD.txt");
	cout << "tewd: \n" << tewd.toString() << endl;
	cout << "order: " << tewd.getOrder() << endl;

	BreadthFirstPathsDigraph bfpd = BreadthFirstPathsDigraph(tewd,4);
	for (int i = 0; i < tewd.getOrder(); i++)  {
		list<WeightedArc *> paths = bfpd.pathTo(i);
		cout << endl << "Breadth First Path Digraph. From 4 to " << i << ":  ";
		for (auto e : paths) {
			cout << *e << ", ";
		}
	}

	DijkstraSP dsp = DijkstraSP(tewd,4);
	for (int i = 0; i < tewd.getOrder(); i++)  {
		list<WeightedArc *> paths = bfpd.pathTo(i);
		cout << endl << "Breadth First Path Digraph. From 4 to " << i << ":  ";
		for (auto e : paths) {
			cout << *e << ", ";
		}
	}


	return 0;
}
