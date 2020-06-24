// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct time {
	int hour;
	int min;
	int sec;
	int mili_sec;
};


int main(void)
{
		FILE *fp;
		struct time p;
		int i;
		fp = fopen("F:\\point.bin", "wb");
		if (fp == NULL) {
			printf("Cannot create file\n");
			return -1;
		}
		for (i = 0; i< 5; i++) {
			printf("Enter hour and minute and second and milisecond: ");
			scanf("%d %d %d %d", &p.hour, &p.min,&p.sec,&p.mili_sec);
			fwrite(&p, sizeof(p), 1, fp);
		}
		fclose(fp);
		return 0;





	return 0;
}