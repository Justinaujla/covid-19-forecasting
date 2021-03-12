#pragma once

class COVID_new_cases {
  private:
	double weights[5]{0.25, 0.0, 0.0, 0.0, 0.75};
	double delta = 0.05;
	double arr[5]{0,0,0,0,0};
	int size = 5;
	double threshold = 40;
	double avg = 0;
  public:
    double next_datum( double x );
    bool at_extreme() const;
};

// Five day moving weighted average model - Best performance
double COVID_new_cases::next_datum( double x ) {
	double newVal = x;

	// Threshold for new data variance
	if((std::abs(avg-x)/(double)avg)*100 >= threshold ){
		newVal = (avg+x)/2.0;
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
		avg += arr[i]*weights[i];
	}

	return avg;
}

bool COVID_new_cases::at_extreme() const {
  return false;
}
