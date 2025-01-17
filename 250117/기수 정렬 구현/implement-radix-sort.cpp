#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Counting Sort for a specific digit position
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count the occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Update count[i] to contain the position of the next occurrence
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort implementation
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int maxNum = *max_element(arr.begin(), arr.end());

    // Perform counting sort for each digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform radix sort
    radixSort(arr);

    // Print sorted array
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}