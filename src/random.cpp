#include "random.h"

using namespace std;

RandomNumbers :: RandomNumbers(unsigned long int s){
		if(s == 0){
			seed = random_device()();
		}else{
		seed = s;
		rng = std::mt19937(seed);
	}}

void RandomNumbers ::  uniform_double(std::vector<double>& vecteur, double lower, double upper){
	
for(auto&  coord :  vecteur ){
	coord = uniform_double(lower, upper);
}	
	
	};
  
  
  
double RandomNumbers :: uniform_double(double lower, double upper){
	
	
	uniform_real_distribution <double> u_distrib  (lower,upper);
	
	return u_distrib(rng);
	
	};



void RandomNumbers :: normal(std::vector<double>& vecteur, double mean, double sd){
	
	for(auto&  coord :  vecteur ){
	coord = normal(mean, sd);
}	
	
	};


double RandomNumbers :: normal(double mean, double sd){
	normal_distribution <double> n_distrib (mean, sd);
	return n_distrib(rng);
	};


void RandomNumbers :: poisson(std::vector<int>& vecteur, double mean){
	
	for(auto&  coord :  vecteur ){
	coord = poisson(mean);
}	
	
	};


int RandomNumbers :: poisson(double mean){
	
	poisson_distribution<int> p_distrib (mean);
	return p_distrib(rng);
	};
