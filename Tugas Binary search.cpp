#include <stdio.h>

// Fungsi binarySearch untuk mencari elemen target dalam array yang diurutkan
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    // Selama low tidak melewati high
    while (low <= high) {
        // Temukan titik tengah
        int mid = low + (high - low) / 2;

        // Jika target ditemukan di tengah
        if (arr[mid] == target)
            return mid;

        // Jika target lebih besar, cari di sebelah kanan
        else if (arr[mid] < target)
            low = mid + 1;

        // Jika target lebih kecil, cari di sebelah kiri
        else
            high = mid - 1;
    }

    // Jika target tidak ditemukan dalam array
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    // Panggil fungsi binarySearch
    int result = binarySearch(arr, n, target);

    // Cek apakah elemen target ditemukan atau tidak
    if (result != -1)
        printf("Elemen %d ditemukan di index %d\n", target, result);
    else
        printf("Elemen %d tidak ditemukan dalam array\n", target);

    return 0;
}
