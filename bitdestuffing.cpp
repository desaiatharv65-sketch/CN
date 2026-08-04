#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    // Step 1: Read the stuffed frame length n
    cout << "Enter the length of stuffed frame: ";
    cin >> n;

    vector<int> a(n);
    vector<int> b;

    // Step 2: Read the stuffed frame into array a[]
    cout << "Enter the stuffed frame bits (separated by spaces): ";
    for (int k = 0; k < n; k++) {
        cin >> a[k];
    }

    // Step 3: Initialize i = 0, count = 0
    int i = 0, count = 0;

    // Steps 4–9: Process bits
    while (i < n) {
        // Step 5: Copy a[i] to b
        b.push_back(a[i]);

        // Step 6: Check for consecutive 1s
        if (a[i] == 1) {
            count++;
        } else {
            count = 0;
        }

        // Step 7: If 5 consecutive 1s are detected
        if (count == 5) {
            i++; // Increment i to skip the stuffed 0
            count = 0; // Reset count
        }

        // Step 8: Increment i
        i++;
    }

    // Step 10: Display original frame
    cout << "Original frame after bit de-stuffing: ";
    for (int bit : b) {
        cout << bit << " ";
    }
    cout << endl;

    return 0;
}