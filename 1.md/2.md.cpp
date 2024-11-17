#include <iostream>	
#include <ctime>    
using namespace std;
#define N 2
//N 为维数，可以改成3,4,5,6...多少维度都行
	
 
double getA(double arcs[N][N],int n)
{	
	if(n==1)	
	{	
		return arcs[0][0];	
	}	
	double ans = 0;	
	double temp[N][N]={0.0};	
	int i,j,k;	
	for(i=0;i<n;i++)	
	{	
		for(j=0;j<n-1;j++)	
		{	
			for(k=0;k<n-1;k++)	
			{	
				temp[j][k] = arcs[j+1][(k	>=i)?k+1:k];
			}	
		}	
		double t = getA(temp,n-1);
		if(i%2==0)	
		{	
			ans += arcs[0][i]*t;	
		}	
		else	
		{	
			ans -=  arcs[0][i]*t;	
		}	
	}	
	return ans;	
}	
	
 
void  getAStart(double arcs[N][N],int n,double ans[N][N])
{	
	if(n==1)	
	{	
		ans[0][0] = 1;	
		return;	
	}	
	int i,j,k,t;
	double temp[N][N];	
	for(i=0;i<n;i++)	
	{	
		for(j=0;j<n;j++)	
		{	
			for(k=0;k<n-1;k++)	
			{	
				for(t=0;t<n-1;t++)	
				{	
					temp[k][t] = arcs[k>=	i?k+1:k][t>=j?t+1:t];
				}	
			}	
				
				
			ans[j][i]  =  getA(temp,n-1);
			if((i+j)%2 == 1)	
			{	
				ans[j][i] = - ans[j][i];	
			}	
		}	
	}	
}	
	
 
bool GetMatrixInverse(double src[N][N],int n,double des[N][N])
{	
	double flag=getA(src,n);	
	double t[N][N];	
	if(0==flag)	
	{	
		cout<< "原矩阵行列式为0，无法求逆。请重新运行" <<endl;
		return false;
	}	
	else	
	{	
		getAStart(src,n,t);	
		for(int i=0;i<n;i++)	
		{	
			for(int j=0;j<n;j++)	
			{	
				des[i][j]=t[i][j]/flag;	
			}	
			
		}	
	}	
		
	return true;	
}	
	
int main()	
{	
	bool flag;
	int row =N;	
	int col=N;	
	double matrix_before[N][N]{};//{1,2,3"	",4,5,6,7,8,9};
	
 
	srand((unsigned)time(0));	
	for(int i=0; i<N ;i++)	
	{	
		for(int j=0; j<N;j++)	
		{	
			matrix_before[i][j]=rand()%100 *0.01;
		}	
	}	
	if(N==2){
		matrix_before[0][0]=	1.80138	;
		matrix_before[0][1]=	-1	;
		matrix_before[1][0]=	3.80138	;
		matrix_before[1][1]=	2.4897	;      
	}
		
		
	cout<<"原矩阵："<<endl;
		
	for(int i=0; i<N ;i++)	
	{	
		for(int j=0; j<N;j++)	
		{	
			//cout << matrix_before[i][j]	"<<"" "";"
			cout << *(*(matrix_before+i)+	j)<<" ";
		}	
		cout<<endl;	
	}	
	cout<<endl;	
		
	double matrix_after[N][N]{};	
	flag=GetMatrixInverse(matrix_before,N,matrix_after);
	if(false==flag)	
		return 0;	
		
		
	cout<<"逆矩阵："<<endl;
		
	for(int i=0; i<row ;i++)	
	{	
		for(int j=0; j<col;j++)	
		{	
			cout <<matrix_after[i][j] <<"	";
			//cout << *(*(matrix_after+i)	"+j)<<"" "";"
		}	
		cout<<endl;	
	}	
	cout<<endl;	
	
	GetMatrixInverse(matrix_after,N,matrix_before);
		
	cout<<"反算的原矩阵："<<endl;//
		
	for(int i=0; i<N ;i++)	
	{	
		for(int j=0; j<N;j++)	
			{	
				//cout << matrix_before[i][j]	"<<" "";
				cout << *(*(matrix_before+i)+j)<<" ";
			}	
		cout<<endl;	
	}	
		
		
	return 0;	
}	