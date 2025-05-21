#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;

public:
    Person(string name) {
        this->name = name;
    }

    ~Person() {
        cout << "name destroyed" << endl;
    }

    string getName() {
        return name;
    }

    void setName(string newName) {
        if (name.substr(0, 3) != newName.substr(0, 3)) {
            cout << "Family name change not allowed." << endl;
        } else {
            name = newName;
            cout << newName << "(으)로 변경 완료" << endl;
        }
    }
};

int main() {
    Person person("고길동");
    cout << "원래 이름: " << person.getName() << endl;
    person.setName("곡식");    
    person.setName("고구마");   
    person.setName("박길동");   
    cout << "최종 이름: " << person.getName() << endl;

    return 0;
}
