#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r], i = l;
    for(int j = l; j < r; ++j) {
        if(arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int random_partition(int arr[], int l, int r) {
    int n = r-l+1;
    int pivot = rand() % n;
    swap(arr[pivot + l], arr[r]);
    return partition(arr, l, r);
}

int kthsmallest(int arr[], int l, int r, int k) {
    
    if(k > 0 && k <= r-l+1) {

        int pos = random_partition(arr, l, r);

        if(pos - l == k - 1)
            return arr[pos];
        
        if(pos - l > k - 1)
            return kthsmallest(arr, l, pos - 1, k);

        return kthsmallest(arr, pos + 1, r, k-1-pos+l);
    }
    return INT_MAX;
}

int main() {
    int n = 6;
    int arr[] = {2, 1, 5, 9, 6, 4};
    int k = 3;  // kth smallest

    cout << kthsmallest(arr, 0, n-1, k) << "\n";

    return 0;
}
