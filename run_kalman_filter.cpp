#include <iostream>
#include <vector>
#include <cmath>
#include "kalman_filter.h"
#include "matrix_operations.h"
#include <fstream>
#include <sstream>
#include <string>
#include <random>
using namespace std;
#include <chrono>
using namespace std::chrono;

// Code for opening CSV from https://medium.com/@ryan_forrester_/reading-csv-files-in-c-how-to-guide-35030eb378ad
vector<vector<string>> readCSV(const string& filename) {
  vector<vector<string>> data;
  ifstream file(filename);
  
  if (!file.is_open()) {
      cerr << "Failed to open file: " << filename << endl;
      return data;
  }

  string line;
  while (getline(file, line)) {
      vector<string> row;
      stringstream ss(line);
      string cell;

      while (getline(ss, cell, ',')) {
          row.push_back(cell);
      }

      data.push_back(row);
  }

  file.close();
  return data;
}

int main(){
  ofstream myfileax;
  myfileax.open("ax_final.csv");
  vector<vector<float>> A = {{1}};
  vector<vector<float>> H = {{1}};
  vector<vector<float>> P = {{1}};
  vector<vector<float>> R = {{10}};
  vector<vector<float>> Q = {{10}};
  vector<vector<float>> x = {{1}};
  
  KalmanFilter myObj(A, H, Q, R, P, x);


  vector<vector<string>> ax1 = readCSV("ax1.csv");
  for (int i = 0; i < ax1[0].size(); i++){
    vector<vector<float>> z = {{stof(ax1[0][i])}};
    myObj.updateData(z);
    myObj.runKalmanFilter();
    myfileax << myObj.estimated_x[0][0] << endl;
  }

}


