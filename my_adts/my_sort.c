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

//O(N^2)
void selection_sort(input_type a[], unsigned int n)
{
    unsigned int i, j, jMin;
    input_type tmp;
    for (i = 1; i < n; i++)
    {
        jMin = i;
        for (j = i + 1; j <= n; j++)
        {
            if (a[j] < a[jMin])
            {
                jMin = j;
            }
        }
        if (jMin != i)
        {
            tmp = a[i];
            a[i] = a[jMin];
            a[jMin] = tmp;
        }
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

//LogN
void heapsort_perc_down(input_type a[], unsigned int i, unsigned int n)
{
    unsigned int child;
    input_type tmp;
    for (tmp = a[i]; i*2<n; i=child)
    {
        child = i*2;
        if (child != n && a[child + 1] > a[child])
        {
            child += 1;
        }
        if (tmp < a[child])
        {
            a[i] = a[child];
        }
        else
        {
            break;
        }        
    }
    a[i] = tmp;
}

//O(NLogN)
void heapsort(input_type a[], unsigned int n)
{
    int i;
    input_type tmp;
    for (i = n/2; i > 0; i--)
    {
        heapsort_perc_down(a, i, n);
    }
    for (i = n; i >= 2; i--)
    {
        tmp = a[1];
        a[1] = a[i];
        a[i] = tmp;
        heapsort_perc_down(a, 1, i-1);
    }
}

//for merge sort
void merge(input_type a[], input_type tmp_array[], int l_pos, int r_pos, int right_end)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = r_pos - 1;
    tmp_pos = l_pos;
    num_elements = right_end - l_pos + 1;
    while(l_pos <= left_end && r_pos <= right_end)
    {
        if (a[l_pos] <= a[r_pos])
        {
            tmp_array[tmp_pos++] = a[l_pos++];
        }
        else
        {
            tmp_array[tmp_pos++] = a[r_pos++];
        }        
    }
    while(l_pos <= left_end)
    {
        tmp_array[tmp_pos++] = a[l_pos++];
    }
    while(r_pos <= right_end)
    {
        tmp_array[tmp_pos++] = a[r_pos++];
    }
    for (i = 1; i <= num_elements; i++, right_end--)
    {
        a[right_end] = tmp_array[right_end];
    }
}

//for merge sort
void m_sort(input_type a[], input_type tmp_array[], int left, int right)
{
    int center;
    if (left < right)
    {
        center = (left + right)/2;
        m_sort(a, tmp_array, left, center);
        m_sort(a, tmp_array, center + 1, right);
        merge(a, tmp_array, left, center + 1, right);
    }
}

//worst O(NLogN)
//but 3rd array required, more memory consumed. data copying btw arrays costy
//thus, this is not recommended for internal sorting, instead, quicksort is recommended
//it is cornerstone of external sorting
void mergesort(input_type a[], unsigned int n)
{
    input_type *tmp_array;
    tmp_array = (input_type*)malloc((n+1)*sizeof(input_type));
    m_sort(a, tmp_array, 1, n);
    free(tmp_array);
}

//O(n*k) in case 10 based, k = 10
//copied from https://github.com/DaniloNovakovic/sorting-algorithms-in-c/blob/master/O-n/radix_sort.c
void radix_sort(input_type a[], unsigned int n)
{
	QUEUE buckets[MAX_BUCKETS]; // buckets for 0, 1, 2, ... 9 significant digits
	int i, j;
	for(i = 0; i < MAX_BUCKETS; i++)
		init_queue(&buckets[i]);
	
	int k = find_max_significant(a, n);
	int m = 10, n = 1, p;
	
	for(i = 0; i < k; i++){
		for(j = 0; j < n; j++){
			inqueue(&buckets[((int)a[j]%m)/n], a[j]);
		}
		for(p = 0, j = 0; j < MAX_BUCKETS; j++){
			while(!is_empty(buckets[j])) {
				a[p++] = dequeue(&buckets[j]); 
				//first a[p] = ... is done and then p++ afterwards.
			}
		}
		n*=10;
		m*=10;
	}
}

void swap(input_type *a, input_type *b)
{
    input_type tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

input_type median3(input_type a[], int left, int right)
{
    int center;
    center = (left + right)/2;
    if (a[left] > a[center]) swap(&a[left], &a[center]);
    if (a[left] > a[right]) swap(&a[left], &a[right]);
    if (a[center] > a[right]) swap(&a[center], &a[right]);
    swap(&a[center], &a[right - 1]);
    return a[right - 1];
}

static const unsigned int CUTOFF = 10;
void q_sort(input_type a[], int left, int right)
{
    int i, j;
    input_type pivot;
    if (right - left < CUTOFF) return;
    pivot = median3(a, left, right);
    i = left; j = right - 1;
    for(;;)
    {
        while (a[++i] < pivot);
        while (a[--j] > pivot);
        if (i < j) swap(&a[i], &a[j]);
        else break;        
    }
    swap(&a[i], &a[right-1]);
    q_sort(a, left, i-1);
    q_sort(a, i+1, right);
}

/*
 * fastest known sorting in practice
 * average O(n logn), best O(n logn), worst O(n^2) but could be avoided.
 * compare merge sort, subproblems not equally which is bad, 
 * pivot picking and partitioning performed efficiently which is essential reason why it is faster than merge sort
 * pivot selection wrong ways: 1. first element; 2. larger of the first two distinct keys as pivot
 * select pivot randomly, not consistently provide poor partition, but random generation is costy
 * good pivot selection concept is: median of three, sort left right and middle before partitioning (this is important)
 * i, j stops if encounter a key equal to the pivot, do unnecessary swaps and create even subfiles than to risk widly uneven subfiles which would be (O n^2)
 * best practice: turn to selection sort for n<10 
*/
void quick_sort(input_type a[], unsigned int n)
{
    q_sort(a, 1, n);
    insertion_sort(a, n);
}

void insert_sort(input_type a[], int left, int right)
{
    int i, j;
    input_type tmp;
    for (i = left + 1; i <= right; i++)
    {
        tmp = a[i];
        for (j = i; j > left; j--) 
        {
            if (tmp < a[j-1]) a[j] = a[j-1];
            else break;
        }
        a[j] = tmp;
    }
}

/*
 * if using priority queue, it is O(n + k*logn)
 * using qsort, average O(N), worst O(n^2)
 * in chapter 10, another pivot selection result in O(N) in worst case
*/
void q_select(input_type a[], int k, int left, int right)
{
    int i, j;
    input_type pivot;
    if (left + CUTOFF <= right)
    {
        pivot = median3(a, left, right);
        i = left; j = right -1;
        for (;;)
        {
            while (a[++i] < pivot);
            while (a[--j] > pivot);
            if (i < j) swap(&a[i], &a[j]);
            else break;
        }
        swap(&a[i], &a[right - 1]);
        if (k < i) q_selet(a, k, left, i -1);
        else if (k > i) q_select(a, k, i+1, right);
    }
    else
    {
        insertion_sort(a, left, right);
    }    
}

void quick_select(input_type a[], unsigned int k, unsigned int n)
{
    int left, right;
    left = 1;
    right = n;
    q_select(a, k, left, right);
}