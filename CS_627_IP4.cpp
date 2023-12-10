/*
Dre Taylor
December 9, 2023
CS 627 IP4
*/

/*Part I:
----------------------------------------------------------------------
For my porfolio I created a deployed website that includes information
about my skillsets as a developer, experience, and work completed in
this class. The website is publicly accessible and can be found at:

https://drtaylor93.github.io

The website was created using vanilla javascript, html, and css, and
while not quite as polished as I would like, I am proud to at least 
have a starting point as I have wanted to have a personal portfolio
for quite some time. At the bottom of the page there is a link to my
github repo where I have listed all of my IP submissions thus far.

*/


/*Part II:
----------------------------------------------------------------------
For this problem I likened it to signal processing where each bit
represents a pixel on a screen, but in this case the options are only
black and white instead of the standard red, blue, or green. While I
attempted to make the code as close to C++ as possible, it is still
psudocode code and is not production ready.


compareImages: takes 2 images and determines likeness based on a numberic
               threshhold.

Parameters:
x vector<vector>: image one to be compared
y vector<vector>: image two to be compared
thresh int: determines if the two images are alike or different

Return: 
String stating whether the images are alike or different

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compare two black-and-white images
string compareImages(const vector<vector<int>>& x, const vector<vector<int>>& y, int thresh) {
    int totalDifference = 0;

    // Determining the dimensions of the image being passed in
    int rows = x.size();
    int xCols = x[0].size();
    int yCols = y[0].size();
    

     // Initialize a new row to store differences (1 if different, 0 if the same)
    vector<int> differences(xCols, 0);

    for (int i = 0; i < rows; ++i) {
        int currentRowDiff = x[i][0];

        for (int j = 1; j < min(xCols, yCols); ++j) {
            int cost = abs(x[i][j] - y[i][j]);
            currentRowDiff = min(currentRowDiff + cost, x[i][j]);

             // Here we are storing the result of if the two pixels are alike
             // or different in a new row. If they are the same the value is 0,
             // otherwise 1.  
            differences[j] = (x[i][j] != y[i][j]) ? 1 : 0;
        }

        totalDifference += currentRowDiff;
    }

    // Check if total difference is above the threshold. If so,
    // the images are different. I decided to make the threshold
    // inclusive so a differce of two pixel still classifies as 
    // similar. 
    if (totalDifference == 0) {
        return "The images are the same";
    } else if(totalDifference < thresh){
        return "The images are similar to each other";
    } else {
        return "The images are different from each other";
    }
}

int main() {
    // Creating two sample rows to compare
    vector<vector<int>> firstImage = {{1, 1, 0, 1, 0}};
    vector<vector<int>> secondImage = {{0, 1, 1, 1, 0}};

    int threshold = 2;
    string result = compareImages(firstImage, secondImage, threshold);
    cout << result << endl;

    return 0;
}

/*
Part 2B:
---------------------------------------------------
The time complexity of the above solution is
O(x * y). This is because we are using a nested for
loop to complete the anaylsis of the 2D array, the 
outer loop to traverse the columns and the inner
loop to iterate through the rows. The space complexity is
the same O(x * y) because temporary storage is created to save the
difference matrix to memory. 
*/