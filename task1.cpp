#include <iostream>
using namespace std;

int main()
{
    const int size = 5;
    int Marks[size], total = 0;
    for (int a = 0; a < size; a++)
    {
        do
        {
            cout << "Enter marks for subject " << a + 1 << " (out of 100) \n";
            cin >> Marks[a];
        } while (Marks[a] < 0 || Marks[a] > 100);
        total += Marks[a];
    }
    cout << "The total marks are " << total << endl;
    cout << "The average marks are " << (double)total / size << endl;
    ((double)total / size >= 50) ? cout << "Result: Pass\n" : cout << "Result: Fail\n";
    return 0;
}