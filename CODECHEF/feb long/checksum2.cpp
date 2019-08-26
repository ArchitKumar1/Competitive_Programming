#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char a[20],b[20],sum[20],complement[20],carry='0';
	cin>>a>>b;
	int length=strlen(a);

	for(int i=length-1;i>=0;i--){
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

	for(int i=0;i<length;i++){
		if(sum[i]=='0')complement[i]='1';
		else complement[i]='0';
	}

	if(carry=='1')carry='0';
	else carry='1';

	cout<<"\nSum="<<carry<<sum;
	cout<<"\nChecksum="<<carry<<complement;


    return 0;
}
