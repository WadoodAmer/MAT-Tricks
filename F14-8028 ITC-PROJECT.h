#include<iostream>
#include<iomanip>
using namespace std;

//*********************************************   echlolon() ************************************************************

int echolon(int**matrix,int r,int c)
{
	bool check;
	int x,y=0,piv1,temp,entry,count=0;
    for(int a=0;a<r;a++)
	{
		//finding position and first non zero entry
    	do{
    		x=a;
    		do{
    			piv1=matrix[x][y];
    			if(piv1!=0)
				{
					count++;
				}
				x++;
    		}while(piv1==0 && x<r);
    		y++;
     	}while(piv1==0 && y<c);
     	x--;y--;
    	//rearranging rows for first non zero entry on top
    	for(int j=0;j<c;j++)
	    {
     		temp=matrix[x][j];
     		matrix[x][j]=matrix[a][j];
    		matrix[a][j]=temp;
    	}
     	//making all entries =0 below pivot position
    	for(int i=a+1;i<r;i++)
    	{
			check=false;
         	if(matrix[i][y]!=0)
     		{
	        	entry=matrix[i][y];
		        for(int j=0;j<c;j++)
	         	{
	    	   		matrix[i][j]=(matrix[i][j]*piv1-entry*matrix[a][j]);

             	}
				for(int b=0;b<c;b++)
				{
					if(matrix[i][b]%piv1!=0)
					{
						check=true;
					}
				}
				if(check)
				{
					for(int l=0;l<c;l++)
					{
						if(matrix[i][l]%piv1==0)
						{
							matrix[i][l]=matrix[i][l]*piv1;
						}
					}
				}
				else
				{
					for(int w=0;w<c;w++)
					{
						matrix[i][w]=matrix[i][w]/piv1;
					}
				}
    		}
    	}
	}
	return count;
}

//*********************************************   MATmulti ()************************************************************

void MATmulti(int** matrix1,int** matrix2,int r1,int r2,int c1,int c2)
{
	int **matrixR=new int*[r1];
	for(int i=0;i<r1;i++)
	{
		matrixR[i]=new int[c2];
	}


	for(int x=0;x<r1;x++)
	{
		for(int y=0;y<c2;y++)
		{
			matrixR[x][y]=0;
		}
	}

	for(int x=0;x<r1;x++)
	{
		for(int y=0;y<c2;y++)
		{
			for(int i=0;i<c1;i++)
			{
				matrixR[x][y]=matrixR[x][y]+matrix1[x][i]*matrix2[i][y];
			}
		}
	}
	cout<<"\tResult \n";
	for(int a=0;a<r1;a++)
	{
		cout<<endl<<"\t";
		for(int b=0;b<c2;b++)
		{
			cout<<setw(5)<<matrixR[a][b]<<" ";
		}
	}
	for(int j=0;j<r1;j++)
    {
         delete [] matrixR[j];
    }
    delete [] matrixR;
}

//*********************************************   MAT_arithmatic()************************************************************

int MAT_arithmatic(int**matrix1,int**matrix2,int r,int c,int op)
{
	if(op==1)
	{
		for(int i=0;i<r;i++)
	    {
	    	for(int j=0;j<c;j++)
	    	{
    			matrix1[i][j]=matrix1[i][j]+matrix2[i][j];
    		}
    	}
	}
	else if(op==2)
	{
		for(int i=0;i<r;i++)
    	{
     		for(int j=0;j<c;j++)
     		{
	    		matrix1[i][j]=matrix1[i][j]-matrix2[i][j];
    		}
    	}
	}
	else
	{
		cout<<"\n\n\tUnidentified Operation\n\n";
	}
	return op;
}

//***************************************************** MAT_trans() ***********************************************************
void MAT_trans(int** matrix,int*vector,int r,int c)
{
	int *result=new int[r];
    for(int x=0;x<r;x++)
	{
		result[x]=0;
	}

	for(int x=0;x<r;x++)
	{
		for(int i=0;i<c;i++)
		{
				result[x]=result[x]+matrix[x][i]*vector[i];
		}
	}
	cout<<"\n\tTransformed vector is\n";
	for(int a=0;a<r;a++)
	{
		cout<<endl<<"\t";
		cout<<setw(5)<<result[a];
	}
	cout<<"\n\n";
    delete [] result;
}

//***************************************************** R_echo()***********************************************************

void R_echo(int**matrix,int r,int c)
{
	bool check;
	int x,y,piv1,entry;
    for(int a=r-1;a>=0;a--)
	{
		x=a;//finding position and first non zero entry
    	do{
    		y=0;
    		do{
    			piv1=matrix[x][y];
				y++;
    		}while(piv1==0 && y<c);
    		x--;
     	}while(piv1==0 && x>0);
     	x++;y--;
		for(int i=x-1;i>=0;i--)
    	{
			check=false;
         	if(matrix[i][y]!=0)
     		{
	        	entry=matrix[i][y];
		        for(int j=0;j<c;j++)
	         	{
	    	   		matrix[i][j]=(matrix[i][j]*piv1-entry*matrix[a][j]);

             	}
				for(int b=0;b<c;b++)
				{
					if(matrix[i][b]%piv1!=0)
					{
						check=true;
					}
				}
				if(!check)
				{
					for(int w=0;w<c;w++)
					{
						matrix[i][w]=matrix[i][w]/piv1;
					}
				}
    		}
    	}
	}
}