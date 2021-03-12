/*
 * quadratic_least_square.hpp
 *
 *  Created on: Mar. 12, 2021
 *      Author: justi
 */

#ifndef QUADRATIC_LEAST_SQUARE_HPP_
#define QUADRATIC_LEAST_SQUARE_HPP_

class quadratic_least_square {
  private:
	double arr[5]{0,0,0,0,0};
	double est{0};
	int size = 5;
  public:
    double forecast( double x, int tresh );
};

double quadratic_least_square::forecast( double x, int tresh ) {
	double newVal = x;

	// Threshold for new data variance
	if((std::abs(est-x)/(double)est)*100 >= tresh){
		newVal = (est+x)/2.0;
	}

	// Push all values down one position in the array
	for( int i{0}; i < size - 1; i++ ){
			arr[i] = arr[i+1];
		}

	// Insert new value at head of array
	arr[size-1] = newVal;

	// Prediction for next time step's COVID cases
	est = 0.6*arr[0]-0.6*arr[1]-0.8*arr[2]+1.8*arr[4]; // Coefficients and equation derived in ReadMe
	return est;
}

#endif /* QUADRATIC_LEAST_SQUARE_HPP_ */
