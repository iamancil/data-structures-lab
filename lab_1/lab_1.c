#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double method1(int size){
  int start_time = clock();
  float *arr2 = malloc(size * sizeof(float));
  float sum = 0;
  float q = 0;
  float *arr1 = malloc(size * sizeof(float));
  for(int i=0;i<size;i++){
    arr1[i] = (rand() % 100);
  }
  for(int i=0;i<size;i++){
    sum += arr1[i];
    q = sum/(i+1);
    arr2[i] = q;
  }

  int end_time = clock();
  double time_taken = ((double)(end_time - start_time))/CLOCKS_PER_SEC;
  free(arr1);
  free(arr2);
  return time_taken;
}

double method2(int size){
  int start_time = clock();
  float *arr2 = malloc(size * sizeof(float));
  float q = 0;
  float *arr1 = malloc(size * sizeof(float));
  for(int i=0;i<size;i++){
    arr1[i] = (rand() % 1000);
  }
  for(int i=0;i<size;i++){
    float sum = 0;
    for(int j=0;j<=i;j++){
      sum += arr1[j];
    }
    q = sum/(float)(i+1);
    arr2[i] = q;
  }
  int end_time = clock();
  free(arr1);
  free(arr2);
  double time_taken = ((double)(end_time - start_time))/ CLOCKS_PER_SEC;
  return time_taken;
}

int main(){
  srand(time(NULL));
  int size = (rand() % 100);
  
  for (int n = 5000; n <= 50000; n += 1000) {
        double time1 = method1(n);
        double time2 = method2(n);
        printf("%d,%f,%f\n", n, time1, time2);
    } 
  return 0;
}
