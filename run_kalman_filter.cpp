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
    runKFOrientation myObj;
    runKFIMU obj;

    auto start = high_resolution_clock::now();

    ofstream myfilex, myfiley, myfilez, filea, fileb, filec, filed, myfileax, myfileay, myfileaz, myfilemx, myfilemy, myfilemz,
           myfilegx, myfilegy, myfilegz, myfilea, myfileb, myfilec, myfiled, myfilealpha_phi, myfilealpha_gamma, myfileg;

    myfilea.open("a.csv");
    myfileb.open("b.csv");
    myfilec.open("c.csv");
    myfiled.open("d.csv");


    vector<vector<string>> ax1 = readCSV("ax1.csv");
    vector<vector<string>> ay1 = readCSV("ay1.csv");
    vector<vector<string>> az1 = readCSV("az1.csv");
    vector<vector<string>> ax2 = readCSV("ax2.csv");
    vector<vector<string>> ay2 = readCSV("ay2.csv");
    vector<vector<string>> az2 = readCSV("az2.csv");
    vector<vector<string>> ax3 = readCSV("ax3.csv");
    vector<vector<string>> ay3 = readCSV("ay3.csv");
    vector<vector<string>> az3 = readCSV("az3.csv");
    vector<vector<string>> gx1 = readCSV("gx1.csv");
    vector<vector<string>> gy1 = readCSV("gy1.csv");
    vector<vector<string>> gz1 = readCSV("gz1.csv");
    vector<vector<string>> gx2 = readCSV("gx1.csv");
    vector<vector<string>> gy2 = readCSV("gy1.csv");
    vector<vector<string>> gz2 = readCSV("gz1.csv");
    vector<vector<string>> mx = readCSV("mx.csv");
    vector<vector<string>> my = readCSV("my.csv");
    vector<vector<string>> mz = readCSV("mz.csv");



    for (int i = 0; i < 50; i++){
      myObj.updateData(stof(ax1[0][i]), stod(ax2[0][i]), stof(ax3[0][i]),
      stof(ay1[0][i]), stod(ay2[0][i]), stof(ay3[0][i]), stof(az1[0][i]), stof(az2[0][i]), stof(az3[0][i]),
      stof(gx1[0][i]), stof(gx2[0][i]), stod(gy1[0][i]), stod(gy2[0][i]), stod(gz1[0][i]), stod(gz2[0][i]), 
      stod(mx[0][i]), stod(my[0][i]), stod(mz[0][i]));
      myObj.update_state_transition();
      myObj.getOrientation();
     
      myfilea << myObj.x[0][0] << endl;
      myfileb << myObj.x[1][0] << endl;
      myfilec << myObj.x[2][0] << endl;
      myfiled << myObj.x[3][0] << endl;

    }

      filea.close();
      fileb.close();
      filec.close();
      filed.close();
    
   


    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop-start);


   
    



    cout << "Execution Time: " << duration.count() << " milliseconds" << endl;
}


