#include <cstdio>
int arr[1000000];
int temp[1000000];

void merge(int left, int mid, int right) {
    int i = left, j = mid+1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (int x=left; x<=right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        merge(left, mid, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(0, N-1);

    for (int i=0; i<N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}