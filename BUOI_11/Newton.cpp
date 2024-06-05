#include<bits/stdc++.h>
#define EPSILON 0.00001
#define E_VAL 2.71828
using namespace std;
 
// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    // return x*x*x - x*x + 2;
    return 3*exp((pow(x,5)- pow(x,4))) + pow(x, 2) - 20*x + log(x+25) - 10;
}
 
// Derivative of the above function which is 3*x^x - 2*x
double derivFunc(double x)
{
    return 3*exp((x+1)*pow(x, 4))*(5*x - 4)*pow(x,3) + 2*x + 1/(x+25) - 20;
}
double derivOfderivFunc(double x)
{
    double term1 = 15 * exp(x * x * x * x * (-1 + x)) * pow(x, 3);
    double term2 = 3 * exp(x * x * x * x * (-1 + x)) * (-4 + 5 * x) * (x * x * x * x + 4 * x * x * x * (-1 + x)) * x * x * x;
    double term3 = 9 * exp(x * x * x * x * (-1 + x)) * (-4 + 5 * x) * pow(x, 2);
    double term4 = -1 / pow(25 + x, 2);
    return term1 + term2 + term3 + term4 + 2;
}
// Function to find the root
void newtonRaphson(double x, int n)
{
    double temp = x;
    double h = 0;
    // while (abs(h) >= EPSILON)
    // {
    //     h = func(x)/derivFunc(x);
  
    //     // x(i+1) = x(i) - f(x) / f'(x)  
    //     x = x - h;
    // }
    for (int i = 0; i<n; i++)
    {
        h = derivFunc(temp)/derivOfderivFunc(temp);
        temp = temp - h;
        if (fabs(h) > EPSILON) break;
  
    //     // x(i+1) = x(i) - f(x) / f'(x)  

    }
 
    cout << "The value of the root is : " << temp;
}
 
// Driver program to test above
int main()
{
    double x0 = 0; // Initial values assumed
    newtonRaphson(x0, 10000);
    return 0;
}