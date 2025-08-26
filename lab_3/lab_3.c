//WAP to search an ITEM (integer) in an array using binary search, if FOUND then delete that item from array and if NOT
//FOUND than insert that item in position such that array remain sorted.

#include <stdio.h>
#include <stdlib.h>
//find the desired element
void binarySearchRecursive(int *arr, int beg, int end, int n){
	int p = beg + (end - beg) / 2;
  bool found = false;
	if(n == arr[p]){
		printf("The number is present at %d index.", p+1);
    found = true;
	}
	else{
		if(arr[p]>n){
			end = p;
      binarySearch(arr, beg, end, n);
		}
		else{
			beg = p;
      binarySearch(arr, beg, end, n);
		}
	}
}

int binarySearch(int *arr, int size, int target){
  int left = 0;
  int right = size-1;
  while(left<=right){
    int mid = (right + left) /2;
    if(arr[mid] = target){
      return mid;
    }
    if(arr[mid]>target){
      return right = mid-1;
    }
    if(arr[mid]<target){
      return left = mid+1;
    }
  }
  return -(left+1);
}

void deleteElement(int c, int *arr, int &size){
  for(int i=c;i<size;i++){
    arr[i] = arr[i+1];
  }
  size--;
}

void addElement(int pos, int *arr, int target, int &size){
  for(int i=size-1;i>pos;i--){
    arr[i+1] = arr[i];

  }
  arr[pos] = target;
  size++;
}

int main(){
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
  int *arr = (int *)malloc(size * sizeof(int));
	printf("Enter all the elements in the array: ");
	for(int i=0;i<size;i++){
		scanf("%d", &arr[i]);
	}
	printf("Enter the element to find: ");
	int n;
	scanf("%d", &n);
	//sort the array:
	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int c = binarySearch(arr, size, n);
  if(c>=0){
    deleteElement(c, arr, size);
  }
  else{
    int pos = -(c+1);
    addElement(pos, arr, n, size);
  }
  free(arr);
  return 0;
}
