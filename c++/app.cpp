#include "circle.h"

int main()
{
Circle circle1(5.2); /* 객체 변수명 옆에 괄호 */ cout << "반지름: " << circle1.getRadius() << endl; cout << "넓이: " << circle1.getArea() << endl;
cout << "둘레: " << circle1.getPerimeter() << endl << endl;
Circle circle2(circle1); /* 객체 변수명 옆에 괄호 */ cout << "반지름: " << circle2.getRadius() << endl; cout << "넓이: " << circle2.getArea() << endl;
cout << "둘레: " << circle2.getPerimeter() << endl << endl;
Circle circle3; /* 객체 변수명에 괄호 없음 (기본 생성자) */ cout << "반지름: " << circle3.getRadius() << endl; cout << "넓이: " << circle3.getArea() << endl;
cout << "둘레: " << circle3.getPerimeter() << endl << endl;
// 소멸자 호출 (스택 구조이므로 생성 순서 반대로 소멸됨)
return 0; }