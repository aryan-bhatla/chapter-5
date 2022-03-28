#include "matlib.h"
#include <cmath>

double hornerFunction(double x, double a0, double a1) 
{
    return a0 + x * a1;
}

double hornerFunction(double x, double a0, double a1, double a2) 
{
    return a0 + x * hornerFunction(x, a1, a2);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3) 
{
    return a0 + x * hornerFunction(x, a1, a2, a3);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5)
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6) 
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7) 
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7);
}

double hornerFunction(double x, double a0, double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8) 
{
    return a0 + x * hornerFunction(x, a1, a2, a3, a4, a5, a6, a7, a8);
}


double norminv(double x) 
{
    
    double y = x - 0.5;
    if (y<0.42 && y>-0.42) 
    {
        double r = y * y;
        return y * hornerFunction(r, a0, a1, a2, a3) / hornerFunction(r, 1.0, b1, b2, b3, b4);
    }
    else 
    {
        double r;
        if (y < 0.0) 
        {
            r = x;
        }
        else 
        {
            r = 1.0 - x;
        }
        double s = log(-log(r));
        double t = hornerFunction(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);
        if (x > 0.5) 
        {
            return t;
        }
        else 
        {
            return -t;
        }
    }   
}

double normcdf(double x) 
{
    
    if (x < 0) 
    {
        return 1 - normcdf(-x);
    }

    double k = 1 / (1 + 0.2316419 * x);
    double poly = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    double approx = 1.0 - 1.0 / sqrt((2*PI)) * exp(-0.5 * x * x) * poly;
    
    return approx;

}


double normcdfHorner(double x) 
{
    if (x <= 0) 
    {
        return 1 - normcdf(-x);
    }
    double k = 1 / (1 + 0.2316419 * x);
    double poly = hornerFunction(k, 0.0, 0.319381530, -0.356563782, 1.781477937, -1.821255978, 1.330274429);
    double approx = 1.0 - 1.0 / sqrt(2*PI) * exp(-0.5 * x * x) * poly;
    return approx;
}


double blackScholesCallPrice(double strike, double timeToMaturity, double spot, double volatility, double riskFreeRate) 
{
    double numerator = log(spot / strike) + (riskFreeRate + volatility * volatility * 0.5) * timeToMaturity;
    double denominator = volatility * sqrt(timeToMaturity);
    double d1 = numerator / denominator;
    double d2 = d1 - denominator;
    double t1 = normcdf(d1) * spot;
    double t2 = normcdf(d2) * strike * exp(-riskFreeRate * timeToMaturity);
    return t1 - t2;
}
