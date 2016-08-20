#include<iostream>
#include<iomanip>
#include"MAT-Tricks ITC-PROJECT.h"
#include<Windows.h>
using namespace std;
void main()
{
	system("color f5"); 
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"    * * * * * * * * *               Calculator                * * * * * * * * *"<<endl;
    cout<<"     * * * * * * * *                                           * * * * * * * *"<<endl;
	cout<<"      * * * * * * *                                             * * * * * * *"<<endl;
	cout<<"       * * * * * *          *****   MAT Tricks   *****           * * * * * *"<<endl;
	cout<<"      * * * * * * *                                             * * * * * * *"<<endl;
	cout<<"     * * * * * * * *                                           * * * * * * * *"<<endl;
	cout<<"    * * * * * * * * *                                         * * * * * * * * *"<<endl;
	for(int i=0;i<4;i++)
	{
		Sleep(500);
    	system("color f5");
     	Sleep(500);
     	system("color f9");
	}
	int Mod;
	do{
		system("cls");
		cout<<"\n\n\n"<<endl;
		system("color f2");
		cout<<"                                 MAIN MENU"<<endl;
		cout<<"\n\n";
		cout<<"            Enter 1 to calculate Echlon form of a matrix           :\n"<<endl;
		cout<<"            Enter 2 to calculate Reduce Echlon form of a matrix    :\n"<<endl;
		cout<<"            Enter 3 to Apply Transformation on a Vector            :\n"<<endl;
		cout<<"            Enter 4 to calculate Multiplication of a matrices      :\n"<<endl;
		cout<<"            Enter 5 to calculate Arithmatic operation on matrices  :\n"<<endl;
		cout<<"            Enter 6 to anaylise the matrix                         :\n"<<endl;
		cout<<"\n\n\n                              "<<"Enter 0 for exit"<<endl<<endl;
		cin>>Mod;
		system("cls");
		if(Mod==1)                                  // Echolon form module
		{
			int r,c,TPivot;
	        cout<<"\n\n\t\tDefine Order of Matrix\n\n\tRows: ";
         	cin>>r;
         	cout<<"\tColumns: ";
        	cin>>c;
        	int **matrix=new int*[r];
         	for(int i=0;i<r;i++)
        	{
        		matrix[i]=new int[c];
        	}
        	cout<<"\n\n\tEnter matrix Row-wise\n\n\t\t";
        	for(int i=0;i<r;i++)
        	{
        		for(int j=0;j<c;j++)
	        	{
	         		cin>>matrix[i][j];
	        	}
				cout<<"\t\t";
        	}
        	TPivot=echolon(matrix,r,c);
        	cout<<"\n\n\tEcholon form is \n\n";
        	for(int i=0;i<r;i++)
         	{
				cout<<endl<<"\t\t";
        		for(int j=0;j<c;j++)
	        	{
	        		cout<<setw(7)<<matrix[i][j];
         		}
         	}
			cout<<"\n\n";
        	system("pause");
        	for(int i=0;i<r;i++)
        	{
        		delete[]matrix[i];
        	}
         	delete[]matrix;
        }
		else if(Mod==2)
		{
			int r,c,TPivot,unit;
	        cout<<"\n\n\t\tDefine Order of Matrix\n\n\tRows: ";
         	cin>>r;
         	cout<<"\tColumns: ";
        	cin>>c;
        	int **matrix=new int*[r];
         	for(int i=0;i<r;i++)
        	{
        		matrix[i]=new int[c];
        	}
        	cout<<"\n\n\tEnter matrix Row-wise\n\n";
        	for(int i=0;i<r;i++)
        	{
				cout<<"\t";
        		for(int j=0;j<c;j++)
	        	{
	         		cin>>matrix[i][j];
	        	}
        	}
        	TPivot=echolon(matrix,r,c);
        	cout<<"\n\n\tReduced Echolon form is \n\n\t";
			R_echo(matrix,r,c);
         	for(int i=0;i<r;i++)
         	{
		        for(int j=0;j<c;j++)
	        	{
	        		if(matrix[i][j]!=0)
		        	{
			        	unit=matrix[i][j];
			        	break;
	        		}
     	     	}
	            for(int s=0;s<c;s++)
         		{
	      		    if(matrix[i][s]%unit==0)
		         	{
	                 	cout<<setw(7)<<matrix[i][s]/unit;
	             	}
    	   	        else
	       	        {
	            		cout<<setw(7)<<matrix[i][s]<<"/"<<unit;
	             	}
              	}
	           	cout<<endl<<"\t";
	        }
			cout<<"\n\n";
        	system("pause");
        	for(int i=0;i<r;i++)
        	{
        		delete[]matrix[i];
        	}
           	delete[]matrix;
		}
		else if(Mod==3)         // transformation module
		{
			int r,c;
         	cout<<"\n\n\t\tEnter order of the Transformation\n\n";
        	cout<<"\trow: ";
        	cin>>r;
         	cout<<"\tColumns: ";
        	cin>>c;
         	int **matrix=new int*[r];
     	    for(int i=0;i<r;i++)
        	{
	        	matrix[i]=new int[c];
        	}
        	cout<<"\n\tEnter Transformation Matrix (row-wise)\n\n";
         	for(int i=0;i<r;i++)
    	    {
				cout<<"\t\t";
    	    	for(int j=0;j<c;j++)
	        	{
		        	cin>>matrix[i][j];
	        	}
         	}
        	cout<<"\n\tEnter a vector column wise\n";
        	int *vector=new int[c];
        	for(int i=0;i<c;i++)
     	    {
         		cout<<"\t";
	        	cin>>vector[i];
         	}
         	MAT_trans(matrix,vector,r,c);
            system("pause");
        	for(int j=0;j<r;j++)
            {
             	delete [] matrix[j];
            }
            delete [] matrix;
            delete [] vector;
    	}
    	else if(Mod==4)                               //multiplication module
		{
			int r1,c1,r2,c2;
         	cout<<"\n\n\t\tEnter order of the Matrices\n\n";
        	cout<<"\tOrder of 1st Matrix\n\n";
        	cout<<"\trow: ";
        	cin>>r1;
	        cout<<"\tColumns: ";
        	cin>>c1;
        	int **matrix1=new int*[r1];
         	for(int i=0;i<r1;i++)
	        {
	        	matrix1[i]=new int[c1];
        	}
        	cout<<"\n\t Enter 1st Matrix (row-wise)\n\n";
         	for(int i=0;i<r1;i++)
        	{
				cout<<"\t";
	        	for(int j=0;j<c1;j++)
	        	{
        			cin>>matrix1[i][j];
        		}
         	}
         	cout<<"\n\tOrder of 2nd Matrix\n";
         	cout<<"\trow: ";
          	cin>>r2;
         	cout<<"\tColumns: ";
    	    cin>>c2;
         	cout<<"\n\tEnter 2nd Matrix (row-wise)\n\n";
        	int **matrix2=new int*[r2];
        	for(int i=0;i<r2;i++)
         	{
         		matrix2[i]=new int[c2];
         	} 
        	for(int i=0;i<r2;i++)
         	{
				cout<<"\t";
         		for(int j=0;j<c2;j++)
        		{
	         		cin>>matrix2[i][j];
        		}
         	}
         	if(c1==r2)
			{
				MATmulti(matrix1,matrix2,r1,r2,c1,c2);
			}
			else
			{
				cout<<"\n\n\t\tMATH ERROR\n\t";
			}
			cout<<endl<<endl;
            system("pause");
        	for(int j=0;j<r1;j++)
            {
             	delete [] matrix1[j];
            }
            delete [] matrix1;
         	for(int j=0;j<r2;j++)
            {
                delete [] matrix2[j];
            }
            delete [] matrix2;
		}
		else if(Mod==5)                                      //Arithmatic module
		{
			int r,c,op;
         	cout<<"\n\n\t\tEnter order of matrices\n\n";
         	cout<<"\tRows: ";
        	cin>>r;
        	cout<<"\tColumns: ";
        	cin>>c;
         	int **matrix1=new int*[r];
        	for(int i=0;i<r;i++)
        	{
	        	matrix1[i]=new int [c];
         	}
        	cout<<"\n\tEnter 1st Matrix\n\n";
         	for(int i=0;i<r;i++)
         	{
				cout<<"\t\t";
        		for(int j=0;j<c;j++)
        		{
		        	cin>>matrix1[i][j];
         		}
        	}
        	int **matrix2=new int*[r];
         	for(int i=0;i<r;i++)
         	{
        		matrix2[i]=new int [c]; 
        	}
         	cout<<"\n\tEnter 2nd Matrix\n\n";
        	for(int i=0;i<r;i++)
        	{
				cout<<"\t\t";
	         	for(int j=0;j<c;j++)
         		{
		        	cin>>matrix2[i][j];
        		}
        	}
        	cout<<"\n\tPress 1 to Perform ADDITION\n";
        	cout<<"\n\tPress 2 to Perform SUBTRACTION\n\t";
         	cin>>op;
			cout<<"\n\tResult\n\n";
        	MAT_arithmatic(matrix1,matrix2,r,c,op);
        	if(op==1||op==2)
        	{ 
        		for(int i=0;i<r;i++)
	            {
					cout<<"\t";
	             	for(int j=0;j<c;j++) 
     		        {
	    	         	cout<<matrix1[i][j]<<" ";
	                }
	             	cout<<endl;
             	}
        	}
			cout<<"\n\n";
        	system("pause");
            for(int j=0;j<r;j++)
        	{
    	    	delete[]matrix1[j];
             	delete[]matrix2[j];
         	}
         	delete[]matrix1;
        	delete[]matrix2;
		}
		else if(Mod==6)                                  // Echolon form module
		{
			int r,c,TPivot;
	        cout<<"\n\t\tDefine Order of Matrix\n\n\tRows: ";
         	cin>>r;
         	cout<<"\tColumns: ";
        	cin>>c;
        	int **matrix=new int*[r];
         	for(int i=0;i<r;i++)
        	{
        		matrix[i]=new int[c];
        	}
        	cout<<"\n\n\tEnter matrix Row-wise\n";
        	for(int i=0;i<r;i++)
        	{
				cout<<"\t";
        		for(int j=0;j<c;j++)
	        	{
	         		cin>>matrix[i][j];
	        	}
        	}
        	TPivot=echolon(matrix,r,c);
        	cout<<"\n\tEcholon form is \n\n";
        	for(int i=0;i<r;i++)
         	{
				cout<<"\t";
        		for(int j=0;j<c;j++)
	        	{
	        		cout<<setw(7)<<matrix[i][j];
         		}
        		cout<<endl;
         	}
			cout<<"\n\n\tNo. Pivot Positions:  "<<TPivot;
			if(c==1)
			{
				cout<<"\n\n\tThe given matrix is a vector representing a line in (R"<<r<<")"<<endl<<endl;
			}
			else
			{
				                              //Checking mapping
				if(TPivot==r)
				{
					if(TPivot==c)
					{
						cout<<"\n\n\tTransformation is both ONE-to-ONE & ONTO";
					}
					else
					{
						cout<<"\n\n\tTransformation is ONTO";
					}
				}
				else
				{
					if(TPivot==c)
					{
						cout<<"\n\n\tTransformation is ONE-to-ONE";
					}
					else
					{
						cout<<"\n\n\tTransformation is neither ONE-to-ONE nor ONTO";
					}
				}
				                                //checking SPAN
				if(TPivot==r)
				{
					cout<<"\n\n\tColumns of the matrix Span R"<<r;
				}
				else
				{
					if(TPivot==1)
					{
						cout<<"\n\n\tColumns of the matrix Span a LINE IN R"<<r;
					}
					else
					{
						if(TPivot==2)
						{
							cout<<"\n\n\tColumns of the matrix Span PLANE IN R"<<r;
						}
						else
						{
							cout<<"\n\n\tColumns of the matrix Span SPACE in R"<<r;
						}
					}
				}
				                          //Checking Linear Dependency
				if(TPivot==c)
				{
					cout<<"\n\n\tThe columns of the matrix are LINEARLY INDEPENDENT\n\n";
				}
				else
				{
					cout<<"\n\n\tThe columns of the matrix are LINEARLY DEPENDENT\n\n";
				}
			}
        	system("pause");
        	for(int i=0;i<r;i++)
        	{
        		delete[]matrix[i];
        	}
         	delete[]matrix;
        }
	}while(Mod!=0);
}
