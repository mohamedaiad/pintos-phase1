#include "real.h"
#include <stdio.h>
#include <stdint.h>

/* Fixed-point numbers are used 
    they are in signed p:q format where p + q = 31, and f is 1 << q*
 */
const int F = 1 << 14;


/* Multiply two real numbers 
    it takes x,y and return ((int64_t) x) * y / f */
struct real
multiply_real(struct real r1, struct real r2) {
    struct real r = {.x = (int64_t)(r1.x) * (r2.x)/F};
    return r;
}

/* Divide two real numbers 
    it takes x,y and return ((int64_t) x) * f / y */
struct real
divide_real(struct real r1, struct real r2) {
    if(r2.x==0){
        struct real a = {.x=-1};
        return a;
    }

    struct real r = {.x = ((int64_t)(r1.x) * F) / r2.x};
    return r;
}

/* Add two real numbers */
struct real
add_real(struct real r1, struct real r2) {
    struct real r = {.x = r1.x + r2.x};
    return r;
}

/* subtract two real numbers */
struct real
subtract_real(struct real r1, struct real r2) {
    struct real r = {.x = r1.x - r2.x};
    return r;
}

/* Convert x to integer (rounding toward zero): x / f
 * Convert x to integer (rounding to nearest):
 * (x + f / 2) / f if x >= 0
 * (x - f / 2) / f if x <= 0
 */
int
real_to_int(struct real r) {
    if (r.x >= 0) return (r.x + F / 2)/F;
    return (r.x - F / 2)/F;
}

/* Convert n to fixed point: n * f
 * */
struct real
int_to_real(int n) {
    struct real r = {.x = n * F};
    return r;
}


