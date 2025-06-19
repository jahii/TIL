#include <iostream>

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);   // str 뒤에 s 를 붙인다.
  void copy_string(const string &s);  // str 에 s 를 복사한다.
  int strlen();                       // 문자열 길이 리턴
  void show_string();
};

string::string(char c, int n){
  str = new char[n+1];
  for(int i=0; i<n; i++){
    *(str+i) = c;
  }
  str[n]='\0';
  len =n;
}

string::string(const char *s){
  str = new char[std::strlen(s)+1];
  std::strcpy(str, s);
  len = std::strlen(s);
}

string::string(const string &s){
  this->copy_string(s);
}

void string::add_string(const string &s){
  char* tmp = new char[len+1];
  std::strcpy(tmp, this->str);
  str = new char[len+s.len+1];
  for(int i=0; i<len; i++){
    *(str+i)=tmp[i];
  }
  for(int i=0; i<s.len; i++){
    *(str+len+i)=s.str[i];
  }
  str[len+s.len]='\0';
  len += s.len;
}

void string::copy_string(const string &s){
  len = s.len;
  str = new char[len+1];
  std::strcpy(str, s.str);
}

int string::strlen(){
  return len;
}

void string::show_string(){
  std::cout<<str<< std::endl;
}

string::~string(){
  if(str) delete[] str;
  len = 0;
}

int main(){
  string s1("abc");
  string s2(s1);
  string s3 = s1;
  s1.add_string("def");
  s1.show_string();
  s2.show_string();
  s3.show_string();
}