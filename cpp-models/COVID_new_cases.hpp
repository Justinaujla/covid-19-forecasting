/*
 * COVID_new_cases.hpp
 *
 *  Created on: Mar. 5, 2021
 *      Author: justi
 */
#include "latest_datum.hpp"
#include "linear_interpolate.hpp"

#ifndef COVID_NEW_CASES_HPP_
#define COVID_NEW_CASES_HPP_

//Function for COVID predictions

class COVID_new_cases {
  private:
	latest_datum obj{};
	linear_interpolate obj2{};
  public:
    double next_datum( double x );
};

double COVID_new_cases::next_datum( double x ) {
	return obj2.forecast(x);
}

#endif /* COVID_NEW_CASES_HPP_ */
