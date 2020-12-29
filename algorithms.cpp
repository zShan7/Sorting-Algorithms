#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
//--------------
//MALIK ZEESHAN AHMAD
//307629
//--------------
int partitions = 0;
void display(int sortedArray[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << sortedArray[i] << " ";
   }
}
void swap(int *num1, int *num2)
{
   //usual sqp operation to swap things whnever necessary
   //i chose to use pointers since
   //we shouldnt have to pass around the entire array and alements
   //just to switch twdo elements
   int *hold = num1;
   num1 = num2;
   num2 = hold;
}
//the bubble soort algorithm implementation in cpp
void bubbleSort(int a[], int size)
{
   int i, j;
   //size is already stripped to be enough to loop through
   //the whole array
   //so no need to do size-1
   for (i = size; i > 0; i--)
   {
      for (j = 0; j < i - 1; j++)
      {
         if (a[j] > a[j + 1])
         {
            swap(a[j], a[j + 1]);
         }
      }
   }
}
//the selection sort algorithm's implemenattion in C+++
void selectionSort(int a[], int size)
{
   //size is already stripped to be enough to loop through
   //the whole array
   //so no need to do size-1
   int i, j, max;
   for (i = size; i >= 0; i--)
   {
      max = i;
      for (j = 0; j < i - 1; j++)
      {
         if (a[j] > a[max])
         {
            swap(a[j], a[max]);
         }
      }
   }
}
//the isnertion sort algo implementation
void insertionSort(int a[], int size)
{
   int i, j, key;
   for (i = 1; i < size; i++)
   {
      key = a[i];
      j = i - 1;
      while (j >= 0 && a[j] > key)
      {
         a[j + 1] = a[j];
         j = j - 1;
      }
      a[j + 1] = key;
   }
}

//the merge sort algo implementation
void merge(int *myArray, int first, int centre, int last)
{
   int
       //creating variables to loop thru the original unsorted subproblems
       holderStart = first,
       midPoint = centre + 1,
       startHolder = first,
       sortedArray[last + 1];
   while (holderStart <= centre && midPoint <= last)
   { //loop till center is reached or last is reached
      if (myArray[holderStart] < myArray[midPoint])
      {
         sortedArray[startHolder++] = myArray[holderStart++];
      }
      else
      {
         sortedArray[startHolder++] = myArray[midPoint++];
      }
   }
   while (holderStart <= centre)
   { //till start reaches center
      sortedArray[startHolder++] = myArray[holderStart++];
   }
   while (midPoint <= last)
   { //till last is reached
      sortedArray[startHolder++] = myArray[midPoint++];
   }
   for (holderStart = first; holderStart < startHolder; holderStart++)
   { //now copying the whole sorted thing into the original array
      myArray[holderStart] = sortedArray[holderStart];
   }
}

void mergeSort(int *a, int first, int last)
{
   int middle;
   if (first < last)
   {
      //finfing mid
      middle = (first + last) / 2;
      //power of recusrion unlocked when you solve/deal with subproblem ...
      mergeSort(a, first, middle);
      mergeSort(a, middle + 1, last);
      //....and then combine subsolutions to make a whole
      merge(a, first, middle, last);
   }
}

int partition(int *a, int p, int r)
{
   //implementing partition method given in lab
   partitions++;
   //inc =rementing partition because a new partittons has occured
   int x, i, j;
   //choosing pivot as left most element
   x = a[p];
   //variables to loop through array to sort acc to pivot
   i = p - 1;
   j = r + 1;
   while (true)
   {
      //check which element is less than our pivot on right side
      do
      {
         j = j - 1;
      } while (a[j] > x);
      //find element on left that is greater than the one pivit
      do
      {
         i = i + 1;
      } while (a[i] < x);
      //now swapping the elements that were bigger than that pivot on left to right's smaller
      if (i < j)
      {
         swap(a[i], a[j]);
      }
      else
      {
         //if i>=j i.e sorting is done, break the loop and send j as new pivot variable
         return j;
      }
   }
}
void quickSort(int *a, int p, int r)
{
   int q;
   if (p < r)
   {
      //  finding pratition
      q = partition(a, p, r);
      //quick sort on left side of partition
      quickSort(a, p, q);
      //quick sort on right side of partition
      quickSort(a, q + 1, r);
   }
}
int *createAndFillArray(int size)
{
   //filling the array with random numbers
   srand(time(NULL));
   //of whatever size user wants
   int *array = new int[size];
   for (int i = 0; i < size; i++)
   {
      //putting random 1-100 elemensts in array
      array[i] = rand() % 100 + 1;
   }
   //the pointer goes back so the original array is intact
   return array;
}

