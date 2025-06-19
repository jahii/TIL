#include <iostream>

using namespace std;

class Sample{
    int _a;
    int _b;

    public:
    Sample(){
        _a = 10;
        _b = 12;
    }

    Sample(int a, int b){
        this->_a = a;
        this->_b = b;
    };

    void showvalue(){
        cout << _a << " "<< _b << endl;
    }
};

int main(){
    Sample s1;
    Sample s2(1,3);
    // Sample s3(); // 이렇게 하면 리턴값이 Sample이고 인자가 없는 함수 s3를 정의하는 꼴임.
    
    s1.showvalue();
    s2.showvalue();
    // s3.showvalue();

}