/*
Bubble Sort

Bubble sort is a simple and well-known sorting algorithm. It is used in practice once in a blue moon and its main application is to make an introduction to the sorting algorithms. Bubble sort belongs to O(n2) sorting algorithms, which makes it quite inefficient for sorting large data volumes. Bubble sort is stable and adaptive.
Algorithm

    Compare each pair of adjacent elements from the beginning of an array and, if they are in reversed order, swap them.
    If at least one swap has been done, repeat step 1.

You can imagine that on every step big bubbles float to the surface and stay there. At the step, when no bubble moves, sorting stops. 
*/

void bubbleSort(int arr[], int n) {

      bool swapped = true;

      int j = 0;

      int tmp;

      while (swapped) {

            swapped = false;

            j++;

            for (int i = 0; i < n - j; i++) {

                  if (arr[i] > arr[i + 1]) {

                        tmp = arr[i];

                        arr[i] = arr[i + 1];

                        arr[i + 1] = tmp;

                        swapped = true;

                  }

            }

      }

}