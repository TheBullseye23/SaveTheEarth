#include <iostream>

using namespace std;

void countsort(int a[][2],int n)
{ int output[100][2];
   int i,j;                                 //declarations
  int count[101];

  for(i=0;i<101;i++)  //making count = 0
   count[i]=0;

  for(i=0;i<n;i++)              //updating count with the first value of each pair
  count[a[i][0]]++;

  for(i=1;i<100;i++)
  count[i]+=count[i-1];    //finding cumulative frequency

  for(i=n-1;i>=0;i--)
  { output[count[a[i][0]]-1][0]=a[i][0];        //placing first value of each pair
    output[count[a[i][0]]-1][1]=a[i][1];   //placing second value of each pair
    count[a[i][0]]--;
  }

  for(i=0;i<n;i++)      //copying the required array
  {for(j=0;j<2;j++)
  a[i][j]=output[i][j];
  }

  for(i=0;i<n-1;i++)
  {for(j=0;j<2;j++)
  if(a[i][0]==a[i+1][0]&&a[i][1]>a[i+1][1])
  { int t=a[i][1];
    a[i][1]=a[i+1][1];
    a[i+1][1]=t;}
}

}
int main()
{   int a[100][2];
    int i,n,j;
    cout<<"Enter number of pairs ";
    cin>>n;
    cout<<"\nEnter the elements";
    for(i=0;i<n;i++)
    {for(j=0;j<2;j++)
    cin>>a[i][j];}
    cout<<"\nThe sorted array is :";
    countsort(a,n);
    for(i=0;i<n;i++)
    {for(j=0;j<2;j++)
    cout<<a[i][j]<<"  ";}
    return 0;
}
