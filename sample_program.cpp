#include<iostream>
#include "arrayoperations.h"

using namespace std;

//for testing purpose
int main()
{
	int ArrayInput[10] = {1,2,3,4,5,6,7,8};
	Array a;
	
	int count=8;
	
	
	
	cout<<"\ninitial array - \n";
    a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    cout<<"after inserting 10 at the position 5 - \n";
    a.insertPosValue(ArrayInput , count , 10 , 5);
    a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    cout<<"after deleting value at position 5 - \n";
    a.deletePosValue(ArrayInput , count , 5);
    a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    cout<<"after deleting value = 4 by finding it , only deleted first occurence as deleteAll is set to false - \n";
    a.deleteValue(ArrayInput , count , 4 , false);
	a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    cout<<"after reversing the array - \n";
    a.reverseArray(ArrayInput , count);
	a.traverseArray(ArrayInput , count);
    cout<<endl<<endl;
    
    cout<<"searching value = 5 using normal search - \n";
    cout<<a.normalSearch(ArrayInput , count , 5);
    cout<<endl<<endl;
    
    cout<<"searching value = 5 using binary search - \n";
    cout<<a.binarySearch(ArrayInput , count , 5);
    cout<<endl<<endl;
    
    cout<<"sorting array using bubble sort - \n";
    a.bubbleSort(ArrayInput , count);
	a.traverseArray(ArrayInput , count);
    cout<<endl;
    
	return 0;
}

