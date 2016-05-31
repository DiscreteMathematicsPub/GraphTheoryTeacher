/*
 * WeightedEdge.h
 *
 *  Created on: 4 abr. 2016
 *      Author: roure
 */

#ifndef MINSPANNINGTREE_WEIGHTEDARC_H_
#define MINSPANNINGTREE_WEIGHTEDARC_H_

#include <string>
namespace std {

class WeightedArc {

public:

	WeightedArc(int v, int w, double weight);
	virtual ~WeightedArc();

	double getWeight() const;
	int getFrom() const;
	int getTo() const;

	friend std::ostream & operator<<(std::ostream & Str, WeightedArc const & e); // this is a friend function. It doesn't belong to the class
private:

	int from;
	int to;
	double weight;

};

/*
 * This class will be used to compare two weighted arcs
 */
class WeightedArcComparison {
public:
	bool operator() (const WeightedArc *lhs, const WeightedArc * rhs) const {
		//we want to prioritize small values
		return lhs->getWeight() > rhs->getWeight();
	}
};


}


#endif /* MINSPANNINGTREE_WEIGHTEDEDGE_H_ */
