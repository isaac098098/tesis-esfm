#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mcd(int a, int b) {
    return b == 0 ? a > 0 ? a : -a : mcd(b, a % b);
}

double u(int n) {
    if(n >= 0)
        return 1.0;
    else
        return 0;
}

double ex(double amp, double n) {
    return pow(amp, -n);
}

double perex(int n, int p, double amp) {
    if(n < 0)
        return ex(amp, -n % p);
    else
        return ex(amp, n % p);
}

int dsum(int n) {
    int sum=0;
    for(int i=1; i<=n; i++)
        if((n % i) == 0)
            sum+=i;
    return sum;
}

int mob(int n) {
    int p=0;
    if (n == 1) {
        return 1;
    }
    if (n%2 == 0) {
        n=n/2;
        p++;
        if (n % 2 == 0)
            return 0;
    }
    for (int i=3; i <= n; i+=2) {
        if (n%i == 0) {
            n = n/i;
            p++;
            if (n % i == 0)
                return 0;
        }
    }
    return (p % 2 == 0) ? 1 : -1;
}

int ram(int r, int n) {
    int sum=0;
    int nr=mcd(n,r);
    for(int d=1; d<=nr; d++)
        if(nr % d == 0)
            sum+=mob(r/d)*d;
    return sum;
}

int main(int argc, char** argv) {
    FILE* div=fopen("plot8.csv", "w");
    /*for(int j=-10; j <= atoi(argv[1]); j++)*/
    /*    fprintf(div, "%d, %d\n", j, mcd(3,j));*/
    for(int j= atoi(argv[1]); j < 0; j++)
        fprintf(div, "%d, %1.5f\n", j, perex(j+3*40, 40, 1.1));
    for(int j=0; j <= atoi(argv[2]); j++)
        fprintf(div, "%d, %1.5f\n", j, perex(j, 40, 1.1));
    fclose(div);
    /*printf("%d\n", ram(atoi(argv[1]), atoi(argv[2])));*/
    return 0;
}

/*fprintf(div, "%d, %1.5f\n", j, 2*cos((2.0/5.0)*j*M_PI)+2*cos((4.0/5.0)*j*M_PI));*/
