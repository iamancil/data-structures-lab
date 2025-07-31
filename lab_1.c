#include <stdio.h>
#include <stdlib.h>
void method1(float arr2[], int size){
  float sum = 0;
  float q = 0;
  int arr1[size];
  for(int i=0;i<size;i++){
    arr1[i] = (rand() % 100);
  }
  for(int i=0;i<size;i++){
    sum += arr1[i];
    q = sum/(i+1);
    arr2[i] = q;
  }
}

void method2(float arr2[], int size){
  float q = 0;
  int arr1[size];
  for(int i=0;i<size;i++){
    arr1[i] = (rand() % 100);
  }
  for(int i=0;i<size;i++){
    float sum = 0;
    for(int j=0;j<=i;j++){
      sum += arr1[j];
    }
    q = sum/(float)(i+1);
    arr2[i] = q;
  }
}

int main(){
  int size = (rand() % 100);
  float finalArray[size];
  method1(finalArray,size);
   for (int i = 0; i < size; i++) {
        printf("%f ",finalArray[i]);
    }
  return 0;
}
