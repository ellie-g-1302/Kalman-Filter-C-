#ifndef kalman_filter_h
#define kalman_filter_h
#include <iostream>
#include <vector>
#include "matrix_operations.h"
using namespace std;

class KalmanFilter {
  public:
      vector<vector<float>> A_matrix;
      vector<vector<float>> H_matrix;
      vector<vector<float>> Q_matrix;
      vector<vector<float>> R_matrix;
      int m;
      int n; 

      // Variables
      vector<vector<float>> predicted_x;
      vector<vector<float>> measurement;
      vector<vector<float>> predicted_P;
      vector<vector<float>> K;
      vector<vector<float>> estimated_x;
      vector<vector<float>> estimated_P;

      KalmanFilter(vector<vector<float>> A, vector<vector<float>> H, 
          vector<vector<float>> Q, vector<vector<float>> R, vector<vector<float>> P, vector<vector<float>> x){
          A_matrix = A;
          H_matrix = H;
          Q_matrix = Q;
          R_matrix = R;
          estimated_x = x;
          estimated_P = P;
      }
      ~KalmanFilter(){}

      void updateData(vector<vector<float>> z0){
          measurement = z0;
      }

      void predict_state(){
        predicted_x = matrix_multiplication(A_matrix, estimated_x);
        }
        
      void predict_error_covariance(){
          vector<vector<float>> result = matrix_multiplication(A_matrix, estimated_P);
          predicted_P  = matrix_addition(matrix_multiplication(result, transposeMat(A_matrix)), Q_matrix);
        }

      
      void kalman_gain(){
          vector<vector<float>> result = matrix_multiplication(H_matrix, predicted_P);
          vector<vector<float>> result_two = transposeMat(H_matrix); 
          vector<vector<float>> result_three = matrix_multiplication(result, result_two);
          vector<vector<float>> result_four = matrix_addition(result_three, R_matrix);
          vector<vector<float>> result_five = matrix_multiplication(predicted_P, result_two);
          vector<vector<float>> result_six = inverse(result_four.size(), result_four);
          K = matrix_multiplication(result_five, result_six); 

        }
      void estimate(){
          vector<vector<float>> result = subtractMat(measurement, matrix_multiplication(H_matrix, predicted_x));
          estimated_x = matrix_addition(predicted_x, matrix_multiplication(K, result));
        }
        
      void compute_error_covariance(){
          vector<vector<float>> result = matrix_multiplication(K, H_matrix);
          estimated_P = subtractMat(predicted_P, matrix_multiplication(result, predicted_P));
      }

      void runKalmanFilter(){
          predict_state();
          predict_error_covariance();
          kalman_gain();
          estimate();
          compute_error_covariance();
      }
};


    
#endif /* kalman_filter_h */
