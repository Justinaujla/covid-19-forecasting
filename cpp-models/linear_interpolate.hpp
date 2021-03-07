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
	double y1{0},y2{0},x1{0},x2{0},m{0},b{0};
  public:
    double forecast( double x );
};

double linear_interpolate::forecast( double x ) {
	// TODO
	return 0;
}



#endif /* LINEAR_INTERPOLATE_HPP_ */
