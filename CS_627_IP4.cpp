/*
Dre Taylor
December 9, 2023
CS 627 IP4
*/

function calculateDifference(X, Y, thresh):
    I = length(X)  // Number of rows in X
    J = length(X[0])  // Number of columns in X
    K = length(Y[0])  // Number of columns in Y

    // Initialize D matrix
    D = createMatrix(I, K)
    
    // Initialize totalDifference
    totalDifference = 0

    // Populate D matrix using dynamic programming
    for i from 1 to I:
        for j from 1 to K:
            // Calculate the cost for matching or mismatching pixels
            cost = abs(X[i-1][j-1] - Y[i-1][j-1])
            
            // Recurrence relation for D matrix
            D[i][j] = cost + min(D[i-1][j], D[i][j-1], D[i-1][j-1])
    
    // Find the minimum value in the bottom row of D matrix
    minVali = min(D[I])
    
    // Aggregate the differences
    totalDifference = totalDifference + minVali

    // Check if total difference is above the threshold
    if totalDifference > thresh:
        return "The images are different"
    else:
        return "The images are similar"

function createMatrix(rows, cols):
    // Helper function to create a 2D matrix with zeros
    matrix = new 2D array with dimensions rows x cols, initialized with zeros
    return matrix



/*
Part 2B:
---------------------------------------------------
The time complexity of the above solution is
O(m * n). This is because we are using a nested for
loop to complete the anaylsis of the 2D array, the 
outer loop to traverse the columns and the inner
loop to iterate through the rows. The space complexity is
the same O(m * n) because temporary storage is created to save the
matrix to memory. 
*/