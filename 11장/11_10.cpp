#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// 11_9 하위호환

class Book {
	string title;
	string press;
	string author;
public:
	Book(string title = "", string press = "", string author = "") {
		this->title = title;
		this->press = press;
		this->author = author;
	}
	friend ostream& operator << (ostream& print, Book book);
};

ostream& operator << (ostream& print, Book book) {
	print << "도서명 : " << book.title << endl
		<< "출판사 : " << book.press << endl
		<< "저자 : " << book.author;
	return print;
}

int main() {

	string title, press, author;

	cout << "제목, 출판사, 저자를 입력 : ";
	getline(cin, title);
	getline(cin, press);
	getline(cin, author);

	Book book(title, press, author);
	cout << setiosflags(ios::left) << book << endl;

	return 0;
}