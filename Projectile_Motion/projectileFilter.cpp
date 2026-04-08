using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include "matrix_operations.h"
#include "kalman_filter.h"
#include <fstream>
#include <sstream>
#include <string>
#include <random>


int main(){
    float dt = 0.01;
    float half = 0.5;
    float f = -1 * half * pow(dt,2);
    int N = 1000;

    vector<vector<float>> A = {{1, dt, f},
                               {0, 1, -1*dt},
                               {0, 0, 1}};
    vector<vector<float>> Q = {{10, 0, 0},
                               {0, 10, 0},
                               {0, 0, 0.001}};
    vector<vector<float>> P = {{1, 0, 0},
                               {0, 1, 0},
                               {0, 0, 0.001}};
    vector<vector<float>> H = {{0, 0, 1}};
    vector<vector<float>> R = {{1000000}};
    vector<vector<float>> x = {{500},
                               {0},
                               {9.81}};
    KalmanFilter myObj(A, H, Q, R, P, x);
    vector<string> names = {"Position", "Velocity", "Acceleration"};
    myObj.KF("acceleration.csv", "ProjectileData.csv", names, N);
  
}

