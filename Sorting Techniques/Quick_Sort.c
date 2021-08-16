/*Name of program:- Quick Sort
Coder:-Dhiraj Gardi
Email:- dhiraj.21920116@viit.ac.in
*/
//Header files
#include<stdio.h>
#include<conio.h>

int partition(int*,int , int);
void Quick_Sort(int *,int , int );
void swap(int* ,int* );

void main(){
	int arr[50] , n , i ;

	printf("Enter number of elements : ");
	scanf("%d", &n);
	printf("Enter %d element",n);

	for( i=0 ; i<n ; i++ )
   {
		scanf("%d",&arr[i]);
   }

   printf("Array elements before sort : \n");
   for( i=0 ; i<n ; i++ )
   {
		printf("%d\t",arr[i]);
   }
   printf("\n\n");

   Quick_Sort(arr, 0, n-1) ;

   printf("Array elements after sort : \n");
   for( i=0 ; i<n ; i++ )
   {
		printf("%d\t", arr[i]);
   }
   printf("\n\n");
   
}

 void Quick_Sort(int arr[],int l, int h)
{    
    int j;
	if(l<h)
	{
		j = partition(arr,l, h);
		Quick_Sort(arr,l, j);
		Quick_Sort(arr,j+1, h);
	}	
}

int partition(int arr[],int l, int h)
{
	int pivot,i,j;
    pivot = arr[l];	
	i=l;
	j=h;
	
	while(i<j)
	{
		do
		{
			i++;
		}while(arr[i] <= pivot);
		do
		{
			j--;
		}while(arr[j] > pivot);
		
		if(i<j)

			{
				swap(&arr[i],&arr[j]);
				
			}
	}
	
	swap(&arr[l],&arr[j]);
	return j;
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;

}

	


