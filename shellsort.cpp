/*
 * shell sort test
 * platform: win32, visual studio 2005/2010; Linux, gcc4.1.2
 */

#include <iostream>
using namespace std;

/*
 * one sort in shell sort
 * a is the array to save data, n is its number
 * d is the current step length
 */
void shell_pass(int a[], int n, int d)
{
    for (int loop = d; loop <n; loop++)  //sort a[d], a[2d], ..., and insert its right position
    {
        if (a[loop] < a[loop - d])
        {
            int tmp = a[loop];
            int pos = loop - d;
            do  //find the position of a[loop]
            {
                a[pos + d] = a[pos];  //move the data
                pos = pos - d;
            } while (pos > 0 && tmp < a[pos]);
            a[pos + d] = tmp;  //insert a[loop] into its right position
        }
    }    
}

void shell_sort(int a[], int n)
{
    int step = n;
    do
    {
        step = step/3 + 1;
        shell_pass(a, n, step);
    } while(step > 1);
}

void dump(int a[], int n)
{
    int loop = 0;
    for (loop = 0; loop < n - 1; loop++)
        cout << a[loop] << ", ";
    cout << a[loop] << endl;
}

int main()
{
    int a[] = {49, 38, 65, 97, 76, 13, 27, 49, 55, 4};
    cout << "original : ";
    dump(a, 10);

    cout << "shellsort: ";
    shell_pass(a, 10, 5);
    dump(a, 10);

    cout << "shellsort: ";
    shell_pass(a, 10, 3);
    dump(a, 10);

    cout << "shellsort: ";
    shell_pass(a, 10, 1);
    dump(a, 10);
    return 0;
}

