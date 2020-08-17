# Matrix Operations Header File -

A header file that as number of pre loaded matrix operations , just pass the value and see the results 


# How to import - 

Download the matrixOperations.h header file and paste it into your source code folder and then write this in your .cpp file

```C++
#include "matrixOperations.h"
```

#### Note - almost all operations are on vector matrix


# classes - 

1. ## Matrix

creating a object for using methods

```C++
Matrix m;
```

<br />
<br />

### Methods in Matrix Class

1. #### transposing a matrix

returns a transposed matrix

```C++
transposed = m.transposeMatrix(vector <vector <int>> v);
```
<br />
<br />

2. #### increasing matrix size to passed m and n with value

inserts values to increase matrix size to desired number of row and col

```C++
m.increaseMatrix(vector <vector <int>> &v , int m , int n , int value = 0)
```
<br />
<br />


3. #### adding two matrix

return the addition result of two matrix

```C++
added = m.add2Matrix(vector <vector <int>> v1 , vector <vector <int>> v2)
```
<br />
<br />

4. #### multiply two matrix

return the multiplication result of two matrix

```C++
added = m.multiply2Matrix(vector <vector <int>> v1 , vector <vector <int>> v2)
```
<br />
<br />


5. #### take input from user

return the matrix inputted by user

```C++
inputted = m.input2dArray(int row , int coloumn)
```
<br />
<br />


6. #### print matrix

matrix will be printed seperated by the sep

```C++
m.printMatrix(vector <vector <int>> v , string sep = " ")
```
<br />
<br />


7. ####  find saddle point of matrix

returns the saddle point of matrix , throws error if no saddle point is found

```C++
m.saddlePointOfMatrix(vector <vector <int>> v)
```
<br />
<br />

8. ####  print matrix in spiral form

if clockwise is false then it will print in anti clock wise direction

```C++
m.printMatrixInSpiralForm(vector <vector<int>> a , string sep = " " , bool clockWise = true)
```
<br />
<br />









2. ## SpecialMatrix

creating a object for using methods

```C++
SpecialMatrix sm;
```

<br />
<br />

### Methods in SpecialMatrix Class

1. #### reduce the diagonal type matrix

returns a reduced 1d array from diagonal type matrix

```C++
reduced = sm.diagonalMatrix(vector <vector <int>> v)
```
<br />
<br />

2. #### reduce the tridiagonal type matrix

returns a reduced 1d array from tridiagonal type matrix

mapping = 0 for row wise , 1 for coloumn vise , 2 for diagonal vise

```C++
reduced = sm.triDiagonalMatrix(vector <vector <int>> v , int mapping = 0)
```
<br />
<br />


2. #### reduce the triangular type matrix

returns a reduced 1d array from triangular type matrix

0 for row mapping , 1 for col mapping 

set lowerTriangular = true for lower tiangular mat else make it false for upper trianglar mat

```C++
reduced = sm.triangularMatrix(vector <vector <int>> v , int mapping = 0 , int lowerTriangular = false)
```
<br />
<br />



# sample program - 

