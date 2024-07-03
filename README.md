# Calculation-of-a-sine-of-an-angle-using-Parallelization-C-vs-Python-on-FPGA

This assignment report delves into the comparative analysis of computational performance between C and Python implementations for computing the sine of an angle on Field-Programmable Gate Arrays (FPGAs). The study aims to explore the efficacy of parallelization methodologies in augmenting computational throughput. Leveraging the Zynq 7000 FPGA platform for executing the C implementation and the PYNQ board for running the Python counterpart, the investigation delves into various aspects including execution time, resource utilization, and power efficiency. By systematically examining the impact of programming language selection and parallelization techniques on FPGA-based computations, the report provides comprehensive insights into optimizing performance within embedded systems. Through rigorous experimentation and analysis, this study contributes to the advancement of FPGA-based computing paradigms, offering valuable guidelines for practitioners and researchers seeking to maximize computational efficiency in FPGA deployments.

The Taylor series is a mathematical representation of a function as an infinite sum of terms, each of which is determined by the function&#39;s derivatives at a single point. It provides a way to approximate complex functions with simpler polynomial expressions.

The Taylor series expansion for a function f(x) around a point a is given by:
![image](https://github.com/PoojaMulbagal/Calculation-of-a-sine-of-an-angle-using-Parallelization-C-vs-Python-on-FPGA/assets/139887877/3908f55a-62ed-4462-b6fe-d55a7e40d4f2)

**Algorithm**
1. Start
2. Define necessary header files: stdio.h for standard input and output, and time.h for time-related functions.
3. Define the macros: NUM_THREADS: Number of threads for parallel computation. TERMS_PER_THREAD: Number of terms to be calculated per thread.
4. Define a structure ‘ThreadData’ to hold data for each thread, including the angle ‘x’, start and end terns for computation and the result.
5. Implement functions for calculating factorial (factorial) and power (power).
6. Implement the function calculate_sine:
    Cast the input argument to ThreadData type.
    Compute the sine terms assigned to the thread within the specified range.
    Update the result in the ThreadData structure.
7. Implement the sine function:
    Create an array of ThreadData structures to hold data for each thread.
    Divide the computation into multiple threads, each responsible for calculating a subset of terms.
    Spawn threads to compute sine terms concurrently.
    Collect and sum up the results from all threads.
8. In the ‘main’ function:
    Initialize the angle in degrees.
    Convert the angle to radians.
    Call the sine function to compute the sine of the angle.
    Print the result.
9. End.

    
