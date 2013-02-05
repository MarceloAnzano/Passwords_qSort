#include <iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;

int partition(string* numbers, int start, int n)
{
    string pivot = numbers[n];

    while ( start < n )
    {
        while ( numbers[start] < pivot )
            start++;

        while ( numbers[n] > pivot )
            n--;

        if ( numbers[start] == numbers[n] )
            start++;
        else if ( start < n )
        {
            string tmp = numbers[start];
            numbers[start] = numbers[n];
            numbers[n] = tmp;
        }
    }

    return n;
}

void quicksort(string* numbers, int start, int n)
{
    if ( start < n )
    {
        int x = partition(numbers, start, n);
        quicksort(numbers, start, x-1);
        quicksort(numbers, x+1, n);
    }
}

int main()
{
    int c = 0, n=100;
    string passwords[100];
    string line;
    fstream myfile;
    myfile.open("top_passwords.txt");
    while(myfile.good())
    {
        getline(myfile,line);
        passwords[c]=line;
        c++;
    }

    //Laman ng Array
    /*for(c = 0; c<n; c++)
    {
        cout<<passwords[c]<<endl;
    }*/

    cout<<"\n\n\nSorting\n";
    quicksort(passwords, 0, n);

    //Laman ng Sorted Array
    for(c = 0; c<n; c++)
    {
        cout<<passwords[c]<<endl;
    }
    myfile.close();

    return 0;
}