int main()
{
   int *num;
   //this was taken from geekforgeeks to record time taken for algo run
   clock_t startingTime, endingTime;
   double timeTaken;
   //-----------------------------------bubble sort---------------------------------------
   cout << endl
        << "--------------------------------  BUBBLE SORT  ---------------------- " << endl;
   cout << endl
        << "sorted ascending........BEST CASE" << endl
        << endl;
   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i);
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      bubbleSort(num, i);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   cout << endl
        << "sorted descending...    WORST CASE" << endl
        << endl;

   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i, greater<int>());
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      bubbleSort(num, i);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   //-----------------------------------selection sort---------------------------------------
   cout << endl
        << "--------------------------------  SELECTION SORT  ---------------------- " << endl;
   cout << endl
        << "sorted ascending........BEST CASE" << endl
        << endl;
   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i);
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      selectionSort(num, i);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   cout << endl
        << "sorted descending.......WORST CASE" << endl
        << endl;

   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i, greater<int>());
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      selectionSort(num, i);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   //-----------------------------------insertion sort---------------------------------------
   cout << endl
        << "--------------------------------  INSERTION SORT  ---------------------- " << endl;
   cout << endl
        << "sorted ascending........BEST CASE" << endl
        << endl;
   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i);
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      insertionSort(num, i);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   cout << endl
        << "sorted descending........WORST CASE" << endl
        << endl;

   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i, greater<int>());
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      insertionSort(num, i);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   //-----------------------------------merge sort---------------------------------------
   cout << endl
        << "--------------------------------  MERGE SORT  ---------------------- " << endl;
   cout << endl
        << "sorted ascending........BEST CASE" << endl
        << endl;
   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i);
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      mergeSort(num, 0, i - 1);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   cout << endl
        << "sorted descending........WORST CASE" << endl
        << endl;

   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i, greater<int>());
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      mergeSort(num, 0, i - 1);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by " << i << " elements -->" << fixed << timeTaken << endl;
   }
   //-----------------------------------merge sort---------------------------------------
   cout << endl
        << "--------------------------------  QUICK SORT  ---------------------- " << endl;
   cout << endl
        << "sorted ascending........BEST CASE" << endl
        << endl;
   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i);
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      quickSort(num, 0, i - 1);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by     " << i << " elements -->" << fixed << timeTaken << endl;
   }
   cout << endl
        << "sorted descending........WORST CASE" << endl
        << endl;

   for (int i = 100; i <= 10000; i *= 10)
   {
      num = createAndFillArray(i);
      //sorting the array
      sort(num, num + i, greater<int>());
      //now starting time recorded for sorted array
      startingTime = clock();
      //the actual algo called
      quickSort(num, 0, i - 1);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by " << i << " elements -->" << fixed << timeTaken << endl;
   }
   /*
   for (int i = 100; i <= 100000; i *= 10)
   {
      //showing the length of array
      cout << endl
           << endl
           << " ---------------FOR " << i << " ELEMENTS -----------" << endl;
      //creating randomized array
      //so each time loop runs we dont have best/ worst case
      //this ensure unbiased output
      num = createAndFillArray(i);
      //now starting time recorded
      startingTime = clock();
      //the actual algo called
      bubbleSort(num, i);
      //stop time recorded
      endingTime = clock();
      //calculating the tame taken by sub end-start and then getting seconds
      double timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      //displaying time taken
      cout << "time taken by -->     BUBBLE SORT " << fixed << timeTaken << endl;
      //repeat the baove 7 lines but for each different algo
      num = createAndFillArray(i);
      startingTime = clock();
      selectionSort(num, i);
      endingTime = clock();
      timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      cout << "time taken by -->  SELECTION SORT " << fixed << timeTaken << endl;
      //repeat for insertion
      num = createAndFillArray(i);
      startingTime = clock();
      insertionSort(num, i);
      endingTime = clock();
      timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      cout << "time taken by -->  INSERTION SORT " << fixed << timeTaken << endl;
      //repeat for merge
      num = createAndFillArray(i);
      startingTime = clock();
      mergeSort(num, 0, i - 1);
      endingTime = clock();
      timeTaken = double(endingTime - startingTime) / double(CLOCKS_PER_SEC);
      cout << "time taken by -->      MERGE SORT " << fixed << timeTaken << endl;
   }*/

   //bye bye siotos
   system("pause");
}
