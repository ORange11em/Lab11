#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

float calculateSD(float data[],float k) {
  float s = 0.0, mean, standardDeviation = 0.0;
  int j;

  for(j = 0; j < k; ++j) {
    s += data[j];
  }

  mean = s / k;

  for(j = 0; j < k; ++j) {
    standardDeviation += pow(data[j] - mean, 2);
  }

  return sqrt(standardDeviation / k);
}

int main(){
    int i=0;
    float sum=0,SD;
    float data[83]={};
    string textline ;
    ifstream source("score.txt");
    while (getline(source,textline))
    {
        data[i]= atof(textline.c_str());
        sum += atof(textline.c_str());
        i++;
    }
    SD=calculateSD(data,i);

    cout << "Number of data = "<< i <<"\n";
    cout << setprecision(3);
    cout << "Mean = "<<sum/i<<"\n";
    cout << "Standard deviation = "<< SD<<"\n";
}