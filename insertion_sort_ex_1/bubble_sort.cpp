#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
 
int main()
{
    vector<int> elements;
    int n, i, j, ele;
 
    
    cin >> n;
 
    
    for(i = 0; i < n; i++)
    {
        cin >> ele;
        elements.push_back(ele);
    }
 
    clock_t tStart = clock();
 
    
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(elements[j] > elements[j + 1])
            {
                int temp = elements[j];
                elements[j] = elements[j + 1];
                elements[j + 1] = temp;
            }
        }
    }
 
    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "Time taken is " << time1 << endl;
 
    return 0;
}
 