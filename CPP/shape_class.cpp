#include <iostream>
#include <string>

using namespace std;

class Shape{
    virtual void info() = 0;
};

class Circle : Shape{
    public:
        void info(){
            cout << "It's Circle"<< endl;
            return;
        }
};

class Rectanlge : Shape{
    public:
        void info(){
            cout << "It's Rectangle" << endl;
            return;
        }
};

int main(){
    Rectanlge r;
    Circle c;
    c.info();
    r.info();
    cout << __cplusplus<< endl;
    
    return 0;
}