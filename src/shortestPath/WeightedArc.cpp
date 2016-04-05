/*
 * WeightedEdge.cpp
 *
 *  Created on: 4 abr. 2016
 *      Author: roure
 */

#include "WeightedArc.h"

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>


namespace std {
template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }



WeightedArc::WeightedArc(int v, int w, double weight) {
	this->from = v;
	this->to = w;
	this->weight = weight;
}

WeightedArc::~WeightedArc() {
}

double WeightedArc::getWeight() const{
	return weight;
}

int WeightedArc::getFrom() const{
	return from;
}

int WeightedArc::getTo() const{
	return to;
}

// don't know why but must be declared outside the class. Otherwise, it seems not to recognize parameters
std::ostream & operator<<(std::ostream & Str, WeightedArc const & e) {

  Str << NumberToString(e.getFrom()) << " " << NumberToString(e.getTo()) << " " << NumberToString(e.getWeight());
  return Str;
}


}

