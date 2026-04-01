# Kalman Filter


# About


# kalman_filer.h
This the header file that contains the actual Kalman filter algorithm and an example of the filter using Acceleration, gyroscope and magnetometer data to get attitude (although this was a work in progress and is not 100% correct. It still needs fine tuning). 

# matrix_operations.h
These are the necessary matrix operations to run the filter such as matrix addition, subtraction, transpose, and inverse of a matrix. 

# Text Files
These text files are just for an example of running the Kalman Filter using the prelimary algorithm for attittude determination. The data was retrieved from here: https://data.mendeley.com/datasets/xknhpz5t96/1

# run_kalman_filter.cpp and filter_data.py
This file is the C++ code for running the filter based off the above 6 text files. First the data needs to be preprocessed in python (actually there might be more efficient ways of implementing this in C++ but I was lazy and wanted all my measurements as their own csv files. Feel free to make it more efficient) which is what filter_data.py does. It writes all the 18 variables to their own csv files (ax1, ax2, ax3, ay1, ay2, ay3, az1, az2, az3, gx1, gx2, gy1, gy2, gz1, gz2, mx, my, mz).
