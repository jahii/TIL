#include <iostream>

using namespace std;

class Date {
    int year_;
    int month_;
    int day_;

    public :
        Date();
        void SetDate(int year, int month, int date);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);

        void ShowDate();
};

int main(){
    Date date;
    while(true){
        int command;
        cout << "1. 일수 더하기"<<endl;
        cout << "2. 월수 더하기"<<endl;
        cout << "3. 년수 더하기"<<endl;
        cout << "4. 계산된 날짜 보여주기"<<endl;
        cout << "0. 종료" << endl;
        cin >> command;
        int inc;
        switch(command){
            case 1:
                cout << "며칠 더하게? : ";
                cin >> inc;
                date.AddDay(inc);
                break;
            case 2:
                cout << "몇월 더하게? : ";
                cin >> inc;
                date.AddMonth(inc);
                break;
            case 3:
                cout << "몇년 더하게? : ";
                cin >> inc;
                date.AddYear(inc);
                break;
            case 4:
                date.ShowDate();
                break;
            case 0:
                return 0;
            default :
                cout << "존재하는 명령어가 없습니다."<<endl;
        }

        cout << endl;
    }
    return 0;

}
Date::Date(){
    int year, month, date;
    cout << "몇 년? : ";
    cin >> year;
    cout << "몇 월? : ";
    cin >> month;
    cout << "며칠? : ";
    cin >> date;
    this->SetDate(year,month,date);
}

void Date::SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = date;
}
void Date::AddDay(int inc){
    day_+=inc;
    while(true){
        if(month_==1 || month_==3 || month_==5 || month_==7 || month_==8 || month_==10 || month_==12){
            if(day_<=31) break;
            day_-=31;
        }else if(month_==4 || month_==6 || month_==9 || month_==11){
            if(day_<=30) break;
            day_-=30;
        }else{
            if((year_%4==0 && year_%100!=0)||year_%400 ==0){
                if(day_<=29) break;
                day_-=29;
            }else{
                if(day_<=28) break;
                day_-=28;
            }
        }
        this->AddMonth(1);
    }
}
void Date::AddMonth(int inc){
    month_+=inc;
    year_+=(month_-1)/12;
    month_ = (month_-1)%12+1;
}
void Date::AddYear(int inc){
    year_+=inc;
}
void Date::ShowDate(){
    cout << year_ << "년 " <<month_<<"월 " << day_ << "일 " << endl;
}
