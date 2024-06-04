//Sibgha Ahmad
//ahmad.si@northeastern.edu
//To perform insertion sort of integers stored in a file and display the output and store it in another file.
#include <stdio.h>
#include<stdlib.h>


int main()
{
    FILE *fp;
    int arr[10],temp;
    int count=0,i,j;
    /*count will have the total number of elements in the array*/

    /*read the file*/
    fp=fopen("Input1.txt","r");
    if(fp==NULL){
        //if file returns NULL then can't open the file
        printf("\n Cannot open the file \n");
        exit(0);
    }
    
    //insert your code here
    while(fscanf(fp, "%d", &arr[count]) != EOF && count < 10) {
      count++;
    }
    fclose(fp);

    for(i = 1; i < count; i++){
      temp = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > temp){
        arr[j + 1] = arr[j];
	j = j - 1;
      }
      arr[j + 1] = temp;
    }
    printf("Sorted array:\n");
    for(i = 0; i < count; i++){
      printf("%d", arr[i]);
    }
    printf("\n");

    fp = fopen("Output.txt", "w");
    if (fp == NULL){
      printf("\n Cannot open the file \n");
      exit(0);
    }
    for(i = 0; i < count; i++){
      fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
    
    
    return 0;
}
