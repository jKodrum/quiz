#include <stdio.h>
#define LEN 100000
int maxSubArray(int arr[], int n)
{
    int sum=arr[0], maxSum=arr[0];

    for (int i=1; i<n; i++) {
        if (sum<0) sum=arr[i];
        else if (sum>=0 && sum+arr[i]<0) sum=0;
        else sum += arr[i];

        if (maxSum < sum) maxSum = sum;
    }
    return maxSum;
}

int main(int argc, char *argv[])
{
    int arr[LEN] = {0};
    int maxSum, len;
    while (scanf("%d", &len)==1) {
        printf("%d\n", len);
        for (int i=0; i<len; i++)
            scanf("%d", &arr[i]);
        maxSum = maxSubArray(arr, len);
        printf("maxSum : %d\n", maxSum);
    }

    return 0;
}
