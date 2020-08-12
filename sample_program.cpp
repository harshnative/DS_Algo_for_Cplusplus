#include<iostream>
#include<conio.h>
#include "arrayoperations.h"

using namespace std;


//for testing purpose
int main()
{
	int ArrayInput[10] = {1,2,2,2,3,3,4,5};
	Array a;
	
	int count=8;
	
	
	// showing initial array
	cout<<"\ninitial array - \n";
    a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    // after inserting 10 at position 5
    cout<<"after inserting 10 at the position 5 - \n";
    a.insertPosValue(ArrayInput , count , 10 , 5);
    a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    // after deleting value at position 5 
    cout<<"after deleting value at position 5 - \n";
    a.deletePosValue(ArrayInput , count , 5);
    a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    // after deleting the value = 4   
    cout<<"after deleting value = 4 by finding it , only deleted first occurence as deleteAll is set to false - \n";
    a.deleteValue(ArrayInput , count , 4 , false);
	a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    // after reversing the array
    cout<<"after reversing the array - \n";
    a.reverseArray(ArrayInput , count);
	a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    // after sreaching for value 5 after using normal search
    cout<<"searching value = 5 using normal search - \n";
    cout<<a.normalSearch(ArrayInput , count , 5);
    cout<<endl<<endl;
    
    // after searching for value 5 using binary search
    cout<<"searching value = 1 using binary search - \n";
    cout<<a.binarySearch(ArrayInput , count , 1);
    cout<<endl<<endl;
    

    // array after sorting it using bubble sort
    cout<<"sorting array using bubble sort - \n";
    a.bubbleSort(ArrayInput , count);
	a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;


    // new array for duplicate element function
    int ArrayInput2[10] = {1,2,2,2,3,3,4,5};
    count=8;

    // showing the new array
    cout<<"new array - \n";
    a.traverseArray(ArrayInput2 , count);
    cout<<endl<<endl;

    // array after removing duplicate elements
    cout<<"array after removing duplicate elements - \n";
    a.duplicateElementRemover_fromSortedArray(ArrayInput2 , count);
    a.traverseArray(ArrayInput2 , count);
    cout<<endl<<endl;

    // new array for duplicate element function 2
    int ArrayInput3[10] = {1,2,2,2,3,3,4,5};
    count=8;

    // showing the new array
    cout<<"new array - \n";
    a.traverseArray(ArrayInput3 , count);
    cout<<endl<<endl;

    // array after removing duplicate elements
    cout<<"array after removing duplicate elements using function 2 - \n";
    a.duplicateElementRemover_fromUnshortedArray1(ArrayInput3 , count);
    a.traverseArray(ArrayInput3 , count);
    cout<<endl<<endl;

    // new array for duplicate element function 2
    int ArrayInput4[10] = {1,2,2,2,3,3,4,5};
    count=8;

    // showing the new array
    cout<<"new array - \n";
    a.traverseArray(ArrayInput4 , count);
    cout<<endl<<endl;

    // array after removing duplicate elements
    cout<<"array after removing duplicate elements using function 3 - \n";
    a.duplicateElementRemover_fromUnshortedArray2(ArrayInput4 , count);
    a.traverseArray(ArrayInput4 , count);
    cout<<endl<<endl;


    // press enter to continue 
    getch();
	return 0;
}

