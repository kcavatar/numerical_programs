#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

float func_val(float x)
{
    float value = exp(x*x)*log(2-x); //Please edit this
    return value;
}
int main()
{
    cout<<"GAUSS MULTI-POINT QUADRATURE FORMULA : Valid for max 3 points"<<endl;
    cout<<"--> To use this program,please enter your function in the function module"<<endl;
    cout<<"\nEnter the number of Gauss points required : \t";
    int n;
    cin>>n;
    cout<<"Enter the lower limit and upper limit of the integral: \t";
    float a, b;
    cin>>a>>b;
    float gaussP[n][2];
   
    //Second column represents Gauss points
    //First column represents their corresponding weights
    if(n==1)
    {
        gaussP[0][0] = 2; gaussP[0][1] = 0;
    }
    if(n==2)
    {
      gaussP[0][0] = gaussP[1][0] = 1;
      gaussP[0][1] = 1/sqrt(3); gaussP[1][1] = -1/sqrt(3);
    }
    if(n==3)
    {
      gaussP[0][0] = gaussP[1][0] = 5/9.0;
      gaussP[2][0] = 8/9.0;
      gaussP[0][1] = sqrt(3/5.0); gaussP[1][1] = -sqrt(3/5.0);
    }

    //Gauss integration
    float val = 0.0;
    for(int i=0;i<n;i++)
    {
        float x = a + (b-a)*0.5*(gaussP[i][1] + 1);
        val = val + 0.5*(b-a)*gaussP[i][0]*func_val(x);
    }
    
    //Display results
    cout<<"\n\n"<<setw(40)<<"\t\t****************************************"<<endl;
    cout<<setw(40)<<"The result is: "<<val<<endl;
    cout<<"\n"<<setw(40)<<"\t\t****************************************"<<endl;
    return true;
}
