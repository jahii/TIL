#include <iostream>

using namespace std;

class Point{
    double x;
    double y;
    public:
        Point(double x, double y){
            this->x = x;
            this->y = y;
        }
        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
};

class Geometry{
    Point* point_array[100];
    int num_points;
    public:
        Geometry(){
            num_points = 0;
        }
        void AddPoint(const Point &point) {
            point_array[num_points ++] = new Point(point.getX(), point.getY());
        }

        // 모든 점들 간의 거리를 출력하는 함수 입니다.
        void PrintDistance();

        // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
        // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
        // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
        // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
        void PrintNumMeets();

};

int main(){
    Point p1(2.0, 5.0);
    Point p2(3.5, 9.0);
    Point p3(-1.0, -5.0);

    Geometry geo;
    geo.AddPoint(p1);
    geo.AddPoint(p2);
    geo.AddPoint(p3);
    geo.PrintDistance();
}

void Geometry::PrintDistance(){
    for(int i=0; i<num_points-1; i++){
        for(int j=i+1; j<num_points; j++){
            double dist = sqrt(pow(point_array[i]->getX()-point_array[j]->getX(),2)+pow(point_array[i]->getY()-point_array[j]->getY(),2));
            cout << "Point " << i << " to Point " << j << " Distance : " << dist << endl;
        }
    }
}


void Geometry::PrintNumMeets(){
    
}