## 객체지향언어 3장 실습 코드 정리
---
### local_global_obj.cpp
- Circle 클래스를 생성
- 기본 생성자와 정수 r을 매개변수로 받는 생성자를 사용
- getArea() 함수를 사용해 원의 면적을 계산 및 반환
- 전역 pizza, donut 객체를 생성
- main() 함수에서 지역 객체를 생성
- main() 함수에서 f() 함수 호출 후 지역 객체 생성
- ~Circle() 소멸자를 사용해 소멸 횟수를 출력
---
### useStruct.cpp
c++의 구조체는 클래스와 반대로 기본 접근지정자가 public입니다.<br>
이 코드 로직은 클래스 대신 구조체를 사용하여 원의 면적을 구한한다.

---
### delegate.cpp
기본 생성자 `Circle()`를 위임 생성자로 사용하고, `main()`함수에서<br>
매개변수를 입력 받는 `Circle(int r)` 생성자를 타겟 생성자로 사용하는 코드 로직

---
### memberInit.cpp
`Point` 클래스의 맴버 `x, y`값을 `main()`함수에서 입력받고, <br>
`setX(), setY()`함수를 통해 `private x, y`에 값을 대입한다. <br>
(위임 및 타겟 생성자 기능도 추가된 로직)

---
