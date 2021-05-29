#include <cstdio> //printf
#include <cmath> //cos, std::abs

double f(double x) { return cos(x) - x; }

void secant(double p0, double p1, double TOL, int Nmax) {
    double p = 0; //aproximación actual
    for(int i = 0; i < Nmax; i++) {
        p = p1 - f(p1) * ( p1 - p0) / ( f(p1) - f(p0) );
        printf("%d\t%.10f\t%.10f\t%.16f\t%.20f\n", i, p0, p1, p, std::abs(p - p1));
        if(std::abs(p - p1) < TOL) break;
        p0 = p1; p1 = p;
    }
}

int main() {
    secant(0.4, 0.5, 10e-20, 1000000000);
    return 0;
}