//Write a program to sort an array (make a dynamic array) using Bubble sort. Use 1-bit variable FLAG to signal when no
//interchange take place during pass. If FLAG is 0 after any pass, then list is already sorted and there is no need to continue.

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(){
  int size;
  printf("What is the size of the array? ");
  scanf("%d", &size);
  int* arr = malloc(sizeof(int[size]));
  for(int i=0;i<size;i++){
    printf("Enter %d th element: ", i);
    scanf("%d", &arr[i]);
  }

  for(int i=0;i<size-1;i++){
    bool flag = false;
    for(int j=0;j<size-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp;
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        flag = true;
      }
    }
    if(flag == false){
        break;
      }  
  }
  printf("Elements after the sorting:\n ");
  for(int i=0;i<size;i++){
    printf("%d \n", arr[i]);
  }
  printf("Enter the element to find");
  int var;
  scanf("%d", &var);
  for(int i=0;i<size;i++){
    if(arr[i] == var){
      printf("The number is located at %d index", i);
    }
  }
}

void main(){
  bubbleSort();
}
