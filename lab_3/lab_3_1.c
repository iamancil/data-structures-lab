#include <stdio.h>

void add(int arr[], int *n, int target, int pos) {
for (int i = *n; i > pos; i--) {
  arr[i] = arr[i - 1];
}
arr[pos] = target;
(*n)++;
}

void removeElement(int arr[], int *n, int x) {
for (int i = x; i < *n - 1; i++) {
  arr[i] = arr[i + 1];
}
(*n)--;
}

int binarysearch(int arr[], int n, int target) {
int left = 0;
int right = n - 1;

while (left <= right) {
  int mid = (left + right) / 2;
  if (arr[mid] == target) {
      return mid;
  }
  if (arr[mid] > target) {
      right = mid - 1;
  }
  if (arr[mid] < target) {
      left = mid + 1;
  }
}
return -(left + 1);
}

int main() {
int n;
printf("the size of array is:");
scanf("%d", &n);

int arr[n];
printf("the elements are:");
for (int i = 0; i < n; i++) {
  scanf("%d", &arr[i]);
}

int target;
printf("the element to find is:");
scanf("%d", &target);

int x = binarysearch(arr, n, target);

if (x >= 0) {
  removeElement(arr, &n, x);
  printf("element found and deleted\n");
} else {
  printf("element was not found hence added\n");
  int pos = -(x + 1);
  add(arr, &n, target, pos);
}

printf("the updated array is:");
for (int i = 0; i < n; i++) {
  printf("%d ", arr[i]);
}
printf("\n");

return 0;
}
