#include<stdio.h>
#define M_TO_KM 0.001 

double meter_to_km(double meters) {
    static int count = 0;  
    count++;
    printf("Function called %d times\n", count);
    return meters * M_TO_KM;
}

int main() {
    double m;
    char ch; 
    
    do{
    	printf("\nEnter meters: ");
    	scanf("%lf", &m);
		printf("Kilometers = %.3lf\n", meter_to_km(m));
		printf("\nPress y to continue and convert meters again, anything else to exit, function counter incremented automatically: ");
		scanf(" %c" , &ch);
	}while(ch=='y'||ch=='Y');


    return 0;
}
