#include<stdio.h>
int main (){
  int n;
  int arr [n][n],i,j;
  int h = arr [i][j];
    printf("enter size of the square matrix :");
           scanf("%d",&n);

    printf("enter the elements of the matrix :\n");
       for(i=0 ;i<n ;i++){
         for(j=0 ;j<n ;j++){
           scanf("%d",&arr [i][j]);
                                      }
                                          }
    printf("the matrix before :\n");
       for(i=0 ;i<n ;i++){
         for(j=0 ;j<n ;j++){
           scanf("%d",&arr[i][j]);
                                      }
         printf("\n");
                                          }

       for(i=0 ;i<n ;i++){
         for(j=i+1 ;j<n ;j++){
            arr[i][j]=arr[j][i];
            arr[i][j]=h;
                                      }        
                                          }
    printf("the matrix after :\n");
       for(i=0 ;i<n ;i++){
         for(j=0 ;j<n ;j++){
           scanf("%d",&arr[i][j]);
                                      }
         printf("\n");
                                          }
return 0;
                                                   }
