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
#include "quadratic_least_square.hpp"


#ifndef COVID_NEW_CASES_HPP_
#define COVID_NEW_CASES_HPP_

//Function for COVID predictions

class COVID_new_cases {
  private:
	latest_datum ld_model{};
	linear_interpolate li_model{};
	ten_day_average tda_model{};
	five_day_average fda_model{};
	linear_least_square lls_model{};
	quadratic_least_square qls_model{};

  public:
    double next_datum( double x, double weight[] , int thresh);
};

double COVID_new_cases::next_datum( double x , double weight[], int thresh) {
	double forecast{0};
	// Example model input:
	// forecast = model.forecast(double, double *, int)
	return forecast;
}

#endif /* COVID_NEW_CASES_HPP_ */
