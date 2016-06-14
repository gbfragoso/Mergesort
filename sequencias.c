#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i = 0, j = 0, k = 0, num = 0, size = 0;
    char filename[23];

    // Random seed
    srand(time(NULL));

    printf("Please, inform number of samples: ");
    scanf("%d", &size);

    for (k = 0; k < size; k++){
	    snprintf(filename, sizeof(char) * 32, "sample%i.txt", k + 1);
	    FILE *output = fopen(filename,"w");

	   	// Generate 1024 sequences of 1024 random numbers;
	    if(output != NULL){
	        for(i = 0; i < 1024; i++){
	            for(j=0; j < 1024; j++){
	                num = (int) 1 + (rand()%1024);
	                fprintf(output,"%d ", num);
	            }
	            fprintf(output,"\n");
	        }
	    }

	    fclose(output);
	}
    return 0;
}
