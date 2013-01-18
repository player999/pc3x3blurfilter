// PC_filter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TIMES 10000000
int main(int argc, char* argv[])
{
	FILE *fin, *fout;
	int h, w;
	int i, j, k;
	unsigned char *picture;
	unsigned char *fpicture;
	long long start, stop;
	fin = fopen(argv[1], "rb");
	fout = fopen(argv[2], "wb");
	h = atoi(argv[3]);
	w = atoi(argv[4]);
	picture = (unsigned char *) malloc(w * h);
	fpicture = (unsigned char *) malloc(w * h);
	fread(picture, 1, w*h, fin);
	memcpy(fpicture, picture, w * h);
	fclose(fin);
	fclose(fout);
	start = time(NULL);
	for(i = 0; i < TIMES; i++){
		for(j = 1; j < h-1; j++){
			for(k = 1; k < w-1; k++){
				fpicture[j*w+k] = (
					picture[(j-1)*w+(k-1)]+
					picture[(j-1)*w+(k)]+
					picture[(j-1)*w+(k+1)]+
					picture[(j)*w+(k-1)]+
					picture[(j)*w+(k)]+
					picture[(j)*w+(k+1)]+
					picture[(j+1)*w+(k-1)]+
					picture[(j+1)*w+(k)]+
					picture[(j+1)*w+(k+1)]
				)/9;
			}
		}
	}
	stop = time(NULL);
	printf("Time: %ius", stop-start);
	return 0;
}

