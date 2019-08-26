#include<bits/stdc++.h>
using namespace std;

#define ll long long


struct person{
    string name;
    int age;
};
void display(vector<struct person> &v1){

    for(int i=0;i<v1.size();i++){
        cout<<v1[i].name<<" "<<v1[i].age<<endl;
    }

}
int main() {
    int n;
    cin>>n;
    string name;
    int age;
    vector<struct person> v1(n);
    struct person p;
    for(int i=0;i<n;i++){
        cin>>p.name>>p.age;
        v1.push_back(p);
    }
    
    display(v1);




    return 0;
}

