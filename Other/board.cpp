// 
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	tuple <int,int,int,int> t;
//	
//	int a,b,c,d;
//	cin>>a>>b>>c>>d;
//	vector<tuple<int,int,int,int> > v1;
//	
//	v1.push_back(make_tuple(a,b,c,d));
//	
//	for(int i=0;i<4;i++)
//	{
//		cout<<get<i>v1[0]<<" "<<endl;
//	}
//	return 0;
//}

#include<iostream> 
#include<tuple> // for tuple 
using namespace std; 
int main() 
{ 
    // Declaring tuple 
    tuple <char, int, float> geek; 
  
    // Assigning values to tuple using make_tuple() 
    geek = make_tuple('a', 10, 15.5); 
  
    // Printing initial tuple values using get() 
    cout << "The initial values of tuple are : "; 
    cout << get<0>(geek) << " " << get<1>(geek); 
    cout << " " << get<2>(geek) << endl; 
  
    // Use of get() to change values of tuple 
    get<0>(geek) = 'b'; 
    get<2>(geek) =  20.5; 
  
     // Printing modified tuple values 
    cout << "The modified values of tuple are : "; 
    cout << get<0>(geek) << " " << get<1>(geek); 
    cout << " " << get<2>(geek) << endl; 
  
    return 0; 
} 
