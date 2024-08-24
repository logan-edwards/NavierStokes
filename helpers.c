#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void plot_1d(float x0, float dx, int nx, float* y, char* label) {
	FILE* fp;
	fp = fopen(label, "w");
	for (int i = 0; i < nx; i++) {
		fprintf(fp, "%f %f\n", x0 + i * dx, y[i]);
	}
	fclose(fp);
}
