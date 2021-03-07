/*
 * COVID_new_cases.hpp
 *
 *  Created on: Mar. 5, 2021
 *      Author: justi
 */
#include "latest_datum.hpp"
#include "ten_day_average.hpp"
#include "five_day_average.hpp"
#include "linear_interpolate.hpp"
#include "linear_least_square.hpp"


#ifndef COVID_NEW_CASES_HPP_
#define COVID_NEW_CASES_HPP_

//Function for COVID predictions

class COVID_new_cases {
  private:
	latest_datum obj{};
	linear_interpolate obj2{};
	ten_day_average obj3{};
	five_day_average obj4{};
	linear_least_square obj5{};
  public:
    double next_datum( double x, double weight[] , int thresh);
};

double COVID_new_cases::next_datum( double x , double weight[], int thresh) {
	return obj5.forecast2(x);
}

#endif /* COVID_NEW_CASES_HPP_ */
