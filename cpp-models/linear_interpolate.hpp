/*
 * linear_interpolate.hpp
 *
 *  Created on: Mar. 5, 2021
 *      Author: justi
 */

#ifndef LINEAR_INTERPOLATE_HPP_
#define LINEAR_INTERPOLATE_HPP_


class linear_interpolate {
  private:
	double y1{0},y2{0},m{0},b{0};
  public:
    double forecast( double x );
};

double linear_interpolate::forecast( double x ) {
	// Simple linear interpolate with last two datum; x-1 and x0
	y1 = y2;
	b = y1;
	y2 = x;

	// Prediction for next time step's COVID cases at x+1
	return 2.0*(y2-y1)+b;
}



#endif /* LINEAR_INTERPOLATE_HPP_ */
