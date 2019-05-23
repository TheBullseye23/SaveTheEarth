
#include <iostream>
using namespace std;

void CocktailSort(int a[][2], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    int i,j;
    while (swapped)
  {  swapped = false;

      for ( i = start; i < end; ++i)
        {if (a[i][0] > a[i + 1][0])
          { swap(a[i][0], a[i + 1][0]);
            swap(a[i][1],a[i+1][1]);
            swapped = true; }}

      if (!swapped)
        break;

      swapped = false;

          end--;


        for ( i = end - 1; i >= start; --i)
        { if (a[i][0] > a[i + 1][0])
          { swap(a[i][0], a[i + 1][0]);
            swap(a[i][1],a[i+1][1]);
            swapped = true;} }

        start++;
    }

    for(i=0;i<n-1;i++)
  {for(j=0;j<2;j++)
  if(a[i][0]==a[i+1][0]&&a[i][1]>a[i+1][1])
  swap(a[i][1],a[i+1][1]);}
}


int main()
{   int i,j;
    int a[50][2];int n;
    cout<<"Enter number of pairs";
    cin>>n;
    for(i=0;i<n;i++)
    {for(j=0;j<2;j++)
    cin>>a[i][j];}
    CocktailSort(a, n);
    cout<<"\nSorted array ";
    for (i = 0; i < n; i++)
    {for(j=0;j<2;j++)
    cout<<a[i][j]<<" ";}
    return 0;
}
