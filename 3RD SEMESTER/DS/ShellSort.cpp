#include <iostream>

using namespace std;

void ShellSort(int data[], int n)
{

    register int i, j, hCnt, h;
    int increments[20], k;

    // Creating Appropriate Number of Increments h
    for (h = 1, i = 0; h < n; i++)   //suppose n= 10
    {                                
        increments[i] = h;
        h = 3 * h + 1;
    }

    // Looping on the number of different increments h
    for (i--; i >= 0; i--)
    {

        h = increments[i];

        // Loop on the number of Subarray h-sorted in ith pass
        for (hCnt = h; hCnt < 2 * h; hCnt++)
        {

            //Applying Insertion Sort on Subarray Containing every hth element
            for (j = hCnt; j < n;)
            {
                int temp = data[j];
                k = j;

                while (k - h >= 0 && temp < data[k - h])
                {
                    data[k] = data[k - h];
                    k -= h;
                }
                data[k] = temp;
                j += h;
            }
        }
    }
}
