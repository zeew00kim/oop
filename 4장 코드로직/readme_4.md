## 4장 실습 문제 코드 로직
### mallocCircle.cpp
- 사용자가 원하는 크기의 배열 길이를 입력
- 입력한 정수 값만큼 동적으로 `Circle 객체 배열` 생성
- `do~while` 반복을 통해 0 또는 음수 값 입력 방지
- 소멸자를 선언하여 객체의 소멸 횟수 확인 
---
### mallocCirc_getCnt.cpp
- 로직의 전반적인 매커니즘은 위의 `mallocCircle.cpp`와 동일
- 변수 `cnt`를 사용하여 원의 면적이 `100 <=`, `>= 200`일 경우 `cnt++`
- `cnt` 값을 `sql 쿼리문 출력 결과`처럼 출력
---
