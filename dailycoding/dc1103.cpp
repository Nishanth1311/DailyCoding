#include <iostream>

using namespace std;
int main() {
    // Variables
    int n, m;

    // Get the dimensions of the maze
    cin >> n >> m;
    bool arr[n][m];

    // Get input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    // array to calculate the number of ways to reach the bottom right
    int ways[n][m];

    // Zero down the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ways[i][j] = 0;
        }
    }

    // top left is always free   
    ways[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // can not reach
            if (arr[i][j] == 1) {
                continue;
            }
            
            // if we can reach
            // number of ways to reach = num of ways to reach left + num of ways to reach up

            // no: of ways to reach from left            
            if ((i - 1) >= 0) {
                ways[i][j] += ways[i - 1][j];
            }
            
            // no: of ways to reach from right 
            if ((j - 1) >= 0) {
                ways[i][j] += ways[i][j - 1];
            }
        }
    }
    
    // Answer
    cout << "Number of ways to reach from topleft to bottomright: " << ways[n - 1][m - 1] << endl; 

    return 0;
}