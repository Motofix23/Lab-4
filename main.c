#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int** initma(int n, int m) {

	int **ma = (int**) malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		ma[i] = (int*) malloc(m * sizeof(int));
		for (int j = 0; j < m; j++) {
			ma[i][j] = (rand() % 50);
		}
	}
	return ma;
}

void printma(int **ma, int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d |", ma[i][j]);
		}
		printf("\n");
		for (int j = 0; j < m; j++) {
			printf("------");
		}
		printf("\n");
	}

}

void freema(int **ma, int n) {
	int i;
	for (i = 0; i < n; i++) {
		free(ma[i]);
	}
	free(ma);
}

int max(int **ma, int n) {
	int _max = ma[0][1];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ma[i][j] > _max) {
				_max = ma[i][j];
			}
		}
	}
	return _max;
}

int min(int **ma, int n) {
	int _min = ma[0][1];

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ma[i][j] < _min) {
				_min = ma[i][j];
			}
		}
	}
	return _min;
}

int** trans(int **ma, int n, int m) {
	int **tma = initma(m, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tma[j][i] = ma[i][j];
		}
	}

	return tma;
}

int** mult(int **ma1, int **ma2, int n1, int m1, int n2, int m2) {
	int **ma3 = initma(n1, m2);
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			int sum = 0;
			for (int k = 0; k < m1; k++) {
				sum += (ma1[i][k]) * (ma2[k][j]);
			}
			ma3[i][j] = sum;
		}
	}

	return ma3;
}

int* sortr(int **ma, int r, int m) {
	int *raw = (int*) malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		raw[i] = ma[r][i];
	}
	for (int i = 0; i < m; i++) {
		int min = i;
		for (int j = i; j < m; j++) {
			if (raw[j] < raw[min]) {
				min = j;
			}
		}
		int s = raw[i];
		raw[i] = raw[min];
		raw[min] = s;
	}
	return raw;
}

void printr(int *raw, int m) {
	for (int j = 0; j < m; j++) {
		printf("%4d |", raw[j]);
	}
	printf("\n");
	for (int j = 0; j < m; j++) {
		printf("------");

	}
	printf("\n");
}

int** sortm(int **ma, int n, int m) {
	int **sma = (int**) malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		sma[i] = sortr(ma, i, m);
	}
	return sma;
}

int* sumr(int **ma, int n, int m) {
	int *sumraw = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += ma[i][j];
		}
		sumraw[i] = sum;
	}
	return sumraw;
}

int* sumc(int **ma, int n, int m) {
	int *sumraw = (int*) malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += ma[j][i];
		}
		sumraw[i] = sum;
	}
	return sumraw;
}

int main() {
	srand(time(NULL));
	int i = 0;
	int n1;
	int m2;
	printf("$$$WELCOME TO THE YAROSLAVS MATRIX SOLVER$$$\n");
	printf("Please, enter the square matrix >>");
	fflush(stdout);
	scanf("%i", &n1);
	printf("Enter the second matrix, where will %u lines>>", n1);
	fflush(stdout);
	scanf("%i", &m2);
	printf("**************************************************************\n");
	printf("=====Matrix A=====\n");
	int m1 = n1;
	int n2 = m1;

	int **ma = initma(n1, m1);
	int **mb = initma(n2, m2);
	int **tma = trans(ma, n1, m1);
	printma(ma, n1, m1);
	printf("Max = %u\n", max(ma, n1));
	printf("Min = %u\n", min(ma, n1));
	printf("=====Matrix B=====\n");
	printma(mb, n2, m2);
	printf("=============================================\n");
	printf("Now choose what will we do:\n");
	while (1) {
		int i = 0;
		int r = 0;
		printf(" 1. Transpondatoin\n");
		printf(" 2. Multiplication\n");
		printf(" 3. Sort matrix A\n");
		printf(" 4. Sort line from A\n");
		printf(" 5. Sum lines A\n");
		printf(" 6. Sum columns B\n");
		printf(" 7. Exit program\n");
		printf(">>>");
		fflush(stdout);
		scanf("%i", &i);
		switch (i) {
		case 1:
			printf("================TRANS=======================\n");
			printma(tma, m1, n1);
			printf("============================================\n");
			break;
		case 2:
			printf("***MULTIPLICATION***\n");
			printma(mult(ma, mb, n1, m1, n2, m2), n1, m2);
			printf("============================================\n");
			break;
		case 3:
			printma(sortm(ma, n1, m1), n1, m1);
			printf("============================================\n");
			break;
		case 4:
			printf("Choose number from %u of line to sort>>", m1);
			fflush(stdout);
			scanf("%i", &r);
			r = r - 1;
			printr(sortr(ma, r, m1), m1);
			break;
		case 5:
			printr(sumr(ma, n1, m1), m1);
			printf("============================================\n");
			break;
		case 6:
			printr(sumc(mb, n2, m2), m2);
			printf("============================================\n");
			break;
		case 7:
			freema(ma, n1);
			freema(mb, n2);
			freema(tma, n1);
			return 0;
		}
	}
	freema(ma, n1);
	freema(mb, n2);
	freema(tma, n1);
	return 0;
}
