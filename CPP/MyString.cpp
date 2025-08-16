#include <iostream>
#include <cstring>

class MyString{
    char* string_content;
    int string_length;
    int memory_capacity;
    public:
    explicit MyString(int capacity);
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();
    MyString& assign(const MyString& str);
    MyString& assign(const char* str);
    void reserve(int size);
    char at(int i) const;
    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);
    MyString& erase(int loc, int num);
    int find(int find_from, char c) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, const MyString& str) const;
    int compare(const MyString& str) const;
    

    int length() const;
    int capacity() const;
    void print() const;
    void println() const;
};

MyString::MyString(int capacity){
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
    std::cout <<"Capacity : " << capacity << std::endl;
}

MyString::MyString(char c){
    string_content = new char[1];
    string_content[0] = c;
    string_length = 1;
    memory_capacity = string_length;
}
MyString::MyString(const char* str){
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    for(int i=0; i<string_length; i++){
        string_content[i] = str[i];
    }
}
MyString::MyString(const MyString& str) : string_length(str.string_length){
    string_content = new char[string_length];
    for(int i=0; i<string_length; i++){
        str.string_content[i] = str.string_content[i];
    }
    memory_capacity = string_length;
}
MyString::~MyString(){
    delete[] string_content;
}

MyString& MyString::assign(const MyString& str){
    if(str.string_length > memory_capacity){
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    string_length = str.string_length;
    for(int i=0; i<string_length; i++){
        string_content[i]=str.string_content[i];
    }
    return *this;
}

MyString& MyString::assign(const char* str){
    if(strlen(str) > memory_capacity){
        delete[] string_content;
        string_content = new char[strlen(str)];
        memory_capacity = strlen(str);
    }
    string_length = strlen(str);
    for(int i=0; i<string_length; i++){
        string_content[i] = str[i];
    }
    return *this;
}

void MyString::reserve(int size){
    if(size > memory_capacity){
        char *prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for(int i=0; i< string_length; i++){
            string_content[i] = prev_string_content[i];
        }
        delete[] prev_string_content;
    }
}

char MyString::at(int i) const {
    if(i >= string_length || i < 0){
        return 0;
    }else{
        return string_content[i];
    }
}
MyString& MyString::insert(int loc, const char* str){
    MyString tmp(str);
    return insert(loc, tmp);
}
MyString& MyString::insert(int loc, char c){
    MyString tmp(c);
    return insert(loc, tmp);

}
MyString& MyString::insert(int loc, const MyString& str){
    if(loc < 0 || loc > string_length) return *this;
    if(string_length+str.string_length > memory_capacity){
        memory_capacity = std::max( 2*memory_capacity, string_length+str.string_length);
        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
        for(int i=0; i<loc; i++){
            string_content[i] = prev_string_content[i];
        }
        for(int i=0; i<str.string_length; i++){
            string_content[i+loc] = str.string_content[i];
        }
        for(int i=loc; i<string_length; i++){
            string_content[i+str.string_length] = prev_string_content[i];
        }
        delete[] prev_string_content;
    }
    else{
        for(int i=string_length-1; i>=loc; i--){
            string_content[i+str.string_length] = string_content[i];
        }
        for(int i=0; i<str.string_length; i++){
            string_content[i+loc] = str.string_content[i];
        }
    }
    string_length += str.string_length;
    return *this;
}

MyString& MyString::erase(int loc, int num){
    if(num < 0 || loc>=string_length || loc < 0){
        std::cout << "Parameter inavailable!\n";
        return *this;
    }
    if(loc+num > string_length){
        std::cout << "At Index " << loc <<", you can only erase up to " << string_length-loc <<'\n';
        return *this;
    }
    for(int i=loc+num; i<string_length; i++){
        string_content[i-num] = string_content[i];
    }
    string_length -= num;
    return *this;
}

int MyString::find(int find_from, char c) const {
    MyString tmp(c);
    return find(find_from, tmp);
}

int MyString::find(int find_from, const char *str) const {
    MyString tmp(str);
    return find(find_from, tmp);
}
int MyString::find(int find_from, const MyString& str) const {
    if(str.string_length == 0) return -1;
    int j=0;
    for(int i=find_from; i<=string_length - str.string_length; i++){
        for(j=0; j<str.string_length; j++){
            if(string_content[i+j] != str.string_content[j]) break;
        }
        if(j==str.string_length) return i;
    }
    return -1;
}
//
int MyString::compare(const MyString& str) const{
    for(int i=0; i<std::min(string_length, str.string_length); i++){
        if(string_content[i]>str.string_content[i]){
            return 1;
        }else if(string_content[i]<str.string_content[i]){
            return -1;
        }
    }
    if(str.string_length < string_length){
        return 1;
    }else if(str.string_length > string_length){
        return -1;
    }else{
        return 0;
    }
}


int MyString::length() const {
    return string_length;
}

int MyString::capacity() const {
    return memory_capacity;
}

void MyString::print() const {
    for(int i=0; i<string_length; i++){
        std::cout<<string_content[i];
    }
}
void MyString::println() const {
    for(int i=0; i<string_length; i++){
        std::cout<<string_content[i];
    }
    std::cout<<std::endl;
}
int main() {
//   MyString str1("abcdef");
//   MyString str2("abcfe");

//   std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
    MyString s(3);
}

