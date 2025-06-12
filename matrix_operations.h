#ifndef matrix_operations_h
#define matrix_operations_h
#include <iostream>
#include <vector>
using namespace std;

vector<vector<float>> swap_rows(vector<vector<float>> myvec, int n, int m){
  vector<float> temp = myvec[n];
  myvec[n] = myvec[m];
  myvec[m] = temp;

  return myvec;
}

vector<vector<float>> inverse(int n, vector<vector<float>> mat){
  vector<vector<float>> I(n, vector<float>(n,0.0));

  // We have the indentity matrix
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i == j){
        I[i][j] = 1.0;
      }
    }
  }

  // Next check for zeros on diagonal and swap rows
  for (int i = 0; i < n; i++){
    if (i == n - 1){
      if (mat[i][i] == 0.0 && mat[i-1][i] != 0.0){
        mat = swap_rows(mat, i, i- 1);
        I = swap_rows(I, i, i-1);
      }
  }else if (i != n - 1){
    if (mat[i][i] == 0.0 && mat[i+1][i] != 0.0){
      mat = swap_rows(mat, i, i+1);
      I = swap_rows(I, i, i +1);
      }
    }
  }
  

  float ratio;
  
  // Now we row reduce that shit !! 
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      ratio = mat[j][i] / mat[i][i] * -1;
      for (int k = 0; k < n; k++){
        mat[j][k] = mat[j][k] + ratio * mat[i][k];
        I[j][k] = I[j][k] + ratio * I[i][k];
        }
      }
  }

  // Now reverse

  for (int i = n - 1; i >= 0; i--){
    for (int j = i-1; j >= 0; j--){
      ratio = mat[j][i] / mat[i][i] * -1;
      for (int k = n - 1; k >= 0; k--){
        mat[j][k] = mat[j][k] + ratio * mat[i][k];
        I[j][k] = I[j][k] + ratio * I[i][k];
        }
      }
  }

    // Next put ones along the diagonal

  for (int i = 0; i < n; i++){
    ratio = mat[i][i];
    for (int j = 0; j < n; j++){
      mat[i][j] = mat[i][j] / ratio;
      I[i][j] = I[i][j] / ratio;
      if (I[i][j] == -0.0){
        I[i][j] = 0.0;
      }
    }
  }
  return I;
  }


vector<vector<float>> transposeMat(vector<vector<float>> mat) {
  int n = mat.size();
  int m = mat[0].size();
  vector<vector<float>> my_result(m, vector<float>(n, 0));
  for (int i = 0; i < my_result.size(); i++) {
    for (int j = 0; j < my_result[i].size(); j++) {
      my_result[i][j] = mat[j][i];
    }
  }
  return my_result;
}

vector<vector<float>> matrix_addition(vector<vector<float>> mat1, vector<vector<float>> mat2){
    int m = mat1.size();
    int n = mat1[0].size();
    vector<vector<float>> my_result(m, vector<float>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        my_result[i][j] = mat1[i][j] + mat2[i][j];
      }
    }
    return my_result;
  }

vector<vector<float>> matrix_multiplication(vector<vector<float>> mat1, vector<vector<float>> mat2){
    int r1 = mat1.size();
    int c1 = mat1[0].size();
    int r2 = mat2.size();
    int c2 = mat2[0].size();
    if (c1 != r2){
      cout << "Aborting Program" << endl;
      abort();
    }
    vector<vector<float>> my_result(r1, vector<float>(c2, 0));
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
        my_result[i][j] = 0;
        for (int k = 0; k < r2; k++) {
          my_result[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
  return my_result;
}

vector<vector<float>> subtractMat(vector<vector<float>> mat1, vector<vector<float>> mat2) {
  int r1 = mat1.size();
  int c1 = mat1[0].size();
  vector<vector<float>> my_result(r1, vector<float>(c1, 0));
  for (int i = 0; i < my_result.size(); i++) {
      for (int j = 0; j < my_result[i].size(); j++) {
        my_result[i][j] = mat1[i][j] - mat2[i][j];
      }
    }
  return my_result;
}

#endif /* matrix_operations_h */