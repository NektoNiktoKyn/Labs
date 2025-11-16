#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *array, int n){
	for (int i = 0; i<n-1; i++){
		for (int j = 0; j<n-i-1; j++){
			if (array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void insertion_sort(int *array, int n){
	for (int i = 1; i < n; i++){
		int key = array[i];
		int j = i - 1;

		while(j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j--;
		}

		array[j+1] = key;
	}
}

#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

void shuffle(int *array, int n){
	for (int i=n-1; i>0; i--){
		int j = rand()%(i+1);
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

int main(){
	//Создаем
	int *arr10 = (int*)malloc(10 * sizeof(int));
	if (arr10 == NULL){
		printf("Mem 10 Err\n");
		return 1;
	}

	int *arr1k = (int*)malloc(1000 * sizeof(int));
	if (arr1k == NULL){
		printf("Mem 1k Err\n");
		free(arr10);
		return 1;
	}

	int *arr10k = (int*)malloc(10000 * sizeof(int));
	if (arr10k == NULL){
		printf("Mem 10k Err\n");
		free(arr10);
		free(arr1k);
		return 1;
	}

	int *arr100k = (int*)malloc(100000 * sizeof(int));
	if (arr100k == NULL){
		printf("Mem 100k Err\n");
		free(arr10);
		free(arr1k);
		free(arr10k);
		return 1;
	}

	//Заполняем
	for (int i=0; i<10; i++){
		arr10[i] = i+1;
	}

	for (int i=0; i<1000; i++){
		arr1k[i] = i+1;
	}

	for (int i=0; i<10000; i++){
		arr10k[i] = i+1;
	}

	for (int i=0; i<100000; i++){
		arr100k[i] = i+1;
	}

	//Сортировка пузырьком
	shuffle(arr10, 10);
	shuffle(arr1k, 1000);
	shuffle(arr10k, 10000);
	shuffle(arr100k, 100000);

	printf("\n---Bubble sort---\n");

	clock_t start1 = clock();
	bubble_sort(arr10, 10);
	clock_t end1 = clock();
	double seconds1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
	printf("10 elem: %f\n", seconds1);

	clock_t start2 = clock();
	bubble_sort(arr1k, 1000);
	clock_t end2 = clock();
	double seconds2 = (double)(end2 - start2)/CLOCKS_PER_SEC;
	printf("1k elem: %f\n", seconds2);

	clock_t start3 = clock();
	bubble_sort(arr10k, 10000);
	clock_t end3 = clock();
	double seconds3 = (double)(end3 - start3)/CLOCKS_PER_SEC;
	printf("10k elem: %f\n", seconds3);

	clock_t start4 = clock();
	bubble_sort(arr100k, 100000);
	clock_t end4 = clock();
	double seconds4 = (double)(end4 - start4)/CLOCKS_PER_SEC;
	printf("100k elem: %f\n", seconds4);

	//Сортировка вставками
	shuffle(arr10, 10);
	shuffle(arr1k, 1000);
	shuffle(arr10k, 10000);
	shuffle(arr100k, 100000);

	printf("\n---Insertion sort---\n");

	clock_t start5 = clock();
	insertion_sort(arr10, 10);
	clock_t end5 = clock();
	double seconds5 = (double)(end5 - start5)/CLOCKS_PER_SEC;
	printf("10 elem: %f\n", seconds5);

	clock_t start6 = clock();
	insertion_sort(arr1k, 1000);
	clock_t end6 = clock();
	double seconds6 = (double)(end6 - start6)/CLOCKS_PER_SEC;
	printf("1k elem: %f\n", seconds6);

	clock_t start7 = clock();
	insertion_sort(arr10k, 10000);
	clock_t end7 = clock();
	double seconds7 = (double)(end7 - start7)/CLOCKS_PER_SEC;
	printf("10k elem: %f\n", seconds7);

	clock_t start8 = clock();
	insertion_sort(arr100k, 100000);
	clock_t end8 = clock();
	double seconds8 = (double)(end8 - start8)/CLOCKS_PER_SEC;
	printf("100k elem: %f\n", seconds8);

	//Сортировка слиянием
	shuffle(arr10, 10);
	shuffle(arr1k, 1000);
	shuffle(arr10k, 10000);
	shuffle(arr100k, 100000);

	printf("\n---Merge sort---\n");

	clock_t start9 = clock();
	merge_sort(arr10, 0, 9);
	clock_t end9 = clock();
	double seconds9 = (double)(end9 - start9)/CLOCKS_PER_SEC;
	printf("10 elem: %f\n", seconds9);

	clock_t start10 = clock();
	merge_sort(arr1k, 0, 999);
	clock_t end10 = clock();
	double seconds10 = (double)(end10 - start10)/CLOCKS_PER_SEC;
	printf("1k elem: %f\n", seconds10);

	clock_t start11 = clock();
	merge_sort(arr10k, 0, 9999);
	clock_t end11 = clock();
	double seconds11 = (double)(end11 - start11)/CLOCKS_PER_SEC;
	printf("10k elem: %f\n", seconds11);

	clock_t start12 = clock();
	merge_sort(arr100k, 0, 99999);
	clock_t end12 = clock();
	double seconds12 = (double)(end12-start12)/CLOCKS_PER_SEC;
	printf("100k elem: %f\n", seconds12);
}
