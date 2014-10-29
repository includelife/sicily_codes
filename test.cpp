#include <stdio.h>
#define PI 3.1415927
int main(){

	float dInInches,timeInSecond;
	int r,count=0;

	while(scanf("%f %d %f",&dInInches,&r,&timeInSecond) && r != 0){
		count++;
	    float distance = (float)(dInInches * PI * r) / (float)(5280 * 12);
	    float MPH = (float)(distance * 3600) / (float)timeInSecond;
	    printf("Trip #%i: %0.2f %0.2f\n",count,distance,MPH);
		
	}

	return 0;
}
