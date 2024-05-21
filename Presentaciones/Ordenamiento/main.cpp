#include <iostream>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {

  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {

    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }

    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j) {
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[low], &arr[j]);
  return j;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {

    int partitionIndex = partition(arr, low, high);

    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);
  }
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;

  j = 0;

  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void bubbleSort(int arr[], int n) {
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    if (swapped == false)
      break;
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int N = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, N);
  std::cout << "array ordenada: \n";
  for (int i = 0; i < N; i++)
    std::cout << " " << arr[i];
  int arr_merge[] = {64, 34, 25, 12, 22, 11, 90};
  mergeSort(arr_merge, 0, N - 1);
  std::cout << "array ordenada: \n";
  for (int i = 0; i < N; i++)
    std::cout << " " << arr_merge[i];
  int arr_quick[] = {64, 34, 25, 12, 22, 11, 90};
  quickSort(arr_quick, 0, N - 1);
  for (int i = 0; i < N; i++)
    std::cout << " " << arr_quick[i];
  
  return 0;
}
