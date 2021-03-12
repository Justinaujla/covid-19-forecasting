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
	int size = 10;
	double avg{0};
  public:
    double forecast( double x );
};

double ten_day_average::forecast( double x ) {
	// Reset average
	avg = 0;

	// Push all values down one position in the array
	for( int i{0}; i < size - 1; i++ ){
		arr[i] = arr[i+1];
	}

	// Insert new value at head of array
	arr[size-1] = x;

	// Prediction for next time step's COVID cases
	for( int i{0}; i < size ; i++ ){
		avg += arr[i];
	}
	avg = avg/(double)size;
	return avg;
}

#endif /* TEN_DAY_AVERAGE_HPP_ */
