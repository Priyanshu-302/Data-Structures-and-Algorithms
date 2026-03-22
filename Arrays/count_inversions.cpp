#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int cnt = 0;
    // Function to merge two halves of the array
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
            {
                temp.push_back(arr[right++]);
                cnt += mid - left + 1;
            }
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Recursive merge sort function
    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        mergeSort(arr, low, mid);

        // Recursively sort right half
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }

public:
    int inversionCount(vector<int> &arr)
    {
        int n = arr.size();

        // Brute Force --> TC - O(n ^ 2)
        // int cnt = 0;

        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (arr[i] > arr[j]) cnt++;
        //     }
        // }

        // return cnt;

        // Optimized --> Merge Sort
        mergeSort(arr, 0, n - 1);
        return cnt;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {2, 4, 1, 3, 5};

    cout << sol.inversionCount(arr) << endl;

    return 0;
}