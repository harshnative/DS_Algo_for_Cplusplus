#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

class Matrix
{
	public :

        //documentaion is given along with the func defination
        
        //remember currently the matrix operations are on integer data type 
        //you can change the matrix operation data type by changing function datatype like vector <vector <int>> transposeMatrix() to vector <vector <double>> transposeMatrix() 
		
        
		// function to transpose a passed matrix
		// returns a new transposed matrix
		vector <vector <int>> transposeMatrix(vector <vector <int>> v)
		{
			vector <vector <int>> toReturn;

			for(int i=0 ; i<v.size() ; i++)
			{
				vector <int> temp;
				for(int j=0 ; j<v[i].size() ; j++)
				{
					temp.push_back(v[j][i]);
				}
				toReturn.push_back(temp);
				temp.clear();
			}

			return toReturn;
		}

		// function to increase the size of mat to desired row and col by inserting value provided
		// matrix is passed by reference here
		void increaseMatrix(vector <vector <int>> &v , int m , int n , int value = 0)
		{

			// increasing the rows
			int vSize = v.size();

			if(vSize < m)
			{
				int diffInRow = m - vSize;

				for(int i=0 ; i<diffInRow ; i++)
				{
					vector <int> temp;
					for(int j=0 ; j<n ; j++)
					{
						temp.push_back(value);
					}
					v.push_back(temp);
					temp.clear();
				}
			}
			
			
			// increasing the col
			int diffInCol = m - v[0].size();
			for(int i=0 ; i<v.size() ; i++)
			{
				int viSize = v[i].size();

				if(viSize < n)
				{
					int diffInCol = m - viSize;
					for(int j=0 ; j<diffInCol ; j++)
					{
						v[i].push_back(value);
					}
				}	
				}
		}

		// function to add two matrix 
		vector <vector <int>> add2Matrix(vector <vector <int>> v1 , vector <vector <int>> v2)
		{
			vector <vector <int>> toReturn;

			// calculating the bigger matrix row and col
			int m1 , n1 , m2 , n2 ;

			m1 = v1.size();
			n1 = v1[0].size();

			m2 = v2.size();
			n2 = v2[0].size();

			if(m1 != n2)
			{
				throw "cannot multiply this matrix";
			}

			int bigM , bigN;

			if(m1 < m2)
			{
				bigM = m2;
			}
			else
			{
				bigM = m1;
			}

			if(n1 < n2)
			{
				bigN = n2;
			}
			else
			{
				bigN = n1;
			}
			
			
			// making both matrix of same size
			Matrix m;
			m.increaseMatrix(v1 , bigM , bigN , 0);
			m.increaseMatrix(v2 , bigM , bigN , 0);


			// adding now 
			for(int i=0 ; i<bigM ; i++)
			{
				vector <int> temp;

				for(int j=0 ; j<bigN ; j++)
				{
					temp.push_back( (v1[i][j] + v2[i][j]) );
				}
				toReturn.push_back(temp);
				temp.clear();
			}

			return toReturn;
		}


		// function to multiply two matrix , numbers of rows in one mat should be equal to number of col in other mat 
		vector <vector <int>> multiply2Matrix(vector <vector <int>> v1 , vector <vector <int>> v2)
		{
			vector <vector <int>> toReturn;

			// calculating the bigger matrix row and col
			int m1 , n1 , m2 , n2 ;

			m1 = v1.size();
			n1 = v1[0].size();

			m2 = v2.size();
			n2 = v2[0].size();

			if(m1 != n2)
			{
				throw "cannot multiply this matrix";
			}

			int bigM , bigN;

			if(m1 < m2)
			{
				bigM = m2;
			}
			else
			{
				bigM = m1;
			}

			if(n1 < n2)
			{
				bigN = n2;
			}
			else
			{
				bigN = n1;
			}
			
			
			// making both matrix of same size
			Matrix m;
			m.increaseMatrix(v1 , bigM , bigN , 0);
			m.increaseMatrix(v2 , bigM , bigN , 0);


			// multiplying now 
			for(int i=0 ; i<bigM ; i++)
			{
				vector <int> temp;

				for(int j=0 ; j<bigN ; j++)
				{
					int sum = 0;
					for(int k=0 ; k<bigN ; k++)
					{
						sum = sum + (v1[i][k] * v2[k][j]);
					}
					temp.push_back(sum);
				}
				toReturn.push_back(temp);
				temp.clear();
			}

			return toReturn;
		}

