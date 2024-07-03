import threading
import time

NUM_THREADS = 4  # Number of threads
TERMS_PER_THREAD = 10  # Number of terms each thread will compute


class ThreadData:
    def __init__(self, x, start_term, end_term):
        self.x = x
        self.start_term = start_term
        self.end_term = end_term
        self.result = 0.0


# Function to compute factorial
def factorial(n):
    if n == 0:
        return 1
    result = 1.0
    for i in range(1, n + 1):
        result *= i
    return result


# Function to compute power
def power(base, exponent):
    result = 1.0
    # Handling negative exponents
    if exponent < 0:
        base = 1 / base
        exponent = -exponent
    # Multiply base 'exponent' times
    for _ in range(exponent):
        result *= base
    return result


def calculate_sine(data):
    term = 0.0
    sign = 1
    # Calculate terms assigned to this thread
    for i in range(data.start_term, data.end_term + 1):
        exponent = 2 * i + 1
        term += sign * power(data.x, exponent) / factorial(exponent)
        sign *= -1
    data.result = term


def sine(x):
    threads = []
    thread_data = []
    total_result = 0.0

    # Create threads to compute sine terms
    for i in range(NUM_THREADS):
        start_term = i * TERMS_PER_THREAD
        end_term = (i + 1) * TERMS_PER_THREAD
        if i == NUM_THREADS - 1:
            # Ensure last thread handles remaining terms
            end_term = TERMS_PER_THREAD * NUM_THREADS
        data = ThreadData(x, start_term, end_term)
        thread = threading.Thread(target=calculate_sine, args=(data,))
        threads.append(thread)
        thread_data.append(data)
        thread.start()

    # Wait for threads to finish and collect results
    for thread in threads:
        thread.join()

    for data in thread_data:
        total_result += data.result
        #time_sec = time.time() 
        #print("Time in seconds :", time_sec) 
    return total_result
    


def main():
    angle = float(input("Enter angle in degrees: "))
    start=time.time()
    # Convert degrees to radians
    x = angle * 3.141592653589793 / 180.0
    print("Sine of %.2f degrees is %.6f" % (angle, sine(x)))
    
    stop=time.time()

    print("total execution time",stop-start)

if __name__ == "__main__":
    main()
