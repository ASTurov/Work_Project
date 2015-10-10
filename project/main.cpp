#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void merge(int a[], int p ,int q , int r)
{
    int n1,n2;
    n1 = q - p + 1;
    n2 = r - q;
    int *mL = new int[n1+1];
    int *mR = new int[n2+1];
    for(int i = 0; i < n1; i++)
    {
        mL[i] = a[p+i];
    }
    for(int i = 0; i < n2; i++)
    {
        mR[i] = a[q+i+1];
    }
    mL[n1] = pow(10.0,9)+1;
    mR[n2] = pow(10.0,9)+1;
    int i(0), j(0);
    for (int k = p; k <= r; k++)
    {
      if (mL[i] <= mR[j])  a[k] = mL[i++];
      else a[k] = mR[j++];
    }
}

void Merge_Sort(int a[], int p, int r)
{
    if(p < r){
        int q = (p + r ) / 2;
        Merge_Sort(a,p,q);
        Merge_Sort(a, q+1,r);
        merge(a,p,q,r);
    }
}

int main()
{
    unsigned int h;
    ifstream mergesort_in;
    ofstream mergesort_out;
    mergesort_in.open("sort.in");
    mergesort_out.open("sort.out");
    mergesort_in >> h;
    int *mArray = new int[h];
    for (unsigned int i = 0 ; i < h; i++)
    {
        mergesort_in >> mArray[i];
    }
    Merge_Sort(mArray, 0, h - 1);
        for (unsigned int i = 0 ; i < h; i++)
    {
           mergesort_out << mArray[i] << " ";
    }
    mergesort_in.close();
    mergesort_out.close();
}
