#ifndef ARRAYOPERATIONS_H
#define ARRAYOPERATIONS_H

#include<iostream>

using namespace std;

class Array
{
	public :

        //documentaion is given along with the func defination
        
        //remember currently the array operations are on integer array
        //you can change the array operation data type by changing function datatype like int traverseArray to double traverse array and also function parameters like int inputArray[] to double inputArray[]
		
        //declaring function prototypes
		int traverseArray(int inputArray[] , int ArrayCount , string seperator)	;
		void insertPosValue(int inputArray[] , int &ArrayCount , int value , int position);
		void deletePosValue(int inputArray[] , int &ArrayCount , int position);
		void deleteValue(int inputArray[] , int &ArrayCount , int value , bool deleteAll);
		void reverseArray(int arr[], int count); 
		int normalSearch(int inputArray[] , int ArrayCount , int value);
		int binarySearch(int inputArray[] , int ArrayCount , int value);
		void bubbleSort(int inputArray[] , int ArrayCount);
		void duplicateElementRemover_fromSortedArray(int inputArray[] , int &arrayCount); 
		void duplicateElementRemover_fromUnshortedArray1(int inputArray[] , int &arrayCount);
		void duplicateElementRemover_fromUnshortedArray2(int inputArray[] , int &arrayCount);
		bool elementPresentInArray(int inputArray[] , int arrayCount , int element);

};


//this function shows all the Array elements seperated by the seperator
int Array::traverseArray(int inputArray[] , int ArrayCount , string seperator = " , ")	
{
	for(int i=0 ; i<ArrayCount; i++)
	{
		cout<<inputArray[i];
		if((i+1) < ArrayCount)
		{
			cout<<seperator;
		}
	}
}	




void Array::insertPosValue(int inputArray[] , int &ArrayCount , int value , int position)
//this function takes a value , position and insert it in the Array passed on
//ArrayCount is passed here as reference as it changes after insertion is been made 		
{
	for(int i=ArrayCount-1 ; i>=position-1 ; i--)
	{
		inputArray[i+1] = inputArray[i];	
	}
	inputArray[position-1] = value;	
	ArrayCount++;
}




void Array::deletePosValue(int inputArray[] , int &ArrayCount , int position)
//this func take a position and deletes the value of that position in the Array passed on
//shows ERROR if the position is out of range 
{
	if(position > ArrayCount+1)
	{
		system("cls");
		cout<<"deletion not possible - position not found\n\n";
		system("pause");
		system("cls");
	}
	else
	{
		for(int i=position-1 ; i<ArrayCount-1 ; i++)
		{
			inputArray[i] = inputArray[i+1];
		}
		ArrayCount--;
	}
}





void Array::deleteValue(int inputArray[] , int &ArrayCount , int value , bool deleteAll = true)
//this func takes value as input and deletes them from the whole Array if the deleteAll value is true
{
	for(int i=0 ; i<ArrayCount ; i++)
	{
		if(inputArray[i]==value)
		{
			deletePosValue(inputArray , ArrayCount , i+1);
			i--;
            if(deleteAll == false)
            {
            	break;
			}
            
		}
	}
}



//func to reverse a Array 
void Array::reverseArray(int arr[], int count) 
{ 
	int start = 0;
	int end = count-1;
    while (start < end) 
    {
        int temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
}



int Array::normalSearch(int inputArray[] , int ArrayCount , int value)
{
//this is a normal search of a value in the Array and returns it position
//returns 0 if the element is not found
	for(int i=0 ; i<ArrayCount ; i++)
	{
		if(inputArray[i] == value)
		{
			return i+1;
		}
	}
	return 0;
}



int Array::binarySearch(int inputArray[] , int ArrayCount , int value)
//this is the binary search method , returns element position
//this method requires Array to be pre sorted 
//returns 0 if the element is not found
{
	int high , mid , low;
			
	low = 0;
	high = ArrayCount - 1;

	if(inputArray[0] == value)
	{
		return 1;
	}
	else
	if(inputArray[ArrayCount-1] == value)
	{
		return ArrayCount;
	}
	else
	{
			while(low<=high)
	{
		mid = (low + high)/2;
		if(value == inputArray[mid])
		{
			return mid+1;
		}
		else
		if(value < inputArray[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	}
	
	


	return 0;
}
		




void Array::bubbleSort(int inputArray[] , int ArrayCount)
//this function uses optimised bubble sort algorithm to sort the array
{
	bool swapStatus;
	for(int i=0;i<ArrayCount-1;i++)
	{
		swapStatus = false;
		for(int j=0 ; j<ArrayCount-i-1 ; j++)
		{
			if(inputArray[j] > inputArray[j+1])
			{
			int temp = 0;
			temp = inputArray[j];
			inputArray[j] = inputArray[j+1];
			inputArray[j+1] = temp;
			swapStatus = true;
			}
		}
		if(swapStatus == false)
		{
			break;
		}
	}
}


// function for removing duplicate elements from the sorted array
void Array::duplicateElementRemover_fromSortedArray(int inputArray[] , int &arrayCount)
{
	for(int i=0 ; i<arrayCount ; i++)
	{
		if((inputArray[i] == inputArray[i+1]) && (i+1 < arrayCount))
		{
			deletePosValue(inputArray , arrayCount , i+2);
			i--;
		}
	}
}

// function for removing duplicate elements from the unsorted array without using much extra space
void Array::duplicateElementRemover_fromUnshortedArray1(int inputArray[] , int &arrayCount)
{
	int temp = 0;

	for(int i=0 ; i<arrayCount ; i++)
	{
		temp = inputArray[i];
		deleteValue(inputArray , arrayCount , inputArray[i]);
		insertPosValue(inputArray , arrayCount , temp , i+1);
	}
}

bool Array::elementPresentInArray(int inputArray[] , int arrayCount , int element)
{
	for(int i=0 ; i<arrayCount ; i++)
	{
		if(element == inputArray[i])
		{
			return true;
		}
	}
	return false;
}

// function for removing duplicate elements from the unsorted array with using extra space but less time complexity
void Array::duplicateElementRemover_fromUnshortedArray2(int inputArray[] , int &arrayCount)
{
	int *p = new int[arrayCount];
	int tempArrayCount = 0;

	for(int i=0 ; i<arrayCount ; i++)
	{
		if(elementPresentInArray(p , tempArrayCount , inputArray[i]) == false)
		{
			insertPosValue(p , tempArrayCount , inputArray[i] , tempArrayCount+1);
		}
	}

	for(int i=0 ; i<tempArrayCount ; i++)
	{
		inputArray[i] = p[i];
	}

	arrayCount = tempArrayCount;

}

#endif
