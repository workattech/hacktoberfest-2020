#   Bubble Sort 
    -----------
->  Short Intro: Find the smallest element for every index by traversing all element after it.

->  Worst Case Time Complexity - O(N2)
->  Best Case Time Complexity - O(N2)

//  For more info: https://www.geeksforgeeks.org/bubble-sort/

#   Insertion Sort 
    --------------
->  Short Intro: Sort array before an index and then find perfect place for the value at that index in the sorted part.

->  Worst time complexity - O(N2)  
->  Best Case - O(N) for sorted array
->  Space Complexity - O(N)

->  Advantage: Performs better for small length array.

//  For more info:  https://www.geeksforgeeks.org/insertion-sort/


#   Merge Sort 
    ----------
->  Short Intro : Based on Divide and Conquer Algorithm. At first Divide whole array into smallest length arrays to the leaf doing O(log(N)) work overall
                  and then merge it from bottom to the root in O(N) work in every level.

->  Best Case Time complexity - Theta(Nlog(N))
->  Auxillary Space complexity - Theta(N) space is Created and Destroyed at every level. 

->  Add-on :
1)  Space complexity can be dcreased to O(1) if we use Linked List instead arrays.
2)  In general for arrays, QuickSort performs better.

//  For more info: https://www.geeksforgeeks.org/merge-sort/


#   Quick-Sort
    ----------
->  Short Intro : Based on Divide and Conquer Algorithm. At First we pick the pivot element then partition the array based on pivot element. 
                  All element lesser than pivot is on left side of it and all element graeter than pivot is on right side of it. 
                  Then we recursively do it for the partitioned array untill whole array is sorted.

->  Partition Technique: 
1)  Naive Partition in Time Complexity - O(N), Space Complexity - O(N).  
->  First we put lesser element than pivot into another array and then we put the higher elements in it.

2)  Lomuto Partition in Time Complexity - O(N), Space Complexity - O(1). 
->  We select the last element as the pivot and maintain only one front pointer for element swapping.

3)  Hoare Partition in Time Complexity - O(N), Space Complexity - O(1).  
->  We select the first element as the pivot and maintain two pointer one front and one end for element swapping. 


->  Worst Time Complexity - O(N2)  
->  Best Case - O(NlogN)
->  Space Complexity - O(1)

->  Add-on : Though it have high time complexity, then also it is preferred over the other sorting algorithm due to following reason:

1)  In-place Sorting.
2)  Average Case Time Complexity- O(Nlog(N)).
3)  Tail Recursive.
4)  Cache Friendly.
   
//  For more info: https://www.geeksforgeeks.org/quick-sort/


#   Heap Sort
    ---------
->  Short Intro : Based on Binary Heap. 

->  Worst Time Complexity - O(NlogN)  
->  Best Case - O(N) for sorted array.
->  Space Complexity - O(1)
   
//  For more info: https://www.geeksforgeeks.org/heap-sort/


#   Count Sort
    -----------
->  Short Intro : Based on counting the occurances of every number and storing the count in the another array at that number index.

->  Time Complexity:  Theta(N)
->  Space Complexity: O(n) where n is the upper limit of the number in the array.

->  Limitation: Incompactible with higher limit of array element size because we cannot declare large size array for storing the count.

//  For more info: https://www.geeksforgeeks.org/counting-sort/


#   Radix Sort
    ----------
->  Short Intro : Sort in based on the fact that if we sort element based on least significant digit to most significant digit in it, 
                  then final result will be a sorted array. 

->  Time Complexity:  Theta(d*(N+b)) - where d is the number of digit in maximum element of the array and b is the base of the number.
->  Space Complexity: Theta(N+b) 

//  For more info: https://www.geeksforgeeks.org/radix-sort/

