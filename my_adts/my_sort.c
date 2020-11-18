#include "my_sort.h"

//O(N^2)
void insertion_sort(input_type a[], unsigned int n)
{
    unsigned int j, p;
    input_type tmp;
    a[0] = INT_MIN;
    for (p = 2; p <= n; p++)
    {
        tmp = a[p];
        for (j = p; tmp < a[j-1]; j--)
        {
            a[j] = a[j -1];
        }
        a[j] = tmp;
    }
}

//increment is: h(k+1) = h(k)/2
//worst case O(N^2)
void shellsort(input_type a[], unsigned int n)
{
    unsigned int i, j, increment;
    input_type tmp;

    for (increment = n/2; increment > 0; increment /= 2)
    {
        for (i = increment + 1; i <= n; i++)
        {
            tmp = a[i];
            for (j = i; j > increment; j -= increment)
            {
                if (tmp < a[j - increment])
                {
                    a[j] = a[j - increment];
                }
                else
                {
                    break;
                }                
            }
            a[j] = tmp;
        }
    }
}

//O(NLogN)
void heapsort(input_type a[], unsigned int n)
{
    
}