#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucketsort(float arr[], int n) 
{ 
    // 1) Create n empty buckets 
    vector<float> b[n]; 
     
    // 2) Put array elements in different buckets 
    for (int i=0; i<n; i++) 
    { 
       int bi = n*arr[i]; // Index in bucket 
       b[bi].push_back(arr[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i=0; i<n; i++) 
       sort(b[i].begin(), b[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
          arr[index++] = b[i][j]; 
} 

int main() {
  float arr[] = {0.3, 0.5, 0.6, 0.1, 0.5, 0.4}; 
  int n = sizeof(arr)/sizeof(arr[0]); 

  bucketsort(arr, n);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << "\n";
  
  return 0;
}