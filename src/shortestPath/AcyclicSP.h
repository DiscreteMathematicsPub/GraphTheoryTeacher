/*
 * AcyclicSP.h
 *
 *  Created on: 6 juny 2016
 *      Author: roure
 */

#ifndef SHORTESTPATH_ACYCLICSP_H_
#define SHORTESTPATH_ACYCLICSP_H_

#include "VertexDistance.h"
#include "WeightedArc.h"
#include "EdgeWeightedDigraph.h"
#include "TopologicalOrder.h"

namespace std {


class AcyclicSP {
private:
	WeightedArc ** edgeTo;	// edgeTo[v] last edge on s - v path
	double * distTo; // distTo[v] the distance form s to v
	TopologicalOrder * topological;

	int s;			// source vertex

	void relax (EdgeWeightedDigraph & g, int v);

public:
	AcyclicSP(EdgeWeightedDigraph & g, int s);
	virtual ~AcyclicSP();

	bool hasPathTo(int v);
	list<WeightedArc *> pathTo(int v);
	int distanceTo(int v);
};

} /* namespace std */


#endif /* SHORTESTPATH_ACYCLICSP_H_ */
