# algorithm-portfolio
**CS 627 Portfolio**

Within this portfolio you will find a compilation of work from this class demonstrating our coverage of algorithms with a focus on time and space complexity. An outline of each project is detailed below.

**Individual Project 1**
 
Build an in-place, order reversal algorithm. This algorithm will take as an input an array of ints and will reverse the order of the elements in the array, in place (essentially using only the memory in the array). For example, if the array contains five elements [1,2,3,4,5], the output of the algorithm will be [5,4,3,2,1]. 

**Individual Project 2**

Code a search algorithm that searches a list of strings for a particular song. The searching algorithm will have two inputs: the playlist, which is a string array that contains a list of songs in alphabetical order; and a particular song, which is a string. If the song is found in the list, the algorithm will return the index of the song, and it will return -1 otherwise.
This searching algorithm will employ a divide-and-conquer approach similar to that in binary search, but with a slight variation. In binary search, a list is split in 2 sublists during each step; however, for your assignment, you will build and algorithm that splits the list into 3 sublists during each step.

**Individual Project 3**

You plan to design a greedy algorithm to efficiently transfer media to storage devices. Note that this is an optimization problem. Optimization problems have a general structure and consist of some quantity to be maximized or minimized under some list of constraints. In this problem, you have n files (f1, ..., fn) with corresponding sizes (in MBs) s1, ... sn. Your goal is to store these files onto m disks, d1, ..., dm, that have corresponding storages amounts t1, ..., tm. Note that one file cannot be spread across multiple disks. In this problem, the goal is to minimize the amount of storage that is not used on each disk (that is used). This should also minimize the total number of number of disks being used. That is, you would like to fill up each disk as much as possible while leaving a minimally small amount of unused storage. (In the perfect case, each disk would be perfectly filled, and there would be no unused storage.) If there are any disks left unused, you will be able to return them for a refund.

**Individual Project 4**

Compare one black-and-white image into another black-and-white image. There are a number of methods that can be used to perform this task, but your group has agreed that using dynamic programming is a fast and elegant scheme to solve this problem.

Design an algorithm (using pseudocode) that takes in as an input, two 2-D int arrays that are assumed to be 2 black-and-white images: initialImage x, whose dimensions are IxJ, and finalImage y, whose dimensions are IxK. The algorithm will compare x to the y, row-by-row, as defined below. Your algorithm will employ a dynamic programming scheme to compare X to Y identifying the minimal difference between each row.

Because you are working with black-and-white images only, you should assume that each image is a 2-D int array consisting of 2 possible values: 0 or 1, where 0 represents black and 1 represents white. Thus, this 2-D grid of 0 and 1 values comprise a 2-D black-and-white image. Each row of this image is then simply a 1-D int array filled with either 0s or 1s. Therefore, you must define how you will measure the difference between the strings of 0s and 1s in each row.


**Individual Project 5**
Your company has asked your team to design an app that will complete a Sudoku game, given any starting state of the game. 