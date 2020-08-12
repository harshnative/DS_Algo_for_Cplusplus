# Array Operations Header File -

A header file that as number of pre loaded array operations , just pass the value and see the results 


## How to import - 

Download the arrayoperations.h header file and paste it into your source code folder and then write this in your .cpp file

```C++
#include "arrayoperations.h"
```

## How to use the operation's - 

All the Array Operations methods are present in a class called Array , you first need to make a object of this class to access teh methods

```C++
Array obj;
```

#### Now you can access the method's by using dot operator - 

Example - 

```C++
obj.traverseArray(ArrayInput , count);
```


## Methods Currently available - 

let A be a array = int a[10];
let count be a array = int count = 10;

#### Note - elements index starting from 1 not 0 for simplicity , so position will always be actual index + 1 

<br />
<br />

1. int traverseArray(int inputArray[] , int ArrayCount , string seperator)

note - the default value if string seperator is " , "

```C++
obj.traverseArray(A , count , " ")  

// here the last argument is string sperator
```

<br />
<br />

2. void insertPosValue(int inputArray[] , int &ArrayCount , int value , int position);

note - here the count is passed as reference as it changes after insertion process

```C++
obj.insertPosValue(A , count , 5 , 4)  

// here the 5 will be inserted at the position 4 in array
```

<br />
<br />

3. void deletePosValue(int inputArray[] , int &ArrayCount , int position);

note - here the count is passed as reference as it changes after insertion process

```C++
obj.deletePosValue(A , count , 5 )  

// here the element at the 5th position will be deleted
```

<br />
<br />

4. void deleteValue(int inputArray[] , int &ArrayCount , int value , bool deleteAll);

note - Default value of deleteAll is set to true , that is this method will delete all the elements in the array that matches with value passed
 
note - if deleteAll is set to false , then method will only delete the first occurance of the element

```C++
obj.deleteValue(A , count , 5)  

// here the elements that are equal to 5
```

<br />
<br />

5. void reverseArray(int arr[], int count); 

```C++
obj.reverseArray(A , count)  

// after this the elements of the array will be reversed
```

<br />
<br />

6. int normalSearch(int inputArray[] , int ArrayCount , int value);

note - this returns the index of the first found if the element

note - return 0 if element is not found
 
```C++
obj.normalSearch(A , count , 5)  

// will return the index of element which is equal to five
```

<br />
<br />

7. int binarySearch(int inputArray[] , int ArrayCount , int value);

note - this returns the index of the element but with advance binary search operation

note - return 0 if element is not found
  
```C++
obj.binarySearch(A , count , 5)  

// will return the index of element which is equal to five
```

<br />
<br />

8. void bubbleSort(int inputArray[] , int ArrayCount);

```C++
obj.bubbleSort(A , count , 5)  

// will sort the array in asending order with the help of bubble sort algorithm
```

<br />
<br />

9.  void duplicateElementRemover_fromSortedArray(int inputArray[] , int &arrayCount); 

For removing duplicate elements from the array

note - array must be pre sorted for this to work
  
```C++
obj.duplicateElementRemover_fromSortedArray(A , count)  

// will remove the duplicate elements from the sorted array
```

<br />
<br />

10.  void duplicateElementRemover_fromUnshortedArray1(int inputArray[] , int &arrayCount); 

For removing duplicate elements from the array from unsorted array

note - this function uses less space while operating but may require more time 
  
```C++
obj.duplicateElementRemover_fromUnshortedArray1(A , count)  

// will remove the duplicate elements from the unsorted array without using more space
```

<br />
<br />

11.  void duplicateElementRemover_fromUnshortedArray2(int inputArray[] , int &arrayCount); 

For removing duplicate elements from the array from unsorted array

note - this function uses less time while operating but may require more space 
  
```C++
obj.duplicateElementRemover_fromUnshortedArray2(A , count)  

// will remove the duplicate elements from the unsorted array using less time
```

<br />
<br />


12.  bool elementPresentInArray(int inputArray[] , int arrayCount , int element);


For checking if a value is present in array or not

note - returns a bool value true or false 
  
```C++
obj.elementPresentInArray(A , count , 5)  

// return true if 5 is present in array else return false
```

<br />
<br />



### Sample Program - 

```C++
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

```

### Ouput of above program - 

```
initial array -
1 , 2 , 2 , 2 , 3 , 3 , 4 , 5

after inserting 10 at the position 5 - 
1 , 2 , 2 , 2 , 10 , 3 , 3 , 4 , 5     

after deleting value at position 5 -
1 , 2 , 2 , 2 , 3 , 3 , 4 , 5

after deleting value = 4 by finding it , only deleted first occurence as deleteAll is set to false -
1 , 2 , 2 , 2 , 3 , 3 , 5

after reversing the array -
5 , 3 , 3 , 2 , 2 , 2 , 1

searching value = 5 using normal search -
1

searching value = 1 using binary search - 
7

sorting array using bubble sort -
1 , 2 , 2 , 2 , 3 , 3 , 5

new array -
1 , 2 , 2 , 2 , 3 , 3 , 4 , 5

array after removing duplicate elements -
1 , 2 , 3 , 4 , 5

new array -
1 , 2 , 2 , 2 , 3 , 3 , 4 , 5

array after removing duplicate elements using function 2 -
1 , 2 , 3 , 4 , 5

new array -
1 , 2 , 2 , 2 , 3 , 3 , 4 , 5

array after removing duplicate elements using function 3 -
1 , 2 , 3 , 4 , 5
```


# Licensing - 
This code is licensed under GPL 3.0 , which means you can use this code in any of your project and also modify it if needed.

But it is recommended that you contribute some of the extra features to the community as well (^_^)
