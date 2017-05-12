#include <iostream>
using namespace std;
const int MAX = 3;

class CString{
	char str[MAX + 1];
public:
	CString(char* s){
		if (s == nullptr){
			str[0] = '\0';
		}
		else{
			for (int i = 0; i < MAX; i++){
				str[i] = s[i];
				if (s[i] == '\0'){
					break;
				}
				str[MAX] = '\0';
			}
		}
	}
	void display(std::ostream& os){
		os << str;
	}
};
ostream& operator<<(ostream& os, CString cs){
	static int count = 0;
	os << count << " : ";
	cs.display(os);
	count++;
	return os;
}
void process(char* s){
	CString cs(s);
	cout << cs << "\n";
}
int main(int argc, char* argv[]){
	cout << "Command Line : ";
	cin >> *argv;
	cout << "Maximum number of characters stored : ";
	cin >> argc;
	for (int arg = 0; arg < argc; arg++){
		cout << arg << ": " << argv[arg] << endl;
	}
	if (argc == 1){
		cout << "Insufficient number of arguments (min 1)" << endl;
		return 1;
	}
	return 0;
}