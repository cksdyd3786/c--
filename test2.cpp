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
            cout << newName << "(��)�� ���� �Ϸ�" << endl;
        }
    }
};

int main() {
    Person person("��浿");
    cout << "���� �̸�: " << person.getName() << endl;
    person.setName("���");    
    person.setName("����");   
    person.setName("�ڱ浿");   
    cout << "���� �̸�: " << person.getName() << endl;

    return 0;
}
