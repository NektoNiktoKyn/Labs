#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(int args, char *argv[]){
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Err file\n");
		return 1;
	}


	int count_str;
	int count_column;

	if(fscanf(file, "%d %d", &count_str, &count_column) != 2) {
		printf("Err: Size - |{count str} {count column}|\n");
		fclose(file);
		return 1;
	}

	double** mas = (double**)malloc(count_str * sizeof(double*));
	if (mas == NULL) {
		printf("Err: Size for matrix\n");
		fclose(file);
		return 1;
	}

	for (int i = 0; i < count_str; i++){
		mas[i] = (double*)malloc(count_column * sizeof(double));
		if (mas[i] == NULL) {
			printf("Err: Size for column matrix\n");
			for (int j = 0; j < i; j++) {
				free(mas[j]);
			}
			free(mas);
			fclose(file);
			return 1;
		}
	}

	for (int i = 0; i < count_str; i++){
		for (int j = 0; j < count_column; j++){
			if (fscanf(file, "%lf", &mas[i][j]) != 1){
				printf("Err: Err read elem |%d| |%d|\n", i, j);
				for (int k = 0; k<count_column; k++){
					free(mas[k]);
				}
				free(mas);
				fclose(file);
				return 1;
			}
		}
	}

	fclose(file);

	int count_neg_number = 0;
	for (int i = 0; i < count_str; i++){
		for (int j = 0; j < count_column; j++){
			if (i>j && mas[i][j] < 0){
				count_neg_number++;
			}
		}
	}
	printf("Count neg under main diagonal: %d\n", count_neg_number);

	for (int i = 0; i < count_str; i++){
		double S = 5;
		double sum = 0;
		for (int j = 0; j < count_column; j++){
			S += (mas[i][j] / 7);
			sum += sin(mas[i][j]);
		}
		S += sum;

		printf("Srt: %d | S=%.6f\n", i, S);
	}

	for (int i = 0; i < count_str; i++) {
        	free(mas[i]);
    	}
    	free(mas);

	return 0;
}
