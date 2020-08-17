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
    forMatrixClass_spiralmatrix_anticlock();
    return 0;
}