/*
 * ten_day_average.hpp
 *
 *  Created on: Mar. 6, 2021
 *      Author: justi
 */

#ifndef TEN_DAY_AVERAGE_HPP_
#define TEN_DAY_AVERAGE_HPP_

class ten_day_average {
  private:
	double arr[10]{0,0,0,0,0,0,0,0,0,0};
	double avg{0};
  public:
    double forecast( double x );
};

double ten_day_average::forecast( double x ) {
	for( int i{0}; i < 9; i++ ){
		arr[i] = arr[i+1];
	}
	arr[9] = x;
	for( int i{0}; i < 10; i++ ){
		avg += arr[i];
	}
	return avg/10;
}


#endif /* TEN_DAY_AVERAGE_HPP_ */
