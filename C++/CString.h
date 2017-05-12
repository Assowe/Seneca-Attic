#ifndef CSTRING_H__
#define CSTRING_H__
#include <iostream>
namespace w1 {

	const int LENGTH = 3;

	class CString {
	private:
		char str[LENGTH + 1];
	public:
		CString(char* s);
		void display(std::ostream& os);
	};
	std::ostream& operator<<(std::ostream& os, CString cs);
}
#endif