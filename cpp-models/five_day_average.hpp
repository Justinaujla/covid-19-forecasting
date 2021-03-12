/*
 * five-day-average.hpp
 *
 *  Created on: Mar. 6, 2021
 *      Author: justi
 */

#ifndef FIVE_DAY_AVERAGE_HPP_
#define FIVE_DAY_AVERAGE_HPP_

class five_day_average {
  private:
	double arr[5]{0,0,0,0,0};
	int size = 5;
	double avg{0};
  public:
    double forecast( double x, double weight[] , int thresh);
};

double five_day_average::forecast( double x, double weight[], int thresh) {
	double newVal = x;

	// Threshold for new data variance
	if((std::abs(avg-x)/(double)avg)*100 >= thresh){
		newVal = std::abs(avg+x)/2.0;
	}

	// Reset average
	avg = 0;

	// Push all values down one position in the array
	for( int i{0}; i < size - 1; i++ ){
		arr[i] = arr[i+1];
	}

	// Insert new value at head of array
	arr[size-1] = newVal;

	// Prediction for next time step's COVID cases with weighting
	for( int i{0}; i < size ; i++ ){
		avg += arr[i]*weight[i];
	}
	return avg;
}

#endif /* FIVE_DAY_AVERAGE_HPP_ */
