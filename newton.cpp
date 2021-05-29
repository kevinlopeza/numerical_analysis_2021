#include <cstdio> //printf
#include <cmath> //sin, cos

double f(double x) { return cos(x) + 2.0*sin(x) + x*x; }
double df(double x) { return -sin(x) + 2.0*cos(x) + 2.0*x; }

void Newton(double p0, double TOL, int Nmax){
    double p = 0; //p will hold the current approximation
    for(int i=0; i<Nmax; i++){
        p = p0 - f(p0)/df(p0);
        printf("%d\t%.10f\t%.10f\t%.10f\n", i, p0, p, std::abs(p - p0));
        if(std::abs(p - p0) < TOL) break;
        p0 = p;
    }
}

int main() {
    Newton(0.0, 10e-10, 100);   
    return 0;
}