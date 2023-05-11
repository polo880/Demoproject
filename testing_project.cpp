#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//hi

struct Randomizer{
    int a;
    int b;
    int c;
    int cur;
    int rand();
};
int Randomizer::rand(){
    cur=(a*cur+b)%c;
    return cur;
}

class A
{
private:
    int i;
public:
    A(){cout<<"A";}
    A(const A&a){cout<<"a";}
    
};
void f(A a1,A a2,A a3){
    A a4;
}
class B
{
    private:
        A a;
    public:
        B(){cout<<"B\n";}
        ~B(){cout<<"b\n";}
};
class MyVector
{
private:
    int n;
    double* m;
public:
    MyVector();
    MyVector(int dim,double v[]);
    MyVector(const MyVector& v);
    ~MyVector();
    void print();
    bool isEqual(const MyVector& v);
};

MyVector::MyVector(){
    n=0;
    m=nullptr;
}
MyVector::MyVector(int dim,double v[]){
    n=dim;
    m=new double[dim];
    for(int i = 0; i<dim;i++)
        m[i]=v[i];
}
MyVector::~MyVector(){
    delete [] m;
}
MyVector::MyVector(const MyVector& v){
    n=v.n;
    m=new double[n];
    for(int i=0;i<n;i++)
        m[i]=v.m[i];
}
void MyVector::print(){
    cout<<"(";
    for(int i=0;i<n-1;i++)
        cout<<m[i]<<", ";
    cout<<m[n-1]<<")\n";
}
bool MyVector::isEqual(const MyVector& v){
    if(n!=v.n)
        return false;
    else{
        for(int i = 0 ; i<n;i++){
            if (m[i]!=v.m[i])
                return false;
        }
    }
    return true;
} 
int main(){
    double d1[5]={1,2,3,4,5};
    MyVector a1(5,d1);

    double d2[4]={1,2,3,4};
    MyVector a2(4,d2);
    MyVector a3(a1);

    cout<<(a1.isEqual(a2)?"Y":"N");
    cout<<"\n";
    cout<<(a1.isEqual(a3)?"Y":"N");
    cout<<"\n";
    cout<<"hihih";
    return 0;
}