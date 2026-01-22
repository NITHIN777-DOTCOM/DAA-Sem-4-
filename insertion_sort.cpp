#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{
    vector<int> elements;
    int key, ele;
    int n;

    // Read number of elements
    cin >> n;

    // Read elements
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        elements.push_back(ele);
    }

    // Start time
    clock_t tStart = clock();

    // Insertion Sort
    for (int j = 1; j < n; j++)
    {
        key = elements[j];
        int i = j - 1;

        while (i >= 0 && elements[i] > key)
        {
            elements[i + 1] = elements[i];
            i--;
        }
        elements[i + 1] = key;
    }

    // End time
    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;
    cout << "Time taken is " << time1 << endl;

    /*
    // Print sorted array (optional)
    for (int i = 0; i < n; i++)
    {
        cout << elements[i] << " ";
    }
    */

    return 0;
}
