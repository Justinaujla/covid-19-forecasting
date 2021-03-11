#include <iostream>
#include <cmath>
#include "data.hpp"
#include "COVID_new_cases.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Function declarations
int main();
double test( double array[], unsigned int capacity , int thresh);
double arr[6][5]{{0.15, 0.0, 0.05, 0.0, 0.8},
				{0.15, 0.05, 0.0, 0.0, 0.8},
				{0.15, 0.05, 0.05, 0.0, 0.75},
				{0.2, 0.0, 0.0, 0.0, 0.8},
				{0.2, 0.0, 0.05, 0.0, 0.75},
				{0.25, 0.0, 0.0, 0.0, 0.75}
};
double weight[5]{0.15, 0.0, 0.05, 0.0, 0.8};
double delta = 0.05;

// Function definitions

void printArray( double arr[]) {
	for( int i = 0; i < 5; i++){
		std::cout << arr[i] << ' ';
	}
}
int main() {
//	string readLine;
//	double best{10000};
//	while(! cin.eof()){
//		getline(cin, readLine);
//		stringstream ss(readLine);
//		int i = 0;
//		while(ss.good()){
//			string substr;
//			getline(ss, substr, ',');
//			weight[i] = stod(substr)*delta;
//			i++;
//		}
////	    for ( int i = 0; i < 4; i++){
////	    	std::cout<< weight[i] << std::endl;
////	    }
//		double a{0};
		int threshold = 40;
//		for(int threshold = 40; threshold >= 40; threshold -= 5){
//			a = 0;
//			for ( std::size_t k{0}; k < DATA_MAX; ++k ) {
//				double i = test( data[k], 1000 , threshold);
//				a +=i;
////				std::cout<< a/DATA_MAX << std::endl;
//			  }
//			if(a/DATA_MAX <= best){
//			  std::cout<< a/DATA_MAX << " ";
//			  printArray(weight);
//			  std::cout << threshold << std::endl;
//			  best = a/DATA_MAX;
//			}
//		}
//
////		}
//
//	}
//			for(int threshold = 100; threshold > 5; threshold = threshold-5){
//				a =0;
//				for ( std::size_t k{0}; k < DATA_MAX; ++k ) {
//					double i = test( data[k], 1000 , threshold);
//	//		    std::cout << i << std::endl;
//					a +=i;
//				  }
////				std::cout << a << std::endl;
//				if(a/DATA_MAX <= best){
//				  std::cout<< a/DATA_MAX << " ";
//				  printArray(weight);
//				  std::cout << threshold << std::endl;
//				  best = a/DATA_MAX;
//				}
//			}
//			int a =0;
			for ( std::size_t k{0}; k < DATA_MAX; ++k ) {
				double i = test( data[k], 1000 , threshold);
		    std::cout << i << std::endl;
//				a +=i;
			}
//				std::cout << a << std::endl;
//			if(a/DATA_MAX <= best){
//			  std::cout<< a/DATA_MAX << " ";
//			  printArray(weight);
//			  std::cout << threshold << std::endl;
//			  best = a/DATA_MAX;
//			}
	return 0;

}
// Calculate the root-mean-squared-error (RMSE).
double test( double array[],
             unsigned int capacity , int thresh) {
  COVID_new_cases obj{};
  double squared_error{ 0.0 };

  for ( unsigned int k{capacity - 1}; k > 0; --k ) {
    double prediction { obj.next_datum( array[k] , arr[5], thresh) };
    squared_error +=
        std::pow( prediction - array[k - 1], 2.0 );
  }

  return std::sqrt( squared_error/capacity );
}
