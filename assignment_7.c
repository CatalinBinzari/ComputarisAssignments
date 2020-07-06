//clang 6.0.0

#include  <stdio.h>
#include <stdlib.h>

int smallestSubWithSum(int arr[], int *n, int *x, int *subarray_start)
{
    int min_len = *n + 1;
    
    for (int start=0; start<*n; start++) 
	{ 
		int curr_sum = arr[start]; 

        if (curr_sum > *x){ *subarray_start = start; return 1; }

		for (int end=start+1; end<*n; end++) 
		{ 
			curr_sum += arr[end]; 
			if (curr_sum > *x && (end - start + 1) < min_len) 
               {
                min_len = (end - start + 1);
                *subarray_start = start;
                break;
               }
		} 
	} 
	return min_len;  
}

void display_subarray(int arr[], int *res, int *sub_s)
{
    printf("subarray[%d]: ",*res);
    for (int i = 0; i < *res; ++i )
    {
        printf("%d ",arr[*sub_s+i]);
    }
}

int main(void)
{
    int subarray_start = 0;
    int n, x; 

    scanf("%d", &n); // cititm N
    printf("n:%d\n",n);
    int arr1[n];
    
    for (int i = 0; i < n; i++) // cititm array-ul
    {
        int number;
        scanf("%d", &number); 
        arr1[i] = number;
    }
    
    scanf("%d", &x); // cititm sum
    printf("x:%d\n",x);

    
	int res1 = smallestSubWithSum(arr1, &n, &x, &subarray_start); 
    
    if (res1 == n + 1) 
        printf("0\n");
    else {
        printf("subarray length: %d\n", res1);
        printf("subarray start index: %d\n", subarray_start);
        display_subarray(arr1, &res1, &subarray_start);
    }
    
    return 0;
}
