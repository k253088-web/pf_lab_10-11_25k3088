#include<stdio.h>

int linear_search(int arr[], int size, int target, int index) {
    if (index == size) return -1;   
    if (arr[index] == target) return index;
    return linear_search(arr, size, target, index + 1);
}

int main() {
	int i;
    int n, target;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    int result = linear_search(arr, n, target, 0);

    if (result == -1) printf("Not found\n");
    else printf("Found at index %d\n", result);

    return 0;
}
