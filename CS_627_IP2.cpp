// Drevon Taylor
// CS627 IP2
// November 26, 2023

#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

/* Part I:
----------------------------------------------------------------------------------------
trackSearch: this function returns a song if found within a given array

Parameters:
songs vector<string>: a list of songs within a given playlist
track string*: a reference to the track that we are searching for
start int: the starting index of the list to be searched
end int: the ending index of the list to be searched
*/

int trackSearch(const vector<string> &songs, string track, int start, int end){
    // Check to make sure the search space is possible
    if(start <= end){
        // Each marker is where the array will be divided at, ideally giving us roughly 3 equal sub sections
        int marker_one = start + (end - start) / 3;
        int marker_two = end - (end - start) / 3;

        // Something I took into consideration from personal experience
        // is I used to hate when I would upload a track to my MP3 player
        // and it would not recognize that a track already existed on my playlist
        // simply because the casing was different so I added case insensitive search here

        if(toupper(songs[marker_one][0]) == toupper(track[0])){
            int i = 1;
            for (; i < track.length() && i < songs[marker_one].length() &&
                   toupper(songs[marker_one][i]) == toupper(track[i]); ++i){}
                if (i == track.length()){
                    return marker_one;
                }
        }
        if(toupper(songs[marker_two][0]) == toupper(track[0])){
            int i = 1;
            for (; i < track.length() && i < songs[marker_two].length() &&
                   toupper(songs[marker_two][i]) == toupper(track[i]); ++i){}
                if (i == track.length()){
                    return marker_two;
                }
        }

        
        if(toupper(track[0]) < toupper(songs[marker_one][0])){
            return trackSearch(songs, track, start, marker_one - 1);
        }else if(toupper(track[0]) > toupper(songs[marker_two][0])){
            return trackSearch(songs, track, marker_two + 1, end);
        }else{
            return trackSearch(songs, track, marker_one + 1, marker_two - 1);
        }
    }

    return -1;
}

int main(){
    vector<string> playlist = {"Purple Rain", "Beat It", "Mortal Man", "Ultimate", "Heaven's EP",
                               "Kick Push", "Mt. Olympus", "Sky is the Limit", "Stars"};
    // Testing case sensitivity
    string targetSong = "sTaRs";
    int trackIndex = trackSearch(playlist, targetSong, 0, playlist.size() - 1);

    if(trackIndex != -1) {
        // This will print the track name as typed vs how its stored in the array, but its case insensitive
        // either way
        cout << targetSong << " is located at index " << trackIndex << endl;
    }else{
        cout << "The provided song was not found, check spelling if you believe this is an error." << endl;
    }

    return 0;
}

// Part 2:

/*  The difference between ternary search and binary search is very small
    and that is reflected in their similarities in time complexity. Both
    algorithms are logarithmic, but each log has a different base. The base of each
    log is the number of sections that are used in the process of the algorithm.
    This means for binary search the time complexity is O(log 2 n)(not a mathmetician 
    but I believe O(log 2 n) is the same as O(log n) because base 2 is the default),
    while the time complexity of ternary search is O(2 * log 3 n). In the worst case 
    ternary search has a slightly worse result. Lets compare:
    
    Ternary Search Worst Case:
    T(n) = T(n/3) + 4, T(1) = 1  -> 4log3n + O(1) -> O(log3n)
    
    Binary Search Worse: 
    T(n) = T(n/2) + 2,  T(1) = 1 -> 2log2n + O(1) -> O(log2n)

    Personally I could find little difference in the average runtime of each. I plugged 
    trackSearch function into the runtime calculator I submitted last week and compared 
    it to a standard binary search algorthm where n(size of playlist) = 10, 100, 1000 and
    the results were so similar that on a graph that they were nearly the same. 

*/