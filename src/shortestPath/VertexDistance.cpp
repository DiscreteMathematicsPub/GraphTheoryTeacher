/*
 * VertexDistance.cpp
 *
 *  Created on: 6 juny 2016
 *      Author: roure
 */

#include "VertexDistance.h"

//////////////////////// Vertex Distance /////////////////
VertexDistance::VertexDistance(int v, double d) {
	vertex = v;
	distance = d;
}


bool VertexDistance::operator<(const VertexDistance& right) const {
	return right.distance < distance;
}


int VertexDistance::getVertex() const { return vertex;}
double VertexDistance::getDistance() const {return distance;}



