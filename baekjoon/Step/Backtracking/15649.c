#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_nm
{
	int n;
	int m;
}				t_nm;

void arr_print(int *arr, int m)
{
	int i;

	i = 0;
	while (i < m)
	{
		printf("%d", arr[i]);
		if (i < m - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void permutation(int depth, t_nm nums, int *arr, int *brr)
{
	int i;

	if (depth == nums.m)
	{
		arr_print(arr, nums.m);
		return ;
	}
	for (i = 0 ; i < nums.n ; i++)
	{
		if (brr[i] == 0)
		{
			brr[i] = 1;
			arr[depth] = i + 1;
			permutation(depth + 1, nums, arr, brr);
			brr[i] = 0;
		}
	}
}

int main(void)
{
	t_nm nums;
	int *arr;
	int *brr;
	int i;

	scanf ("%d %d", &nums.n, &nums.m);
	arr = malloc(sizeof(int) * nums.n);
	brr = malloc(sizeof(int) * nums.n);
	i = -1;
	while (i++ < nums.n)
		brr[i] = 0;
	permutation(0, nums, arr, brr);
	return (0);
}
