#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
 
void merge(vector<int> &elements, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    vector<int> L(n1), R(n2);
 
    for (int i = 0; i < n1; i++)
        L[i] = elements[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = elements[mid + 1 + j];
 
    int i = 0, j = 0, k = left;
 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            elements[k++] = L[i++];
        else
            elements[k++] = R[j++];
    }
 
    while (i < n1)
        elements[k++] = L[i++];
 
    while (j < n2)
        elements[k++] = R[j++];
}
 
void mergeSort(vector<int> &elements, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(elements, left, mid);
        mergeSort(elements, mid + 1, right);
        merge(elements, left, mid, right);
    }
}
 
int main()
{
    vector<int> elements;
    int n, ele;
 
    // Read number of elements
    cin >> n;
 
    // Read elements
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        elements.push_back(ele);
    }
 
    clock_t tStart = clock();
 
    mergeSort(elements, 0, n - 1);
 
    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "Time taken is " << time1 << endl;
 
 
    return 0;
}