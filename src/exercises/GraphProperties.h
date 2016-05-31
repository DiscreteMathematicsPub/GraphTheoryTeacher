/*
 * GraphProperties.h
 *
 *  Created on: 19 maig 2016
 *      Author: roure
 */

#ifndef EXERCISES_GRAPHPROPERTIES_H_
#define EXERCISES_GRAPHPROPERTIES_H_

#include <list>

namespace std {

class GraphProperties {
public:
	GraphProperties(AdjListGraph &g);

	int eccentricity(int v);
	int diameter();
	int radius();
	list<int> & center();

	virtual ~GraphProperties();
};

} /* namespace std */



#endif /* EXERCISES_GRAPHPROPERTIES_H_ */
