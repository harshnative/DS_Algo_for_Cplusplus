#include<iostream>
#include<conio.h>
#include<vector>

#include "matrixOperations.h"

using namespace std;

void forMatrixClass()
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

//for testing purpose
int main()
{
    // forMatrixClass();
    forSpecialMatrixClass_triDiagonalMatrix();

    return 0;
}