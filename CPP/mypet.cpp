#include <iostream>
#include <string>

typedef struct _Animal {
    char name[30];
    int age;

    int health;
    int food;
    int clean;

} Animal;

void create_animal(Animal *animal){

    std::cout << "이름은? : ";
    std::cin >> animal->name;

    std::cout << "나이는 ? : ";
    std::cin >> animal->age;

    animal->health = 100;
    animal->food = 100;
    animal->clean = 100;
}
void play(Animal *animal) {

    animal->health += 10;
    animal->food -= 20;
    animal->clean -= 30;
}
void one_day_pass(Animal *animal) {
  // 하루가 지나면
    animal->health -= 10;
    animal->food -= 30;
    animal->clean -= 20;
}
void show_stat(Animal *animal) {
    std::cout << animal->name << "의 상태" << std::endl;
    std::cout << "체력    : " << animal->health << std::endl;
    std::cout << "배부름 : " << animal->food << std::endl;
    std::cout << "청결    : " << animal->clean << std::endl;
}

int main(){
    Animal *list[10];
    int animal_num = 0;
    int day_count = 0;
    while(++day_count){
        std::cout << day_count <<"번째 날" <<std::endl;
        std::cout << "1. 동물 추가하기" <<std::endl;
        std::cout << "2. 놀기" <<std::endl;
        std::cout << "3. 상태 보기" <<std::endl;

        int input;
        std::cin >> input;

        switch (input) {
            
            case 1:
                list[animal_num]= new Animal;
                create_animal(list[animal_num]);
                animal_num++;
                std::cout << "현재 동물의 수 : "<<animal_num<<std::endl;

                break;
            case 2:
                std::cout << "누구랑 놀게 ? : ";
                int play_with;
                std::cin >> play_with;
                if(play_with < animal_num) play(list[play_with]);
                break;
            case 3:
                if(animal_num==0){
                    std::cout << "아직 추가한 동물이 없습니다." << std::endl;
                    break;
                }
                std::cout << "누구꺼를 보게 ? : ";
                int who;
                std::cin >> who;
                show_stat(list[who]);
                break;
            default :
                std::cout << "1,2,3이 아니므로 다음날로 넘어갑니다."<< std::endl;
            
        }
        for(int i=0; i<animal_num; i++){
            one_day_pass(list[i]);
        }
    }
    for(int i=0; i<animal_num; i++){
        delete list[i];
    }
}

