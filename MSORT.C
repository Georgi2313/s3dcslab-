#include<stdio.h>
#include<string.h>
#include<conio.h>

void merge(int *arr[],int f1,int l1,int f2,int l2)
{
   int a[10],b[10],ff,ss,i,j;

   //to insert first half of the array arr into a
   for(i=0;i<=(l1-f1);i++)
   {
      a[i]=*arr[f1+i];
   }

   //to insert second half of the array arr into b
   for(j=0;j<=(l2-f2);j++)
   {
      b[j]=*arr[l2+j];
   }
   ff=0;
   ss=0;
   while(ff<i && ss<j)
   {
      if(a[ff]<b[ss])
      {
	 *arr[f1+ff+ss]=a[ff];
	 ff++;
      }

      else
      {
	 *arr[f1+ff+ss]=b[ss];
	 ss++;
      }

   }
   if(ff!=(i-1))
   {
      *arr[f1+ff+ss]=a[ff];
      ff++;
   }

   else if(ss!=(j-1))
   {
      *arr[f1+ff+ss]=b[ss];
      ss++;
   }

}

void split(int *arr[],int f,int l)
{
   int m=(f+l)/2,i;
   int a[10],b[10];

   //to insert first half of the array arr into a
   for(i=0;i<=(m-f);i++)
   {
      a[i]=*arr[f+i];
   }

   //to insert second half of the array arr into b
   for(i=0;i<(l-m);i++)
   {
      b[i]=*arr[m+1+i];
   }

   if(l<f)
   {
      split(arr,f,m);
      split(arr,m+1,l);
      merge(arr,f,m,m+1,l);
   }
}

void main()
{
   int arr[20],n,i;//,*ptr;
   clrscr();
   printf("Enter the no of elements: ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&arr[i]);
   }
//   ptr=&arr[0];
   split(arr,0,n-1);

   printf("\nsorted array: \n");
   for(i=0;i<n;i++)
   {
      printf("%d ",arr[i]);
   }
   getch();
}