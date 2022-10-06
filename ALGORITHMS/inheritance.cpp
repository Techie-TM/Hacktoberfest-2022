#include<iostream>
using namespace std;
class base{
    public:
    int i;

};
class derived:public base{
    int j;
    public:
    void get(){
        cout<<"Enter i and j ";
        cin>>i>>j;//wont work if i is private
    }
    void show(){
        cout<<"i is "<<i<<" j is "<<j<<endl;//wont work if i is private
    }
};
int main(){
    derived d;
    d.get();
    d.show();
    return 0;
}