#include <iostream>
#include <chrono>
#include <vector>

//Part I:
//-------------------------------------------------------------------
// Something I learned while going through this function is that C++ passes arguments by reference and not by value. This initialy caused some confusion because I was unable 
// to get the size of the array after it had been passed in the function, so I had to
// pass the size as an additional argument. I probably could have dereferenced the pointer inside the function so I could directly get the size of the array but adding an additional parameter to the function to accept the size sufficed for this exercise. The more you know. 


// arrayReversal: takes in an array and reverses its contents
// Parameters:
// arr[]: Holds the array being passed in from the function caller
// size int: contains the size of the array

// Time Complexity: O(n)
// Space Complexity; O(1)
// Total Lines Executed: (3 * (n/2)) + 2

void arrayReversal(int arr[], int size) {
	int begin = 0;
	int end = size - 1;

    for(int start = 0; start < end; start++){
        // Create a temporary variabe to hold the value that is going to be swapped to the end of the array
			// since it will be overwritten once the value at the end is brought to the front
			int temp = arr[begin];
			arr[begin] = arr[end];
			arr[end--] = temp;

			// The outermost indicies have been swapped so the beginning and end can be moved inward for the next iteration
    }
}

// generateArray: creates an array of n value length to emulate a recording being passed in

// Parameters:
// n int: contains the size of the array
int* generateArray(int n) {
    int* newArray = new int[n];

    for (int i = 0; i < n; ++i) {
        newArray[i] = i + 1;
    }

    return newArray;
}

// measureAverageRuntime: calls the arrayReversal method and records how long it takes for the function to complete

// Parameters:
// arr[]: Holds the array being passed in from the function caller
// size int: contains the size of the array
// trials int: determines the number of times arrayReveral will be run
std::chrono::nanoseconds measureAverageRuntime(int arr[], int size, int trials) {
    std::chrono::nanoseconds totalRuntime(0);

    for (int i = 0; i < trials; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        // Operation to be measured (e.g., array reversal)
        arrayReversal(arr, size);

        auto end = std::chrono::high_resolution_clock::now();
        totalRuntime += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

        // Restore the original order for the next iteration
        generateArray(size);
    }

    return totalRuntime / trials; // Calculate average runtime
}

int main() {
    const int size = 2500;
    const int trials = 100;

    int* myArray = generateArray(size);

    // Measure average runtime
    std::chrono::nanoseconds averageRuntime = measureAverageRuntime(myArray, size, trials);

    // Output average runtime
    std::cout << "Average Time Elapsed: " << averageRuntime.count() << " nanoseconds\n";

    // Uncomment to display reversed array contents
    // --------------------------------------------
	// std::cout << "Reversed Array: ";
	// for (int i = 0; i < size; i++) {
	//     std::cout << myArray[i] << " ";
	// }

    delete[] myArray;

    return 0;
}

// Part II:

/* The time complexity of the array reversal function is O(N). At most the function will iterate halfway through the array before it has completed swapping all elements. 

The space complexity of the algorithm is O(1) or constant space. 
This is because the amount of memory needed to execute the program
is not dependent on the size of the array. The temp variable is the only additional space consumed outside of the begin and end variables
and the space allocated on the stack for each function.

The total lines executed would be (3 * (n/2)) + 2 because the loop will execute 3 lines of code per iteration, the number of iterations will be n/2 because swapping will be complete halfway through the array, and the declaration of begin and end are constant. 
*/



// Part III:
//------------------------------------------------------------------
/*
To create the graph I used 5 different values of n (500, 1000, 1500, 2000, and 2500). I then measured the average runtime by using the trial variable run the arrayReveral method that number of times and returning the average. For all n values I used a value of 100 trials.
The measureAverageRuntime function would then take in that trial number and run repeatedly until the task was complete. 

I then plotted the values on a self modified cartiesian plane (could not find a great software for plotting cartesian coordinates so I improvised). Overall the results are a fairly linear ascent as the value of n increases, and I would say we can expect this behavior for this algorithm across any value of n.
*/