#include <stdio.h>


//1-search
int search(int *arr, int size, int num)
{
	int i;
	for (i = 0; i < size; i++)
		if (arr[i] == num)
			return 1;
	return 0;
}
//2-eshterak
int Intersection(int *arr1, int size_arr1, int *arr2, int size_arr2, int *res)
{
	int i;
	int result_index = 0;
	for (i = 0; i < size_arr1; i++)
		if (search(arr2, size_arr2, arr1[i]) == 1) {
			res[result_index] = arr1[i];
			result_index++;
		}
	return result_index;
}

//3-tafazol
int sub_set(int *arr1, int size_arr1, int *arr2, int size_arr2, int *res) {
	int i;
	int result_index = 0;
	for (i = 0; i < size_arr1; i++)
		if (search(arr2, size_arr2, arr1[i]) == 0) {
			res[result_index] = arr1[i];
			result_index++;
		}
	return result_index;
}

//4-print
void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
//5-sort
void array_swap(int a[], int i, int j)
{
	int tmp;
	tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
//6-sort
void bubble_sort(int a[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
			if (a[i] > a[j])
				array_swap(a, i, j);
}


int main(void)
{
	int i;
	int size1, size2;

	scanf("%d", &size1);
	int a1[size1];
	for (i = 0; i < size1; i++)
		scanf("%d", &a1[i]);

	scanf("%d", &size2);
	int a2[size2];
	for (i = 0; i < size2; i++)
		scanf("%d", &a2[i]);

	int res[100];
	int res1[100];
	int res2[100];
	int result_size1;
	int result_size2;
	int result_size3;
	result_size1 = Intersection(a1, sizeof(a1) / sizeof(int), a2, sizeof(a2) / sizeof(int), res);
	result_size2 = sub_set(a1, sizeof(a1) / sizeof(int), a2, sizeof(a2) / sizeof(int), res1);
	result_size3 = sub_set(a2, sizeof(a2) / sizeof(int), a1, sizeof(a1) / sizeof(int), res2);

	//tarif araeye egtemae
	int egtemae[result_size1 + result_size2 + result_size3];
	for (i = 0; i < result_size1; i++)
		egtemae[i] = res[i];

	for (int j = 0, i = result_size1; i < result_size1 + result_size2; i++, j++)
		egtemae[i] = res1[j];

	for (int j = 0, i = result_size1 + result_size2; i < result_size1 + result_size2 + result_size3; i++, j++)
		egtemae[i] = res2[j];

	bubble_sort(egtemae, result_size1 + result_size2 + result_size3);
	printf("%d\n", result_size1 + result_size2 + result_size3);
	print_arr(egtemae, result_size1 + result_size2 + result_size3);




	return 0;
}
