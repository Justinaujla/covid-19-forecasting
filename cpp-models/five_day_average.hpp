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
	if((std::abs(avg-x)/(double)avg)*100 >= thresh){
		newVal = std::abs(avg+x)/2.0;
	}
	avg = 0;
	for( int i{0}; i < size - 1; i++ ){
		arr[i] = arr[i+1];
	}
	arr[size-1] = newVal;

	for( int i{0}; i < size ; i++ ){
		avg += arr[i]*weight[i];
//		avg += arr[i];
	}
//	avg = avg/(double)size;
	return avg;
}

#endif /* FIVE_DAY_AVERAGE_HPP_ */
