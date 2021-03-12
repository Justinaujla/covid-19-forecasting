/*
 * latest_datum.hpp
 *
 *  Created on: Mar. 5, 2021
 *      Author: justi
 */

#ifndef LATEST_DATUM_HPP_
#define LATEST_DATUM_HPP_

class latest_datum {
  private:
  public:
    double forecast( double x );
};

double latest_datum::forecast( double x ) {
	// Prediction for next time step's COVID cases; assume it's similar to last time step's cases
	return x;
}


#endif /* LATEST_DATUM_HPP_ */
