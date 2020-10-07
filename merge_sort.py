# Python program for implementation of MergeSort
# Merge Sort is a Divide and Conquer algorithm which divides the input array in two halves, calls itself for the two halves and then merges the two sorted halves...

# Code:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
def merge_sort(values): 
  
    if len(values)>1: 
        m = len(values)//2
        left = values[:m] 
        right = values[m:] 
        left = merge_sort(left)   # Recursively sorting the first half
        right = merge_sort(right)  # Recursively sorting the second half
  
        values =[] 
  
        while len(left)>0 and len(right)>0: 
            if left[0]<right[0]: 
                values.append(left[0]) 
                left.pop(0) 
            else: 
                values.append(right[0]) 
                right.pop(0) 
  
        for i in left: 
            values.append(i) 
        for i in right: 
            values.append(i) 
                  
    return values
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

'''Merge sort analysis:
 Time Complexity: Sorting arrays on different machines. Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation.
                  T(n) = 2T(n/2) + \Theta(n)
The above recurrence can be solved either using Recurrence Tree method or Master method. It falls in case II of Master Method and solution of the recurrence is 'nLogn'.
Time complexity of Merge Sort is 'nLogn' in all 3 cases (worst, average and best) as merge sort always divides the array into two halves and take linear time to merge two halves
'''
