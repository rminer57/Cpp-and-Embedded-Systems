
/*
Binary search algorithm

Generally, to find a value in unsorted array, we should look through elements of an array one by one, until searched value is found. In case of searched value is absent from array, we go through all elements. In average, complexity of such an algorithm is proportional to the length of the array.

Situation changes significantly, when array is sorted. If we know it, random access capability can be utilized very efficiently to find searched value quick. Cost of searching algorithm reduces to binary logarithm of the array length. For reference, log2(1 000 000) ˜ 20. It means, that in worst case, algorithm makes 20 steps to find a value in sorted array of a million elements or to say, that it doesn't present it the array.
Algorithm

Algorithm is quite simple. It can be done either recursively or iteratively:

    get the middle element;
    if the middle element equals to the searched value, the algorithm stops;
    otherwise, two cases are possible:
        searched value is less, than the middle element. In this case, go to the step 1 for the part of the array, before middle element.
        searched value is greater, than the middle element. In this case, go to the step 1 for the part of the array, after middle element.

Now we should define, when iterations should stop. First case is when searched element is found. Second one is when subarray has no elements. In this case, we can conclude, that searched value doesn't present in the array. 

Complexity analysis

Huge advantage of this algorithm is that it's complexity depends on the array size logarithmically in worst case. In practice it means, that algorithm will do at most log2(n) iterations, which is a very small number even for big arrays. It can be proved very easily. Indeed, on every step the size of the searched part is reduced by half. Algorithm stops, when there are no elements to search in. Therefore, solving following inequality in whole numbers:

n / 2iterations > 0

resulting in

iterations <= log2(n).

It means, that binary search algorithm time complexity is O(log2(n)).

*/

/*

* searches for a value in sorted array

*   arr is an array to search in

*   value is searched value

*   left is an index of left boundary

*   right is an index of right boundary

* returns position of searched value, if it presents in the array

* or -1, if it is absent

*/

int binarySearch(int arr[], int value, int left, int right) {

      while (left <= right) {

            int middle = (left + right) / 2;

            if (arr[middle] == value)

                  return middle;

            else if (arr[middle] > value)

                  right = middle - 1;

            else

                  left = middle + 1;

      }

      return -1;

}