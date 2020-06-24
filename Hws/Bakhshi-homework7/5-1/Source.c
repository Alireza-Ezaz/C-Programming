// Created by S.Alireza Ezaz
// Student NO : 9731009
// Ostad : Mr Bakhshi

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Tedad 5 //5 is the numbers of time in the bin file .

struct time {
	int hour;
	int min;
	int sec;
	int mili_sec;
};

/* 1: t1 > t2, 0: t1 = t2, -1: t1 < t2 */
int time_cmp(struct time t1, struct time t2) {
	if (t1.hour > t2.hour)
		return 1;
	else if (t2.hour > t1.hour)
		return -1;
	else if (t1.min > t2.min)
		return 1;
	else if (t2.min > t1.min)
		return -1;
	else if (t1.sec > t2.sec)
		return 1;
	else if (t2.sec > t1.sec)
		return -1;
	else if (t1.mili_sec > t2.mili_sec)
		return 1;
	else if (t2.mili_sec > t1.mili_sec)
		return -1;
	else
		return 0;
}

/* Find index of max element */
int rec_max(struct time time_arr[], int start, int end) {
	int tmp, res;
	if (start == end)
		res = start;
	else {
		tmp = rec_max(time_arr, start + 1, end);
		if (time_cmp(time_arr[start], time_arr[tmp]) >= 0)
			res = start;
		else
			res = tmp;
	}
	return res;
}

/* Find index of min element */
int rec_min(struct time time_arr[], int start, int end) {
	int tmp, res;
	if (start == end)
		res = start;
	else {
		tmp = rec_max(time_arr, start + 1, end);
		if (time_cmp(time_arr[start], time_arr[tmp]) <= 0)
			res = start;
		else
			res = tmp;
	}
	return res;
}

int main(void) 
{
	FILE *fp;
	struct time p[Tedad];
	long int time_in_mili[Tedad];
	int i = 0;
	char name[400];
	scanf("%s", name);
	fp = fopen(name, "rb");
	if (fp == NULL) {
		printf("Cannot read from file\n");
		return -1;
	}
	while (1) {
		if (fread(&p[i], sizeof(p)/Tedad, 1, fp) < 1)
			break;
		//printf("hour = %d, and minute = %d and second = %d and mili_second = %d\n", p[i].hour, p[i].min,p[i].sec,p[i].mili_sec);
		i++;
	}
	fclose(fp);


	int sum = 0;
	for (i = 0; i < Tedad; i++)
	{

		time_in_mili[i] = p[i].hour * 60 * 60 * 1000 + p[i].min * 60 * 1000 + p[i].sec * 1000 + p[i].mili_sec;
		sum += time_in_mili[i];


	}

	int avr = sum / Tedad;


	int avr_hour = avr / (60 * 60 * 1000);

	avr = avr - avr_hour *(60 * 60 * 1000);

	int avr_min = avr / (60 * 1000);
	avr = avr - avr_min *(60 * 1000);

	int avr_sec = avr / 1000;
	avr = avr - avr_sec * 1000;

	int avr_mili_sec = avr;
	printf("average is  : hour = %d, and minute = %d and second = %d and mili_second = %d\n", avr_hour, avr_min, avr_sec, avr_mili_sec);





	int j;
	j = rec_max( p, 0, Tedad - 1);//j is index of max
	printf("Max time is : hour = %d, and minute = %d and second = %d and mili_second = %d\n", p[j].hour, p[j].min, p[j].sec, p[j].mili_sec);
	int z;
	z = rec_min(p, 0, Tedad - 1);//z is index of min
	printf("Min time is : hour = %d, and minute = %d and second = %d and mili_second = %d\n", p[z].hour, p[z].min, p[z].sec, p[z].mili_sec);











	return 0;
}