#include <stdio.h>
#include <time.h>

#define NUM_THREADS 4
#define TERMS_PER_THREAD 10

struct ThreadData {
    double x;
    int start_term;
    int end_term;
    double result;
};

// Function to compute factorial
double factorial(int n) {
    if (n == 0) {
        return 1;
    }
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to compute power
double power(double base, int exponent) {
    double result = 1.0;
    // Handling negative exponents
    if (exponent < 0) {
        base = 1 / base;
        exponent = -exponent;
    }
    // Multiply base 'exponent' times
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

void calculate_sine(void *args) {
    struct ThreadData *data = (struct ThreadData *)args;
    double term = 0.0;
    int sign = 1;
    // Calculate terms assigned to this thread
    for (int i = data->start_term; i <= data->end_term; i++) {
        int exponent = 2 * i + 1;
        term += sign * power(data->x, exponent) / factorial(exponent);
        sign *= -1;
    }
    data->result = term;
}

double sine(double x) {
    struct ThreadData thread_data[NUM_THREADS];
    double total_result = 0.0;

    // Create threads to compute sine terms
    for (int i = 0; i < NUM_THREADS; i++) {
        int start_term = i * TERMS_PER_THREAD;
        int end_term = (i + 1) * TERMS_PER_THREAD;
        if (i == NUM_THREADS - 1) {
            // Ensure last thread handles remaining terms
            end_term = TERMS_PER_THREAD * NUM_THREADS;
        }
        struct ThreadData data = {x, start_term, end_term, 0.0};
        thread_data[i] = data;
        calculate_sine((void *)&thread_data[i]);
    }

    // Collect results
    for (int i = 0; i < NUM_THREADS; i++) {
        total_result += thread_data[i].result;
    }

    return total_result;
}

int main() {
    double angle;
    angle = 47;

    printf("Enter angle in degrees:%1f ", angle);
    //scanf("%lf", &angle);

    double x = angle * 3.141592653589793 / 180.0;


    // Calculate sine
    double result = sine(x);

    printf("Sine of %.2f degrees is %.6f\n", angle, result);
    return 0;
}