		// returns a vector of 2d array inputted by user
		vector <vector <int>> input2dArray(int row , int coloumn)
		{
			vector<vector<int>> a;
			for(int i=0;i<row;i++)
			{	
				vector<int> temp;
				for(int j=0;j<coloumn;j++)
				{
					int b;
					cin>>b;
					temp.push_back(b);
				}
				a.push_back(temp);
				temp.clear();	
			}
			return a;
		}



		// prints the 2d vector array passed to it seperated by sep
		void printMatrix(vector <vector <int>> v , string sep = " ")
		{
			for(int i=0 ; i<v.size() ; i++)
			{
				for(int j=0 ; j<v[i].size() ; j++)
				{
					cout<<v[i][j]<<sep;
				}
				cout<<endl;
			}
		}


		int saddlePointOfMatrix(vector <vector <int>> v)
		{
			for(int i=0 ; i<v.size() ; i++)
			{
				for(int j=0 ; j<v[i].size() ; j++)
				{
					int point = v[i][j];

					bool colNo = true;
					bool rowNo = true;
					
					for(int k=0 ; k<v[i].size() ; k++)
					{
						if(point < v[i][k])
						{
							colNo = false;
						}
					}

					for(int l=0 ; l<v.size() ; l++)
					{
						if(point > v[l][j])
						{
							rowNo = false;
						}
					}

					if(rowNo && colNo)
					{
						return v[i][j];
					}
				}
			}
			throw "no SaddlePoint found";
		}

		void printMatrixInSpiralForm(vector <vector<int>> a , string sep = " " , bool clockWise = true)
		{ 

			int m , n;

			m = a.size();
			n = a[0].size();
		
			// t - starting row index  
			// b - ending row index  
			// l - starting column index  
			// r - ending column index  
			

			int i, k = 0, l = 0; 
  
			/* k - starting row index  
				m - ending row index  
				l - starting column index  
				n - ending column index  
			*/
  
			if(clockWise)
			{

				while (k < m && l < n) 
				{ 
					/* Print the first row from 
						the remaining rows */
					for (i = l; i < n; ++i) { 
						cout << a[k][i] <<sep; 
					} 
					k++; 
			
					/* Print the last column  
					from the remaining columns */
					for (i = k; i < m; ++i) { 
						cout << a[i][n - 1] <<sep; 
					} 
					n--; 
			
					/* Print the last row from  
							the remaining rows */
					if (k < m) { 
						for (i = n - 1; i >= l; --i) { 
							cout << a[m - 1][i] <<sep; 
						} 
						m--; 
					} 
			
					/* Print the first column from 
							the remaining columns */
					if (l < n) { 
						for (i = m - 1; i >= k; --i) { 
							cout << a[i][l] <<sep; 
						} 
						l++; 
					} 
				} 
			} 
			else
			{
				int cnt = 0; 
			
				int total = m * n; 
			
				while (k < m && l < n)  
				{ 
					if (cnt == total) 
						break; 
			
					// Print the first column  
					// from the remaining columns 
					for (i = k; i < m; ++i) 
					{ 
						cout << a[i][l] << " "; 
						cnt++; 
					} 
					l++; 
			
					if (cnt == total) 
						break; 
			
					// Print the last row from 
					// the remaining rows  
					for (i = l; i < n; ++i)  
					{ 
						cout << a[m - 1][i] << " "; 
						cnt++; 
					} 
					m--; 
			
					if (cnt == total) 
						break; 
			
					// Print the last column  
					// from the remaining columns  
					if (k < m)  
					{ 
						for (i = m - 1; i >= k; --i)  
						{ 
							cout << a[i][n - 1] << " "; 
							cnt++; 
						} 
						n--; 
					} 
			
					if (cnt == total) 
						break; 
			
					// Print the first row  
					// from the remaining rows  
					if (l < n)  
					{ 
						for (i = n - 1; i >= l; --i)  
						{ 
							cout << a[k][i] << " "; 
							cnt++; 
						} 
						k++; 
					} 
				} 
			}
			
		}

};


