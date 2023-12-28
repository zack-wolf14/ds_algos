#include<iostream>
#include<math.h>
#include<tuple>
using namespace std;

double f(double mu, double sigma2, double x)
{
    double prob =  1.0 / sqrt(2.0 * M_PI * sigma2) * exp(-0.5 * pow((x - mu), 2.0) / sigma2);
    return prob;
}
tuple<double, double> measurement_update(double mean1 , double var1, double mean2, double var2)
{
    double newMean = (mean1*var2 + mean2*var1)/(var1+var2);
    double newVar = 1/((1/var1)+(1/var2));

    return make_tuple(newMean, newVar);
}

tuple<double, double> state_estimation(double mean1, double var1, double mean2, double var2)
{
    double newMean = mean1+mean2;
    double newVar = var1+ var2;

    return make_tuple(newMean, newVar);
}
int main()
{   int n = 5;
     //Measurements and measurement variance
    double measurements[n] = { 5, 6, 7, 9, 10 };
    double measurement_sig = 4;
    
    //Motions and motion variance
    double motion[n] = { 1, 1, 2, 1, 1 };
    double motion_sig = 2;
    
    //Initial state
    double mu = 1000;
    double sig = 10;
    double newMean, newVar;
    double stateMean, stateVar;

    for (int i = 0; i<n; i++)
    {
        tie(newMean, newVar) = measurement_update(mu, sig, measurements[i], measurement_sig);
        // Apply a measurment update
        printf("update:  [%f, %f]\n", newMean, newVar);
        
        tie(stateMean, stateVar) = state_estimation(newMean, newVar, motion[i], motion_sig);
        // Apply a state prediction
        printf("predict: [%f, %f]\n", stateMean, stateVar);

        mu = stateMean;
        sig = stateVar;
        
    }

    return 0;
}