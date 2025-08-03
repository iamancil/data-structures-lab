#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void method1(float arr2[], int size){

  int start_time = clock();

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
  printf("%d, %f \n", size, time_taken);
}

void method2(float arr2[], int size){
  
  int start_time = clock();

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
  double time_taken = ((double)(end_time - start_time))/ CLOCKS_PER_SEC;
  printf("%d, %f \n ", size, time_taken);
}

int main(){
  srand(time(NULL));
  int size = (rand() % 10000000);
  float *finalArray = malloc(size * sizeof(float));
  method1(finalArray,size);

  return 0;
}
