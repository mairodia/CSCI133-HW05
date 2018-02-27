// ============================================================================
// File: find_max_array.cpp (Spring 2018)
// ============================================================================
// Programmer: Jennifer King
// Date: 2/27/2018
// Project: Find Max Array
// Professor: Scott Edwards
// Class: CSCI133F | TR 9:30AM
// Description:
//      This program is an exercise in working with two-dimensional arrays and
//      pointers-to-pointers. A two-dimensional array of ints is allocated from
//      the stack and initialized in "main". This is passed to FindMaxArray,
//      along with the address of a local pointer-to-an-int. After the function
//      returns, the local int pointer should be pointing to the array with the
//      largest sum.
//
// Output:
//      Here is the array with the maximum sum:
//      22 + 500 + -67 + 1 = 456
//
// ============================================================================

#include    <iostream>
using namespace std;


// constants
const int NUM_ARRAYS = 5;
const int NUM_ELEMS  = 4;


// function prototypes (fill in any missing formal parameter lists)
int     CalcArraySum(int  array[], int  numItems);
void    DispArray(int  array[], int  numItems);
int     FindMaxArray(int matrix[][NUM_ELEMS], int numArrays, int **arrayPtr);


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    int         intArrays[NUM_ARRAYS][NUM_ELEMS] = {  {10, 20, 30, 40}  // 100
                                                    , {1, 2, 3, 4}      // 10
                                                    , {5, 2, -8, 22}    // 21
                                                    , {99, 3, 10, 34}   // 146
                                                    , {22, 500, -67, 1} // 456
                                                   };
    int         *arrayPtr;
    int         sum;

    sum = FindMaxArray(intArrays, NUM_ARRAYS, &arrayPtr);
    cout << "Here is the array with the maximum sum:\n";
    DispArray(arrayPtr, NUM_ELEMS);
    cout << " = " << sum << endl;

    return  0;

}  // end of "main"

// == CalcArraySum ============================================================
// Calculates the sum of all the numbers in the array
//
// IN:
//               array     -- array that is being calculated
//           numItems  -- number of items in the array
//
// OUT:
//              sum -- the sum of all the numbers in the array
// ===========================================================================
int CalcArraySum(int array[], int numItems)
{
    int sum = 0;

    for(int index = 0; index < numItems; index ++)
    {
        sum += array[index];
    }

    return sum;
}

// == DispArray ==============================================================
// Displays the array.
//
// IN:
//              array    -- array to be displayed
//              numItems -- number of items in the array
//
// OUT:
//              void; nothing
// ===========================================================================
void DispArray(int array[], int numItems)
{
    for(int index = 0; index < (numItems - 1); index ++)
    {
        cout << array[index] << " + ";
    }

    // this is so it doesn't output a "+" after the last element
    cout << array[numItems-1];
}

// == FindMaxArray ===========================================================
// Finds and returns the largest sum of the arrays in the matrix.
//
// IN:
//              matrix    -- array of arrays being calculated for sums
//              numArrays -- number of arrays in matrix
//              arrayPtr  -- points to the array with the largest sum
//
// OUT:
//              max -- the largest sum of the arrays
// ===========================================================================
int FindMaxArray(int matrix[][NUM_ELEMS], int numArrays, int **arrayPtr)
{
    int sums[numArrays];

    for(int index = 0; index < numArrays; index++)
    {
        sums[index] = CalcArraySum(matrix[index], NUM_ELEMS);
    }

    int counter = 0;
    int max = 0;

    while(counter < numArrays)
    {
        if(sums[counter] > max)
        {
            max = sums[counter];
            *arrayPtr = matrix[counter];
        }

        counter++;
    }

    return max;
}

