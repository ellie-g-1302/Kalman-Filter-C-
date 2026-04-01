# Kalman Filter
A Kalman filter is an algorithm that takes in sensor measurements and filteres the data and estimates state variables. This program is written in C++ and is a basic Kalman filter. 

# How to Use the Filter
Right now the Filter only takes in 1 variable of data in the form of a column with no header, specifically a CSV file. I am working to expand this to multivariable data files and different data file types. You import the header file kalman_filter.h into a C++ file and initialize the class with the necessary vectors. Then you call the function "KF" with the first argument being the output file and the second argument being the input file. The file will run and return the variable in that data file.

# A Simple Example
Say we have an accelerometer that measures the acceleration of gravity. Say we were to throw this accelerometer up in the air such that its entire trajectory was in free fall. The data is measurements we would expect to see around $9.81 \mathrm{m/s}^2$. What if when we plotted our data, we saw something like this:
<img width="8000" height="4000" alt="Before" src="https://github.com/user-attachments/assets/ce60484d-7cc6-41c3-9f6e-1fc6fa6ed650" />
Now obviously this is incorrect. We know that the value of gravitational acceleration is $9.81 \mathrm{m/s}^2$. We can use a Kalman filter to filter the data and find the true value of the measurements. When we do this, we get
<img width="8000" height="4000" alt="after" src="https://github.com/user-attachments/assets/7ccf0c2b-d6b3-4ffb-a00d-9aef26c6a85f" />

Here we can see the green line which is the filtered data, and the black line which is the true value. You can run this simulation yourself by using the files in the "Projectile Motion" folder.

