#include <stdio.h>
#include <math.h>

struct vectorb {
    double x;
    double y;
    double a;
    double l;
};

// дек дан x,y
// полярная a,l
double dl(double x, double y) {
    int a = sqrt(x * x + y * y);
    return a;
}

int main() {
    struct vectorb a;
    struct vectorb b;
    scanf("%lf %lf", &a.a, &a.l);
    scanf("%lf %lf", &b.a, &b.l);
    a.x = a.l * (cos(a.a));
    a.y = a.l * (sin(a.a));
    b.x = b.l * (cos(b.a));
    b.y = b.l * (sin(b.a));
    printf("%lf %lf\n", a.x, a.y);
    printf("%lf\n", dl(a.x, a.y));
    double xsum = a.x + b.x;
    double ysum = a.y + b.y;
    printf("%lf %lf\n", xsum, ysum);
    //парал
    double k1 = atan(a.l) * 180 / M_PI;
    double k2 = atan(b.l) * 180 / M_PI;
    if (k1 == k2) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
    return 0;

}
