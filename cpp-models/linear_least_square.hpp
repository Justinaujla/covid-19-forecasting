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
    double forecast( double x );
    double forecast2( double x );
};

double linear_least_square::forecast( double x ) {
	double newVal = x;
	if((std::abs(est-x)/(double)est)*100 >= 30){
		newVal = std::abs(est+x)/2.0;
	}
	for( int i{0}; i < size - 1; i++ ){
		arr[i] = arr[i+1];
	}
	arr[size-1] = newVal;
	est = -0.4*arr[0]-0.1*arr[1]+0.2*arr[2]+0.5*arr[3]+0.8*arr[4];
	return est;
}

double linear_least_square::forecast2( double x ) {
	double newVal = x;
	if((std::abs(est-x)/(double)est)*100 >= 30){
		newVal = std::abs(est+x)/2.0;
	}
	for( int i{0}; i < size - 1; i++ ){
			arr[i] = arr[i+1];
		}
	arr[size-1] = newVal;
	est = 0.6*arr[0]-0.6*arr[1]-0.8*arr[2]+1.8*arr[4];
	return est;
}


#endif /* LINEAR_LEAST_SQUARE_HPP_ */
