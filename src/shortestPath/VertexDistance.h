/*
 * VertexDistance.h
 *
 *  Created on: 6 juny 2016
 *      Author: roure
 */

#ifndef SHORTESTPATH_VERTEXDISTANCE_H_
#define SHORTESTPATH_VERTEXDISTANCE_H_

class VertexDistance {
private:
	int vertex;
	double distance;

public:
	VertexDistance(int v, double d);
	bool operator<(const VertexDistance& right) const;

	int getVertex() const;
	double getDistance() const;
};

class VertexDistanceComparison {
public:
	bool operator() (const VertexDistance *lhs, const VertexDistance * rhs) const {
		//we want to prioritize small values
		return lhs->getDistance() > rhs->getDistance();
	}
};

#endif /* SHORTESTPATH_VERTEXDISTANCE_H_ */
