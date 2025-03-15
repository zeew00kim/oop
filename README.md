## Object Oriented Programming (C++)
25년 1학기 객체지향언어(c++) 수업의 코드 로직 저장소
---
### delegate.c++
- `Point` 클래스의 맴버 `x, y`를 필드 값으로 초기화
- `Circl::Circle() : Circle(0, 0) {}` 위임 생성자 이용
---
### judgeIsSquare.c++
- `Rect` 클래스의 맴버 `width, height`를 필드 값으로 초기화
- `Rect()` 기본 생성자의 구현부에서 높이 및 너비를 입력
- `Rect(int w, int h)` 생성자는 main 함수에서 입력된 값을 사용
- `Rect(int length)` 생성자는 main 함수에서 입력된 너비 값만 사용
- `bool isSquare()` 함수는 3항 연산자를 통해 정사각형 유무를 판단
- `main()`함수에선 `isSquare()`함수 실행에 따른 결과를 출력
---
### useCstring.c++
`strcmp(), strlen(), strcpy()` 등의 함수를 사용할 수 있는<br>
`<cstring>` 또는 `<string.h>` 헤더
- `cin.getline(password, 11, '\n')` 공백을 포함한 문자열 입력
- `strcmp()` 함수를 사용하여 문자열의 값이 동일한지 확인
---
### useString.c++
`<string>`헤더 선언 시 `string` 자료형 사용이 가능하다.<br>
`string` 자료형은 문자열의 크기에 맞게 스스로 내부 버퍼를 조절
- 문자열 값을 입력 시 `getline(cin, brand)`와 같이 사용한다.
- `cstring`과는 다르게 문자열 값 비교 시 `==` 비교(관계) 연산자 사용
---