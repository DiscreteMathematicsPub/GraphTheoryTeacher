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
#include "graph/Cycle.h"
#include "minSpanningTree/EdgeWeightedGraph.h"
#include "minSpanningTree/LazyPrimMST.h"
#include "minSpanningTree/KruskalMST.h"
#include "shortestPath/EdgeWeightedDigraph.h"
#include "shortestPath/BreadthFirstPathsDigraph.h"
#include "shortestPath/DijkstraSP.h"
#include "shortestPath/AcyclicSP.h"

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
	AdjListGraph g("/Users/josep/workspaceMD/GraphFileDefinition/tinyClassExample.txt");
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
	cout << endl << endl;


	/*
	 *  Connected Compoents
	 */

	AdjListGraph k("/Users/josep/workspaceMD/GraphFileDefinition/tinyG.txt");
	ConnectedComponents cc(k);

	cout << "Number of connected components: " << cc.numberComponents() << endl;
	cout << "connected 0 - 4: " << cc.connected(0,4) << " id[0], id[4]: " << cc.componentId(0) << ", " << cc.componentId(4)<< endl;
	cout << "connected 0 - 7: " << cc.connected(0,7) << " id[0], id[7]: " << cc.componentId(0) << ", " << cc.componentId(7)<< endl;
	cout << endl;

	/*
	 *   Cycle detection
	 */
	//AdjListGraph kk("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\oneArc.txt");
	cout << "Cycles:" << endl;
	Cycle cg(k);
	cout << "Has Cycles: " << cg.hasCycle() << endl;
	if (cg.hasCycle()) {
		cout << "Cycle: ";
		printStack(cg.getCycle());
	}
	cout << endl;

	/*
	 * Bipartite
	 */
	cout << "Bipartite:" << endl;
	//AdjListGraph gbp("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\oneArc.txt");
	AdjListGraph gbp("/Users/josep/workspaceMD/GraphFileDefinition/bipartite.txt");
	//AdjListGraph gbp("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyG.txt");
	Bipartite bp(gbp);
	for (int i=0; i<gbp.getOrder(); i++) {
		cout << i << " col: " << bp.getColor(i) << endl;
	}
	if (!bp.isBipartite()) {
		cout << "odd cycle: " ;
		printStack(bp.oddCycle());
	}
	cout << endl;



	/*
	 * Digraph
	 */
	//tinyDG

	//DigraphAdjList kk("C:\\Users\\roure\\workspaceCPP\\GraphFileDef\\tinyDGnoCycle.txt");
	DigraphAdjList kk("/Users/josep/workspaceMD/GraphFileDefinition/tinyDG.txt");
	cout << "kk: \n" << kk.toString() << endl;
	cout << "order: " << kk.getOrder() << endl;
	cout << "size: " << kk.getSize() << endl;


	/*
	 * Directed Depth First Path
	 */

	DirectedDepthFirstPaths ddfp = DirectedDepthFirstPaths(kk,0);
	for (int i = 0; i < kk.getOrder(); i++)  {
		list<int> paths = ddfp.pathTo(i);
		cout << endl << "Directed Depth First Path. From 0 to " << i << ":  ";
		printPath(paths, i);
	}
	cout <<endl;

	DigraphAdjList dg("/Users/josep/workspaceMD/GraphFileDefinition/tinyDGnoCycle.txt");
	DirectedCycle dcycle = DirectedCycle(dg);
	if (dcycle.hasCycle()) {
		printStack(dcycle.getCycle());
		cout << endl;
	}
	else {
		cout << "There is no directed cycle" << endl;
	}

	// Digraph pre, post, reversePost orders
	cout << "dg: \n" << dg.toString() << endl;
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
	EdgeWeightedGraph tewg("/Users/josep/workspaceMD/GraphFileDefinition/tinyEWG.txt");
	cout << "tewg: \n" << tewg.toString() << endl;
	cout << "order: " << tewg.getOrder() << endl;


	LazyPrimMST mstTreePrim(tewg);
	cout << "Lazy Prim MST: " << endl;
	for (auto e : mstTreePrim.getMST()) {
		cout << *e << endl;

	}
	cout << endl;

	KruskalMST mstTreeK(tewg);
	cout << "Kruskal MST: " << endl;
	for (auto e : mstTreeK.getMST()) {
		cout << *e << endl;

	}
	/*
	 * Edge Weighted DiGraph
	 */

	//tinyEWD
	cout << endl;
	EdgeWeightedDigraph tewd("/Users/josep/workspaceMD/GraphFileDefinition/tinyEWD.txt");
	cout << "tewd: \n" << tewd.toString() << endl;

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
		list<WeightedArc *> paths = dsp.pathTo(i);
		cout << endl << "DijkstraSP. From 4 to " << i << ":  ";
		for (auto e : paths) {
			cout << *e << ", ";
		}
	}

	//tinyEWD
	cout << endl;
	EdgeWeightedDigraph tewdag("/Users/josep/workspaceMD/GraphFileDefinition/tinyEWDAG.txt");
	cout << "tewdag: \n" << tewd.toString() << endl;

	AcyclicSP asp = AcyclicSP(tewdag,4);
	for (int i = 0; i < tewdag.getOrder(); i++)  {
		list<WeightedArc *> paths = asp.pathTo(i);
		cout << endl << "AcyclicSP. From 4 to " << i << ":  ";
		for (auto e : paths) {
			cout << *e << ", ";
		}
	}

	return 0;
}
