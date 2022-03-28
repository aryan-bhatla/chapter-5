#pragma once

// These are constants that may be used 
const double  PI = 3.14159265358979;
const double a0 = 2.50662823884;
const double a1 = -18.61500062529;
const double a2 = 41.39119773534;
const double a3 = -25.44106049637;
const double b1 = -8.47351093090;
const double b2 = 23.08336743743;
const double b3 = -21.06224101826;
const double b4 = 3.13082909833;
const double c0 = 0.3374754822726147;
const double c1 = 0.9761690190917186;
const double c2 = 0.1607979714918209;
const double c3 = 0.0276438810333863;
const double c4 = 0.0038405729373609;
const double c5 = 0.0003951896511919;
const double c6 = 0.0000321767881768;
const double c7 = 0.0000002888167364;
const double c8 = 0.0000003960315187;

// The following functions are related to normal distributions 

// Computes the normal cumulative distribution 
double normcdf(double x);

// Computes the inverse normal distribution
double norminv(double x);

// Computes the normal cumulative distribution using Horner Functions
double normcdfHorner(double x);


// The following functions are Horner Functions of various orders. They are used to optimise polynomial evaluation

double hornerFunction(double x, double a0, double a1);

double hornerFunction(double x, double a0, double a1, double a2);

double hornerFunction(double x, double a0, double a1, double a2, double a3);

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4);

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5);

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6);

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7);

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8);


// Computes the Black Scholes Call Price using Black Scholes Model 

double blackScholesCallPrice(double strike, double timeToMaturity, double spot, double volatility, double riskFreeRate);




// The following functions are used for circle computations 

// Computes the area of a circle given the radius 
double area(double radius);

// Computes the circumference of a circle given the radius 
double circumference(double radius);

// Computes the diameter of a circle given the radius;
double diameter(double radius);