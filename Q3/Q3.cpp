#include <vector>
#include <iostream>

// слияние массивов в один отсортированный
void merge(std::vector<int> &C, int beg, int mid, int end)
{
    std::vector<int> A, B;
    A.resize(mid - beg + 1);
    B.resize(end - mid);

    for (int i = 0; i < A.size(); i++)
        A[i] = C[beg+i];

    for (int i = 0; i < B.size(); i++)
        B[i] = C[mid+i+1];

    int i = 0, j = 0;

    while (i < A.size() && j < B.size())
    {
        if (A[i] <= B[j])
        {
            C[beg+i+j] = A[i];
            i++;
        }
        else
        {
            C[beg+i+j] = B[j];
            j++;
        }
    }

    if (i == A.size())
        while (j < B.size())
        {
            C[beg+i+j] = B[j];
            j++;
        }
    else if (j == B.size())
        while (i < A.size())
        {
            C[beg+i+j] = A[i];
            i++;
        }
}

// собственно сортировка
void sort(std::vector<int> &A, int beg, int end)
{
    if (beg >= end)
        return;

    int mid = (beg + end) / 2;

    sort(A, beg, mid);
    sort(A, mid+1, end);
    merge(A, beg, mid, end);

}

int main()
{
    std::vector<int> A;
    const int len = 10;

    // пример с отсортированным наоборот массивом
    A.resize(len);
    for (int i = 0; i < len; i++)
        A[i] = len - i;
    
    std::cout << "Initial array: ";
    for (const int& x : A)
        std::cout << x << " ";
    
    sort(A, 0, A.size() - 1);

    std::cout << "\nSorted array: ";
    for (const int& x : A)
        std::cout << x << " ";

    return 0;
}