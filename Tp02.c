#include <stdio.h>
float average (int arr[],int n){
int sum =0;
for (int i=0;i<n;i++){
sum = sum + arr[i]; }
return (float) sum /n ;
}
int add (int a,int b){
 return a+b;
}
int max  (int a,int b){
if(a>b)
 return a;
else 
return b;
}
int main (){
int n;
printf("Enter the number of elements : ");
scanf("%d",&n);
int arr[n];
printf("Enter integers :",n);
for (int i=0;i<n;i++){
scanf("%d",&arr[i]);
}
int largest = arr[o];
for (int i=1;i<n;i++){
largest = max (largest ,arr[i] );
}
float avg = average(arr,n);
int sumExample = add (arr[0],arr[1] );
printf(" sum of first tow elements (Example) =%d ",sumExample );

printf("largest number :",largest);
printf("average =%.2f :",avg);
return 0; 
}
