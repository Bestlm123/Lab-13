#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double arr[], int n, double result[]) {
    double sum = 0, sumSq = 0, prod = 1, sumRec = 0;
    double maxVal = arr[0], minVal = arr[0];

    for (int i = 0; i < n; i++) {
        double x = arr[i];
        sum += x;
        sumSq += x * x;
        prod *= x;
        sumRec += 1.0 / x;

        if (x > maxVal) maxVal = x;
        if (x < minVal) minVal = x;
    }

    double mean = sum / n;
    double variance = (sumSq / n) - (mean * mean);
    double stdDev = sqrt(variance);
    double geoMean = pow(prod, 1.0 / n);
    double harmMean = n / sumRec;

    result[0] = mean;        
    result[1] = stdDev;      
    result[2] = geoMean;     
    result[3] = harmMean;    
    result[4] = maxVal;      
    result[5] = minVal;      
}
