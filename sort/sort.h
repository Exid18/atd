/*
  * swap
  * sortArray
  * 
  * (01) squareSort
  * (02) mergeSort
  * (03) heapSort
  * (04) shellSort
  * (05) quickSort
  * (06) gnomeSort
  * (07) cocktailSort
  * (08) bubbleSort
  * (09) selectSort
  * (10) insertSort
  * (11) bogoSort
  * (12) stupidSort
  * (13) stoogeSort
  * (14) pancakeSort
  */

template <typename T>
void Swap(T &a, T &b)
{
    T c = a;
      a = b;
      b = c;
}

template <typename T>
bool sortArray(T *a, const size_t Size)
{
    for(size_t i=0; i < Size-1; ++i)
    {
        if (a[i] < a[i+1])
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void squareSort(T *a, size_t Size)
{
    T *b = new T[Size];

    for(size_t i = 0; i < Size; ++i)
    {
        size_t c = 0;
        for(size_t j = 0; j < i; ++j)
        {
            if (a[j] <= a[i])
            {
                ++c;
            }
        }
        for(size_t j = i +1; j < Size; ++j)
        {
            if (a[j] < a[i])
            {
                ++c;
            }
        }

        b[c] = a[i];

        delete[] b;
    }

    for(size_t i=0; i < Size; ++i)
    {
        a[i]=b[i];
    }
}

template <typename T>
void Merge(T *a, const size_t low, const size_t mid, const size_t high)
{
    T *b = new T[high+1-low];
    int h = low,
        i = 0,
        j = mid + 1;

    while((h <= mid) && (j <= high))
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h++];
        }
        else
        {
            b[i] = a[j++];
        }
        ++i;
    }

    if (h > mid)
    {
        for(size_t k = j; k <= high; k++, ++i)
        {
            b[i] = a[k];
        }
    }
    else
    {
        for(size_t k = h; k <= mid; k++, ++i)
        {
            b[i] = a[k];
        }
    }

    for(size_t k = 0; k <= high-low; k++)
    {
        a[k+low] = b[k];
    }
    delete[] b;
}

template <typename T>
void mergeSort(T *a, const size_t low, const size_t high)
{
    size_t mid;
    if (low < high)
    {
        mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        Merge(a, low, mid, high);
    }
}

template <typename T>
void heapify(T *a, const size_t Size)
{
    for(int i = Size/2-1;i>=0;--i)
    {
        T par = a[i];
        size_t j = i;
        bool heap = false;

        while(!heap && 2*(j+1) <= Size)
        {
            size_t k = 2*(j+1)-1;

            if (k < Size-1)
            {
                if (a[k+1] > a[k])
                {
                    k=k+1;
                }
            }

            if(par > a[k])
            {
                heap = true;
            }
            else
            {
                a[j] = a[k];
                j = k;
            }
        }
        a[j] = par;
    }
}

template <typename T>
void heapSort(T *a, const size_t Size)
{
    heapify(a,Size);

    for(size_t i=1; i < Size; ++i)
    {
        Swap(a[0], a[Size - i]);
        heapify(a, Size-i);
    }
}

template <typename T>
void shellSort(T *a, size_t Size)
{
    size_t step = Size / 2;
    while (step > 0)
    {
        for(size_t i = 0; i < (Size - step); i++)
        {

            for(size_t j = i; j >= 0 && a[j] > a[j + step]; --i)
            {
                Swap(a[j], a[j + step]);
            }
        }
        step /= 2;
    }
}

template <typename T>
void quickSort(T *a, size_t first, size_t last)
{
    size_t  i = first,
            j = last;
    T x = a[(first+last) / 2];

    do {
        while (a[i] < x) ++i;
        while (a[j] > x) --j;

        if (i <= j)
        {
            if (i < j)
            {
                Swap(a[i],a[j]);
            }
            ++i;
            --j;
        }
    } while (i <= j);

    if (i < last)
    {
        quickSort(a, i, last);
    }

    if (first < j)
    {
        quickSort(a, first, j);
    }
}

template <typename T>
void gnomeSort(T *a, size_t Size)
{
    for(size_t i = 1, j = 2; i < Size; )
    {
        if (a[i-1] < a[i])
        {
            i = j++;
        }
        else
        {
            Swap(a[i-1], a[i]);
            --i;
            if (i==0)
            {
                i = j++;
            }
        }
    }
}

template <typename T>
void cocktailSort(T *a, size_t Size)
{
    for(size_t left  = 0, right = Size - 1; left < right; ++left, --right)
    {
        for(size_t i=left; i < right; ++i)
        {
            if (a[i] > a[i+1])
            {
                Swap(a[i],a[i+1]);
            }
        }

        for(size_t i = right -1; i > left; --i)
        {
            if (a[i] < a[i-1])
            {
                Swap(a[i], a[i-1]);
            }
        }
    }
}

template <typename T>
void bubbleSort(T *a, const int Size)
{
    for(size_t i=0; i < Size - 1; ++i)
    {
        for(size_t j=i+1; j < Size; ++j)
        {
            if (a[i]>a[j])
            {
                Swap(a[i],a[j]);
            }
        }
    }
}

template <typename T>
void selectSort(T *a, const size_t Size)
{
    for(size_t i=0; i < Size-1; ++i)
    {
        T b=i;

        for(size_t j=i+1; j < Size; ++j)
        {
            if (a[j]<a[b])
            {
                b=j;
            }
        }

        if (i != b)
        {
            Swap(a[i], a[b]);
        }
    }
}

template <typename T>
void insertSort(T *a, const size_t Size)
{
    for(size_t i=1; i < Size; ++i)
    {
        for (size_t j=i; j > 0 && a[j] < a[j-1]; --j)
        {
            Swap(a[j],a[j-1]);
        }
    }
}


//Подключить при необходимости
//#include <cstdlib>

template <typename T>
void bogoSort(T *a, const size_t Size)
{
    while(!sortArray(a, Size))
    {
        swap(a[rand() % Size], a[rand() % Size]);
    }
}


template <typename T>
void stupidSort(T *a, size_t Size)
{
    size_t i = 0;

    while (i < Size - 1)
    {
        if (a[i+1] < a[i])
        {
            Swap(a[i],a[i+1]);
            i = 0;
        }
        else
        {
            i++;
        }
    }
}

template <typename T>
void stoogeSort(T *a, size_t left, size_t right)
{
   int k;
   if(a[left] > a[right])
   {
      Swap(a[left], a[right]);
   }

   if ((left+1) >= right)
   {
       return;
   }

   k = (int)((right-left+1)/3);
   stoogeSort(a, left, right-k);
   stoogeSort(a, left+k, right);
   stoogeSort(a, left, right-k);
}


template <typename T>
void flip(T *a, size_t i)
{
    int start = 0;

    for(size_t j=0; j < i; ++j, --i)
    {
        Swap(a[j],a[i]);
    }
}

template <typename T>
T findMax(T *a, size_t Size)
{
   size_t iMin=a[0];
   for (size_t i = 1; i < Size; ++i)
       if (a[i] > a[iMin])
              iMin = i;
   return iMin;
}

template <typename T>
void pancakeSort(T *a, size_t Size)
{
    for (size_t i = Size; i > 1; --i)
    {
        T mi = findMax(a, i);

        if (mi != i-1)
        {
            flip(a, mi);
            flip(a, i-1);
        }
    }
}
