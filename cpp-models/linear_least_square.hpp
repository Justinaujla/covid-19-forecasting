/*
 * linear_least_square.hpp
 *
 *  Created on: Mar. 6, 2021
 *      Author: justi
 */

#ifndef LINEAR_LEAST_SQUARE_HPP_
#define LINEAR_LEAST_SQUARE_HPP_

class linear_least_square {
  private:
	double arr[5]{0,0,0,0,0};
	double est{0};
	int size = 5;
  public:
    double forecast( double x, int thresh );
};

double linear_least_square::forecast( double x, int thresh ) {
	double newVal = x;

	// Threshold for new data variance
	if((std::abs(est-x)/(double)est)*100 >= thresh){
		newVal = (est+x)/2.0;
	}

	// Push all values down one position in the array
	for( int i{0}; i < size - 1; i++ ){
		arr[i] = arr[i+1];
	}

	// Insert new value at head of array
	arr[size-1] = newVal;

	// Prediction for next time step's COVID cases
	est = -0.4*arr[0]-0.1*arr[1]+0.2*arr[2]+0.5*arr[3]+0.8*arr[4]; // Coefficients and equation derived in ReadMe
	return est;
}

#endif /* LINEAR_LEAST_SQUARE_HPP_ */
