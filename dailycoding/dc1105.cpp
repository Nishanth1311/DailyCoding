#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int sum = 0, halfsum = 0;
    cin >> n;
    vector <int> arr(n);
    
    // get input
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    // If the sum is not even, we can not split it to 2 separate sub-arrays
    if (sum % 2) {
        cout << "Not possible\n";
        return 0;
    }

    // We need to see if any sub-array can be equal to half the sum
    // if it is then the remaining part would make the other sub-array
    halfsum = sum / 2;
    
    // Create a boolean array of size halfsum
    vector <bool> possibleSum (halfsum + 1, false);
    
    // iterate through the array to form possible subarray sums
    for (int i = 0; i < n; i++) {
        for (int j = halfsum; j > arr[i]; j--) {
            if (possibleSum[j - arr[i]] || (j == arr[i])) {
                possibleSum[j] = true;
            }
        }
    }
    
    /*
    for (int i = 0; i <= halfsum; i++) {
        cout << possibleSum[i] << " ";
    }
    cout << endl;
    */
 
    cout << "Possibility to divide the array to equal subarrays: " << possibleSum[halfsum] << endl;

    return 0;
}
