# Convex Hull Algorithms

This program implements the Giftwrapping (Jarvis March) and Graham Scan algorithms for finding a convex hull.


## How to Use
Run `make test`. This will:

1. Compile the program into an executable called `convexhull`
2. Compile the `generator.c` program into an executable called `gen`
3. Run the generator program to generate random points in different sizes
4. Run `convexhull` on those points and output the number of points in the file, the number of points on the hull, and the execution time of the 2 algorithms

Note: graham scan runtime depends on the STL sort() performance 


## How it Works
See [here](https://docs.google.com/a/binghamton.edu/presentation/d/1v4kFFzYMo4J1zqPEm7TNFhs8MXQWTe2uGEfGDYsMzuc/edit?usp=sharing)