class SpecialMatrix
{
	public :


		// returns a 1d array from the diagonal type matrix to reduce space usage
		// i == j 
		vector <int> diagonalMatrix(vector <vector <int>> v)
		{
			vector<int> toReturn;

			for(int i=0 ; i<v.size() ; i++)
			{
				for(int j=0 ; j<v[i].size() ; j++)
				{
					if(i==j)
					{
						toReturn.push_back(v[i][j]);
					}
				}
			}

			return toReturn;
		}




		int doModeOfInteger(int integer)
		{
			if(integer < 0)
			{
				integer = integer * (-1);
			}
			
			return integer;
		}




		// returns a 1d array from the tridiagonal type matrix to reduce space usage
		// | i - j | > 1
		// mapping = 0 for row wise , 1 for coloumn vise , 2 for diagonal vise
		vector <int> triDiagonalMatrix(vector <vector <int>> v , int mapping = 0)
		{
			vector<int> toReturn;

			if(mapping == 0)
			{
				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(doModeOfInteger((i - j)) <= 1)
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}
			}
			else
			if(mapping == 1)
			{
				vector <vector <int>> transposed;
				Matrix matrixObj;

				transposed = matrixObj.transposeMatrix(v);

				for(int i=0 ; i<transposed.size() ; i++)
				{
					for(int j=0 ; j<transposed[i].size() ; j++)
					{
						if(doModeOfInteger((i - j)) <= 1)
						{
							toReturn.push_back(transposed[i][j]);
						}
					}
				}
			}

			else
			if(mapping == 2)
			{
				// below main diagonal
				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(i == (j+1))
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}

				// main diagonal
				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(i == j)
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}

				// above main diagonal

				for(int i=0 ; i<v.size() ; i++)
				{
					for(int j=0 ; j<v[i].size() ; j++)
					{
						if(i == (j-1))
						{
							toReturn.push_back(v[i][j]);
						}
					}
				}
			}

			else
			{
				throw "please pass a valid mapping to triDiagonal function";			
			}
			

			return toReturn;
		}

		// for triangular matrix
		// 0 for row mapping , 1 for col mapping 
		// set lowerTriangular = true for lower tiangular mat else make it false for upper trianglar mat
		vector <int> triangularMatrix(vector <vector <int>> v , int mapping = 0 , int lowerTriangular = false)
		{
			vector<int> toReturn;
			
			// for lower triangular matrix
			if(lowerTriangular)
			{
				if(mapping == 0)
				{
					for(int i=0 ; i<v.size() ; i++)
					{
						for(int j=0 ; j<v[i].size() ; j++)
						{
							if(i >= j)
							{
								toReturn.push_back(v[i][j]);
							}
						}
					}
				}
				else
				if(mapping == 1)
				{
					vector <vector <int>> transposed;
					Matrix matrixObj;

					transposed = matrixObj.transposeMatrix(v);

					for(int i=0 ; i<transposed.size() ; i++)
					{
						for(int j=0 ; j<transposed[i].size() ; j++)
						{
							if(i <= j)
							{
								toReturn.push_back(transposed[i][j]);
							}
						}
					}
				}
				else
				{
					throw "please pass a valid mapping to triDiagonal function";			
				}
			}

			else
			{
				if(mapping == 0)
				{
					for(int i=0 ; i<v.size() ; i++)
					{
						for(int j=0 ; j<v[i].size() ; j++)
						{
							if(i <= j)
							{
								toReturn.push_back(v[i][j]);
							}
						}
					}
				}
				else
				if(mapping == 1)
				{
					vector <vector <int>> transposed;
					Matrix matrixObj;

					transposed = matrixObj.transposeMatrix(v);

					for(int i=0 ; i<transposed.size() ; i++)
					{
						for(int j=0 ; j<transposed[i].size() ; j++)
						{
							if(i >= j)
							{
								toReturn.push_back(transposed[i][j]);
							}
						}
					}
				}
				else
				{
					throw "please pass a valid mapping to triDiagonal function";			
				}
			}
			
			return toReturn;
		}
};
#endif
