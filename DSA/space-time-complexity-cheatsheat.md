# Space And Time Complexity of Algorithms 



## What is Time Complexity ?

##### Time Complexity is the computational complexity that describes the amount of time it takes to run an algorithm. It is generally estimated by counting the number of elementary operations performed by the algorithm, supposing that each operation takes a fixed amount of time.

It is generally denoted by **Big- O** notation.

Since  running time of Algorithms can vary *a lot* on their input, we commonly consider the **worst-case** time complexity of algorithms.

Assuming that the size of the input is represented by n and constant value is represented by k. Some common time complexities, in increasing order, are:

```
O(k) < O(log(n)) < O(n*log(n)) < O(n^k) < O(k^n) < O(n!) and so on...						
```



### Time Complexity of various algorithms

Following table contains time complexities of various commonly used algorithms:




Name of Algorithm | Best Case|Worst Case | Average Case         
:----------: | :-----------: | :-----------: | :-----------: 
Selection Sort |Ω(n^2)| θ(n^2) | O(n^2)	 
Bubble Sort	| Ω(n)	|θ(n^2)	| O(n^2)	 
Insertion Sort	| Ω(n)	| θ(n^2)	| O(n^2)	 
Heap Sort | 	Ω(n log(n))| 	θ(n log(n))| 	O(n log(n))	 
Quick Sort | 	Ω(n log(n)) | 	θ(n log(n)) | 	O(n^2)	 
Merge Sort | 	Ω(n log(n)) |	θ(n log(n)) |	O(n log(n))	 
Bucket Sort |	Ω(n+k) |	θ(n+k) |	O(n^2)	 
Radix Sort |	Ω(nk) |	θ(nk) |	O(nk)




## What is Space Complexity?

##### The **space complexity** of an algorithm or a computer program is the amount of memory space required to solve an instance of the computational problem as a function of characteristics of the input. It is the memory required by an algorithm to execute a program and produce output.

Similar to time complexity, it is also denoted by **Big - O** notation.



### Space Complexity of various algorithms

Following table contains time complexities of various commonly used algorithms:

| Name of Algorithm |  Best Case  |
| :---------------: | :---------: |
|  Selection Sort   |   Ω(n^2)    |
|    Bubble Sort    |    Ω(n)     |
|  Insertion Sort   |    Ω(n)     |
|     Heap Sort     | Ω(n log(n)) |
|    Quick Sort     | Ω(n log(n)) |
|    Merge Sort     | Ω(n log(n)) |
|    Bucket Sort    |   Ω(n+k)    |
|    Radix Sort     |   Ω(n*k)    |
