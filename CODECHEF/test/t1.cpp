#include<stdio.h>
#include<string.h>
int nearestprime(int ) ;
int prime( int ) ;

int main(){

int m ;
scanf("%d",&m) ;

while( m!= 0 )

{

int n ;
scanf("%d",&n) ;

char str[n+1] ;

scanf("%s",str) ;

int i ;

int l ;
l = strlen(str) ;

for(i= 0 ; i <l ; i++ )
{
int t ;
t = str[i] ;

if( prime(t) == 1 )
{
printf("%c",str[i]) ;
continue ;
}
else{

int a ;
a= nearestprime(t) ;
printf("%c",a) ;
}
}
printf("\n") ;

m-- ;
}

}

int prime( int x )
{
int i ;
if( x == 1 )
return 0 ;
for( i =2 ; i < x ; i++ )
{

if( x%i == 0 )
return 0 ;

}
return 1 ;
}

int nearestprime(int t)
{

int i = 1 ;
int a , b ;
if( t >= 97 && t<= 122 )
{

while(1){

if( t-i >= 97 )
a = t-i ;
if( t+i <= 122 )
b = t+i ;

if( prime(a) == 1 && prime(b) == 0 )
return a ;
else if ( prime(a) == 0 && prime(b) == 1 )
return b ;
else if( prime(a) == 1 && prime(b) == 1 )
{
if( a < b )
return a ;
else
return b ;
}
i++ ;

}
}

else if( t>= 65 && t<=90 )
{

while(1){

if( t-i >= 65)
a = t-i ;
if( t+i <= 90 )
b = t+i ;

if( prime(a) == 1 && prime(b) == 0 )
return a ;
else if ( prime(a) == 0 && prime(b) == 1 )
return b ;
else if( prime(a) == 1 && prime(b) == 1 )
{
if( a < b )
return a ;
else
return b ;
}
i++ ;

}

}
}
