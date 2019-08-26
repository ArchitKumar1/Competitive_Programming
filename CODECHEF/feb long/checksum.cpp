#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b,sum,complement;
    int i,len;

    cin>>a>>b;
	len = a.length();
	string carry("0");
	for(i=len-1;i>=0;i--)
	{
		if(a[i]=='0' && b[i]=='0' && carry=='0')     {sum[i]='0';carry='0';}
		else if(a[i]=='0' && b[i]=='0' && carry=='1'){sum[i]='1';carry='0';}
		else if(a[i]=='0' && b[i]=='1' && carry=='0'){sum[i]='1';carry='0';}
		else if(a[i]=='0' && b[i]=='1' && carry=='1'){sum[i]='0';carry='1';}
		else if(a[i]=='1' && b[i]=='0' && carry=='0'){sum[i]='1';carry='0';}
		else if(a[i]=='1' && b[i]=='0' && carry=='1'){sum[i]='0';carry='1';}
		else if(a[i]=='1' && b[i]=='1' && carry=='0'){sum[i]='0';carry='1';}
		else if(a[i]=='1' && b[i]=='1' && carry=='1'){sum[i]='1';carry='1';}
		else break;
	}


	for(i=0;i<len;i++){
		if(sum[i]=='0') complement[i]='1';
		else complement[i]='0';
	}
	if(carry=='1')carry='0';
	else carry='1';
	cout<<complement<<endl;
	return 0;
}
