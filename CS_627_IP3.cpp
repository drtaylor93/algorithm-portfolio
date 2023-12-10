// Drevon Taylor
// CS627 IP3
// December 4, 2023


#include <iostream>
using namespace std;

// Part I
// -------------------------------------------------------------------------
/*
To help me conceptialize this I am extending the problem to a real life 
issue that I had recently. The core of the problem remains the same. 
I own a Synology DS220 NAS that I use to backup my Macbook using the Time
Machine app. The NAS has 4 bays of 250GBs, 2 500GB, and a 1TB drive. 

For this implementation the objective is to iterate through the array that
holds the list of backups that need to be placed on the NAS and then
selecting the NAS that has the most remaining disk space to store the backup.
This can avoid situations where we may run into a disk that does not have
enough space remaining and we have to go to the next disk. If the disk selected
cannot store the backup, then none of the disks have sufficient space.
*/ 

// Psudocode, will not run as is
function greedyNas(n, fileSizes, m, diskStorage)
    // Initialize arrays to track used storage on each disk and the mapping of files to disks
    diskSpaceUsed[m] = {} // Keeps track of spaced used thus far
    nasMap[n] = {} // Map of backups

    // Generating a list of 50 random sized OS backups(files). Each backup can
    // be between 1GB and 29GB in size
    const int numberOfBackups = 50;
    int osBackups[numberOfBackups];

    for(int i = 0; i < arraySize; ++i) {
        // Generates a random number between 0 and 29 that represents the size of the osbackup
        osBackups[i] = rand() % 30;
    }
          
    // Sort the files in decreasing order of size. Great time to use the 
    // merge sort algorithm we learned about last week. I would copy
    // my solution from last we but its tailored to tracks and would need
    // changes to work here so just indicating the use here
    sortedBackups = mergesort(osBackups)


    // Create a list of files with their corresponding sizes and indices then
    // iterate through each file
    for(i = 0; i <  n - 1; i++){
        // Find the disk with the most remaining storage after adding the file
        // Default selected disk is the first bay and 0 is the default storage left
        highestDiskSpaceLeft = 0
        nasBaySelected = 0

        // Iterate through each disk and calculate the amount of storage left.
        for(j = 0; j < m - 1; j++){
            freeSpace = highestDiskSpaceLeft[j] - diskSpaceUsed[j]

            //Ensuring the Time Machine backup can actualy fit space wise within the remaining 
            if(sortedBackups <= freesSpace && freesSpace > highestDiskSpaceLeft)
                highestDiskSpaceLeft = freeSpace
                selectedDisk = j

            // Update the used storage on the selected disk and map the file to it
            diskSpaceUsed[nasBaySelected] += sortedFiles[index]
            nasMap[sortedBackups[index] = selectedDisk
        }
    }
            
    return nasMap

/*
Part II
-----------------------------------------------------------------------------
The way I solved this problem was inspired by a discussion board post I saw
this past week where a fellow student mentioned using greedy algorithms for
exchanging foreign currency. This made me think about when I used to work
in a grocery store. The process of giving someone their change in cash is not
so different that this problem. If you think of the total denomination as the
total space and the smaller denominations of change as files, its somewhat 
similar. So how would I solve this problem as a cashier? Well first I would
get the maximum amount of the largest denomination. So if the change was
$8.47 we could use one $5 bill, followed by three $1 bills, a quarter, two
dimes, and finally two pennies. 

In a somewhat similar approach, if we think of the denomination of change as 
remaining disk sizes, I first ordered the files from greatest to least. As each file is stored, the 
algorithm keeps track of the remaining amount of space on that drive. If 
there is not enough space to accomodate the next file, we continue to 
iterate through the array of files until there is one that is less than the
free space remaining on disk. What makes this a greedy algorithm is it does
not take into consideration how many disks, or what sizes of the disks
remain. I am sure some optimizations could be made in which the algorithm
constantly scans each disk to determine the most optimal slot, but then it
would not be a greedy algorithm. Because of this, it is not guaranteed to 
always return an optimal result. 

The time complexity of the algorithm above is O(m * n). It is this because
both the storage of each individual disk and the size of each file, in my case
OS backups, are key parts of the runtime and they must be multiplied by 
each other. If either the number of disks in the NAS, or the number of my
OS backups increased (which they often do since Time Machine runs daily)
the runtime would be increase proportional to the product of the two. 
*/


/*
Part III
----------------------------------------------------------------------------
In order to solve the problem using the brute force method we would have to
figure out all possible scenarios. So for example, without first sorting the
files from greatest to least, we would need to first iterate through each
file size, followed by iterating through each disk and getting all possible 
combinations of the files and disks. From that point we could assess what 
would be the optimal placement of each file. Since we would have to iterate
through both arrays and evaluate within two loops, the time complexity
would be O(m^n) which is pretty bad. For something small like my personal NAS
brute force would potenitally be fine, but at scale at a corporation like Google
that has tens of thousands of cloud servers this would not be feasible as it would
require us to take each backup or file and compare it to every availible Google
server, which again, running at O(m^n) would be brutal, and because file storage
is such a common operation for customers it would be untenable to use the 
brute force method in that case. 
*/