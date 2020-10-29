 
# Linear Search
      Short Intro: The element to be searched is compared with every element till a match is found.

      Best Case Time complexity: O(1).
      Worst Case Time complexity: O(N), where N is the number of elements in the array.    
      Space Complexity: O(1)
    
 For more info: https://www.geeksforgeeks.org/binary-search/ 
 
# Jump Search    
      Short Intro: It is performed on sorted data, the array is divided into M parts and we find in which part our element would lie, and then we do a linear search to find the desired element.

      Best Case Time Complexity: O(1).    
      Worst Case Time Complexity: O(sqrt(N)), where N is the length of the array. The algorithm works optimally when we take M = sqrt(N).    
      Space Complexity: O(1).
      Advantage: Works better than a linear search for the sorted array.
    
 For more info: https://www.geeksforgeeks.org/jump-search/
 
# Binary Search
      Short Intro: Based on Divide And Conquer Technique. Works on a sorted array, we compare the searched value with the middle value of the array and find out in which part of the array it can be present right half or left half, similarly, we do it recursively till we found the element or we have exhausted the array. 

      Best Case Time Complexity: O(1).   
      Worst Case Time Complexity: O(log(N)), where N is the length of the array.    
      Space Complexity: O(1).
    
 For more info: https://www.geeksforgeeks.org/binary-search/
 
# Exponential Search
      Short Intro:  It is used in the place where the upper bound of array size is very large. We find the part where the searched element would lie and then perform a binary search on the part to find the element. The part size grows exponentially in order of 2, like 0-2, 2-4, 4-8, 8-16...
      Best Case Time Complexity: O(1).    
      Worst Case Time Complexity: O(log(N)), where N is the length of the array.    
      Space Complexity: O(1).
    
  For more info: https://www.geeksforgeeks.org/exponential-search/?ref=lbp
