#include <iostream>
#include <cmath>
#include "data.hpp"
#include "COVID_new_cases.hpp"

// Function declarations
int main();
double test( double array[], unsigned int capacity );


int main() {
 unsigned int const afghanistan_count{ 340 };
 double afghanistan[afghanistan_count]{ 746,298,113,63,202,135,200,210,234,235,119,202,400,272,0,228,214,0,200,185,246,252,154,232,282,0,383,65,163,205,66,360,146,0,224,80,126,58,40,121,86,95,132,76,157,123,0,113
,199,65,81,61,116,135,88,87,59,68,47,0,32,66,129,96,0,10,77,68,62,145,44,7,5,17,14,15,
12,0,35,6,16,25,71,30,0,125,47,0,17,40,99,75,35,34,28,24,26,96,74,20,16,45,38,9,34,19,
3,11,3,55,1,71,0,105,38,97,160,0,3,45,120,7,79,76,215,0,0,39,78,41,67,82,37,0,0,168,71
,0,103,105,106,121,108,13,188,112,140,174,12,219,76,254,285,4,0,85,458,255,59,210,433,
279,348,302,186,319,279,271,351,165,276,460,234,338,310,409,546,346,658,564,783,761,664,
556,656,747,684,542,575,791,582,915,787,758,759,545,680,866,623,580,625,658,591,584,
782,540,531,492,581,408,262,0,1063,113,259,280,285,369,255,215,171,168,330,190,235,134,
164,222,122,124,172,68,112,70,105,84,61,35,88,63,51,10,70,49,58,52,34,37,61,56,30,38,
29,35,0,43,26,25,27,8,15,16,0,33,2,6,10,0,2,0,0,1,5,6,3,3,3,0,0,0,0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0 };
 std::cout << test( afghanistan, afghanistan_count ) << std::endl;
 return 0;
}
// Function definitions
//int main() {
//  for ( std::size_t k{0}; k < DATA_MAX; ++k ) {
//    std::cout << test( data[k], 1000 )
//              << std::endl;
//  }
// return 0;
//}
// Calculate the root-mean-squared-error (RMSE).

// Calculate the root-mean-squared-error (RMSE).
double test( double array[], unsigned int capacity ) {
 COVID_new_cases obj{};
 double squared_error{ 0.0 };
 for ( unsigned int k{capacity - 1}; k > 0; --k ) {
 double prediction { obj.next_datum( array[k] ) };
squared_error += std::pow( prediction - array[k - 1], 2.0 );
 }
 return std::sqrt( squared_error/capacity );
}
//double test( double array[],
//             unsigned int capacity ) {
//  COVID_new_cases obj{};
//  double squared_error{ 0.0 };
//
//  for ( unsigned int k{capacity - 1}; k > 0; --k ) {
//    double prediction { obj.next_datum( array[k] ) };
//    squared_error +=
//        std::pow( prediction - array[k - 1], 2.0 );
//  }
//
//  return std::sqrt( squared_error/capacity );
//}
