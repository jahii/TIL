#include <iostream>

// 복사 생성자에서 중요한 개념은 얕은 복사와 깊은 복사

class PhotonCanon{
    int hp, shield;
    double x, y;
    int damage;
    char *name;
    public:
        PhotonCanon(double _x, double _y);
        PhotonCanon(double _x, double _y, const char *_name);
        PhotonCanon(const PhotonCanon& pc);
        ~PhotonCanon();

        void show_status();
};

PhotonCanon::PhotonCanon(double _x, double _y){
    std::cout << "생성자 호출!" << std::endl;
    x = _x;
    y = _y;
    hp = 100;
    shield = 50;
    name = NULL;
}
PhotonCanon::PhotonCanon(double _x, double _y, const char *_name){
    std::cout << "이름 포함된 생성자 호출!" << std::endl;
    x = _x;
    y = _y;
    hp = 100;
    shield = 50;
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
}

PhotonCanon::PhotonCanon(const PhotonCanon &pc){
    std::cout << "복사 생성자 호출!" << std::endl;
    hp=pc.hp;
    shield = pc.shield;
    x = pc.x;
    y = pc.y;
    damage = pc.damage;
    // 깊은 복사를 설정해주지 않으면 default 복사 생성자가 얕은 복사를 하기 때문에 반드시 필요함.
    name = new char[strlen(pc.name)+1];
    strcpy(name, pc.name);
}

void PhotonCanon::show_status(){
    if(name) std::cout << "포톤캐논 이름 : "<<name<<std::endl;
    else std::cout << "이름이 없습니다." <<std::endl;
    std::cout << "HP : " << hp << std::endl;
    std::cout << "위치 : (" <<x<<","<<y<<")"<<std::endl;
}

PhotonCanon::~PhotonCanon(){
    if(name) delete[] name;
}

int main(){
    PhotonCanon pc1(3.0, 4.0, "포톤1");
    PhotonCanon pc2(pc1);
    PhotonCanon pc3 = pc2;
    PhotonCanon pc4(5,1);

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();
    pc4.show_status();

    return 0;
}

