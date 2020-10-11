#include <iostream>
using namespace std;

class abc{
    int x,y;
    public:
        void getData(int n1,int n2){
            x=n1;   y=n2;
        }
        void print(){
            cout<<"x is: "<<x<<endl<<"y is: "<<y<<endl;
        }
        friend void addData(abc);
};

//As it's a friend function we don't need to write like void abc:: addData...something like that..
//it can be declared without any scope operator
void addData(abc obj){
    cout<<"Addition is: "<< obj.x + obj.y<<endl;
}

int main() {
    abc obj1;
    obj1.getData(2,3);
    obj1.print();
    addData(obj1);  //don't need to write obj.addData(), as it is a friend function
    return 0;
}