```c++
#include<iostream>
#include<conio.h>
#include<vector>

#include "matrixOperations.h"

using namespace std;

void forMatrixClass_saddlePoint()
{
    vector <vector <int>> array;

    Matrix m;
    
    cout<<"input the 3 by 3 matrix"<<endl;
    array = m.input2dArray(3 , 3);

    cout<<"\n initial Array = "<<endl;
    m.printMatrix(array);

    int saddlePoint = 0;
    saddlePoint = m.saddlePointOfMatrix(array);
    cout<<"\n saddle point = "<<saddlePoint;
}


void forMatrixClass_spiralmatrix()
{
    vector <vector <int>> array;

    Matrix m;
    
    cout<<"input the 4 by 4 matrix"<<endl;
    array = m.input2dArray(4 , 4);

    cout<<"\n initial Array = "<<endl;
    m.printMatrix(array);

    cout<<"\n spiral form = "<<endl;
    m.printMatrixInSpiralForm(array);
}


void forMatrixClass_spiralmatrix_anticlock()
{
    vector <vector <int>> array;

    Matrix m;
    
    cout<<"input the 4 by 4 matrix"<<endl;
    array = m.input2dArray(4 , 4);

    cout<<"\n initial Array = "<<endl;
    m.printMatrix(array);

    cout<<"\n spiral form = "<<endl;
    m.printMatrixInSpiralForm(array , " " , false);
}

void forMatrixClass_tarnsposeMatrix()
{
    vector <vector <int>> array;

    Matrix m;
    
    cout<<"input the 3 by 3 matrix"<<endl;
    array = m.input2dArray(3 , 3);

    cout<<"\n initial Array = "<<endl;
    m.printMatrix(array);

    cout<<"\n matrix after transpose = "<<endl;
    vector <vector <int>> transposedArray;
    transposedArray = m.transposeMatrix(array);
    m.printMatrix(transposedArray);
}


void forMatrixClass_multiplyMatrix()
{
    vector <vector <int>> array1;
    vector <vector <int>> array2;

    Matrix m;
    
    cout<<"input the 2 by 3 matrix 1"<<endl;
    array1 = m.input2dArray(2 , 3);

    cout<<"input the 3 by 2 matrix 2"<<endl;
    array2 = m.input2dArray(3 , 2);

    cout<<"\n initial Array 1 = "<<endl;
    m.printMatrix(array1);

    cout<<"\n initial Array 1 = "<<endl;
    m.printMatrix(array2);


    cout<<"\n matrix after multiplication = "<<endl;
    vector <vector <int>> multiplyResult;
    multiplyResult = m.multiply2Matrix(array1 , array2);
    m.printMatrix(multiplyResult);
}

void forMatrixClass_addMatrix()
{
    vector <vector <int>> array1;
    vector <vector <int>> array2;

    Matrix m;
    
    cout<<"input the 2 by 3 matrix 1"<<endl;
    array1 = m.input2dArray(2 , 3);

    cout<<"input the 3 by 2 matrix 2"<<endl;
    array2 = m.input2dArray(3 , 2);

    cout<<"\n initial Array 1 = "<<endl;
    m.printMatrix(array1);

    cout<<"\n initial Array 1 = "<<endl;
    m.printMatrix(array2);


    cout<<"\n matrix after addition = "<<endl;
    vector <vector <int>> multiplyResult;
    multiplyResult = m.add2Matrix(array1 , array2);
    m.printMatrix(multiplyResult);
}

void forSpecialMatrixClass_diagonalMatrix()
{
    vector <vector <int>> array;

    SpecialMatrix sm;
    Matrix m;
    
    cout<<"input the 3 by 3 matrix"<<endl;
    array = m.input2dArray(3 , 3);

    cout<<"\n initial diagonal matrix = "<<endl;
    m.printMatrix(array);

    vector <int> reducedarray;
    reducedarray = sm.diagonalMatrix(array);
    cout<<"\n reduced Array from diagonal matrix = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }

}


void forSpecialMatrixClass_triDiagonalMatrix()
{
    vector <vector <int>> array;

    SpecialMatrix sm;
    Matrix m;
    
    cout<<"input the 4 by 4 matrix"<<endl;
    array = m.input2dArray(4 , 4);

    cout<<"\n initial triDiagonal matrix = "<<endl;
    m.printMatrix(array);

    vector <int> reducedarray;
    reducedarray = sm.triDiagonalMatrix(array , 0);
    cout<<"\n reduced Array from triDiagonal matrix using row mapping = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }

    reducedarray.clear();
    reducedarray = sm.triDiagonalMatrix(array , 1);
    cout<<"\n reduced Array from triDiagonal matrix using coloumn mapping = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }

    reducedarray.clear();
    reducedarray = sm.triDiagonalMatrix(array , 2);
    cout<<"\n reduced Array from triDiagonal matrix using diagonal mapping = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }
}

void forSpecialMatrixClass_triangularMatrixLower()
{
    vector <vector <int>> array;

    SpecialMatrix sm;
    Matrix m;
    
    cout<<"input the lower triangular 4 by 4 matrix"<<endl;
    array = m.input2dArray(4 , 4);

    cout<<"\n initial triangular matrix = "<<endl;
    m.printMatrix(array);

    vector <int> reducedarray;
    reducedarray = sm.triangularMatrix(array , 0 , true);
    cout<<"\n reduced Array from lowerTriangular matrix using row mapping = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }

    reducedarray.clear();
    reducedarray = sm.triangularMatrix(array , 1 , true);
    cout<<"\n reduced Array from lowerTriangular matrix using coloumn mapping = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }

}

void forSpecialMatrixClass_triangularMatrixUpper()
{
    vector <vector <int>> array;

    SpecialMatrix sm;
    Matrix m;
    
    cout<<"input the upper triangular 4 by 4 matrix"<<endl;
    array = m.input2dArray(4 , 4);

    cout<<"\n initial triangular matrix = "<<endl;
    m.printMatrix(array);

    vector <int> reducedarray;
    reducedarray = sm.triangularMatrix(array , 0);
    cout<<"\n reduced Array from upperTriangular matrix using row mapping = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }

    reducedarray.clear();
    reducedarray = sm.triangularMatrix(array , 1);
    cout<<"\n reduced Array from upperTriangular matrix using coloumn mapping = "<<endl;
    for(int i=0 ; i<reducedarray.size() ; i++)
    {
        cout<<reducedarray[i]<<" ";
    }
}

//for testing purpose
int main()
{
    // call function here
    return 0;
}
```

