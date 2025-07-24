#include<iostream>
using namespace std;
class students{
public:
    string name ;
    int rno ;
    float mark ;

    students(string name, int rno, float mark) {
        this->name = name;
        this->rno = rno;
        this->mark = mark;
    }
};
void change(students &second){
    second.name = "Aniket";
    second.rno = 4;
    second.mark = 90.0;
}
int main() {
    students student1("Vishal", 64, 91.5);
    cout << student1.name << endl;
    // change(student1);
    // cout << student1.name;
    students* ptr = &student1;
    // (*ptr).name = "Aniket";
    ptr->name = "Aniket";
    cout << student1.name << endl;
    
}
