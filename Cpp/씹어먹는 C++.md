## C++ 첫 프로그램 분석하기    (4/17)

```
#include <iostream>
int main()
{
	std::cout << "Hello, World!!" << std::end;
	return 0;
}
```

>[!note] 실행결과
>Hello, World!!
---

```
#include <iostream>
```
-  iostream 이라는 헤더파일을 포함하고있다
- C언어와 다른점은 .h 확장자명을 사용하지않는다
```
int main()
```
- int형 main함수를 정의한다.
```
std::cout << "Hello, World!!" << std::endl;
return 0;
```
- std::cout을 사용하여 Hello, world!!를 출력하고있다.
- std::endl을 사용하여 줄바꿈을 표시한다.
- :: 란 이름공간의 명칭으로 std::는  C++라이브러리에서 지원하는 함수,객체등이 정의된 이름공간(namespace)이다.

### 이름공간(namespace)

```
namespace header1
{
	int val;
	void bar();
}

namespace header2
{
	int val;
	void bar();
}
```
- 같은 이름의 변수가 생성될경우 컴파일에러가 난다.
- namespace는 같은 이름의 변수,함수,객체등 포함하는 범위를 지정하여 동일한 이름을 선언할수있게된다.
- header1, header2 의 val은 동시에 main함수에서 사용할수있는데 :: 지정자를 사용하여 불러올수있다.
ex)```
```
#include "header1"
#incldue "header2"
void main()
{
	header1::val = 1;
	header2::val = 2;
}
```

#### using namespace (namespace)

- 만약 namespace를 사용하기위해 :: 지정자를 생략하고싶다면 
using namespace (namespace) 를 선언하여 생략할수있다.
- 이 경우 다른 namespace 에 있는 함수는 동일하게 ::를 사용하면된다.

### 생각해보기

문제 아래 문장은 화면에 어떻게 출력될까요?
```
std::cout << "hi" << std::endl
		  << "my name is "
		  << "psi" << std::endl;
```

>[!note] 정리
>- std::cout은 출력함수이고 std::endl은 줄바꿈 함수이다.
>hi
>my name is psi

## C++, C언어의 공통 문법 구조

- 변수의 자료형, for, while, if, switch등의 조건문, 제어문등등은 동일하다.

## C++의 참조자(레퍼런스)

- c언어에선 함수의 주소를 가리킬땐 포인터를 사용해야만했다.
  하지만 C++에서는 참조자(레퍼런스)를 사용할수 있게되었다.

```
#include int main() 
{
	int a = 3;
	int& another_a = a;
	another_a = 5;
	
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
	return 0;
}
```

>[!note] 실행 결과
>a : 5
>another_a : 5;

- 위 예시에서 처음 선언했던 int& another_a = a; another_a = 5; 를 대입하여 실행한 결과 a = 5로 변경되었다. 
- DataType& 변수이름 = 변수;
- 참조자는 대입한 변수 이름의 또다른 이름이라고 선언한것과 마찬가지이므로 참조자를 이용해 어떠한작업을 수행하게되면 대입한 변수에 실행하는것과 같다.
- 참조자는 선언하기위해 규칙이 존재한다.
	1. 선언할때 반드시 누구를 참조할것인지 정해야한다.
		``` 
		int& another_a;        //error
		```
		
	 2. 참조자가 한번 지정되면 다른 값을 참조할수 없다.

- 참조자는 컴파일러 단계에서 메모리공간의 할당이 이루어지지않고 참조한 변수에 대입하기때문에 메모리상에 존재하지않을수도있다.
- 참조자가 메모리를 할당하는 예외가 존재한다.
 1. 함수의 인자로 전달받게된다면 
  const 를 사용하여 상수를 선언하게된다면 