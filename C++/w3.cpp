#pragma once
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

namespace w3{
	class Text{
		size_t count;
		string* lineTable;
		public:
		size_t size(){ return count; }
		Text() :count(0){

		}
		Text(const char* filename) :count(0){
			ifstream is(filename);
			if (is.is_open()){
				// count the number of lines in the file
				count = 0;
				string line;
				while (getline(is, line))
					count++;
				cout << "File '" << filename << "' contains " << count << " lines.\n";
				lineTable = new string[count];
				is.clear;
				is.seekg(0);
				for (size_t line = 0; line < count; line++)
					getline(is, lineTable[line]);
				/*size_t lines = (count < 10 ? count : 10);
for (size_t line = 0; line < lines; line++){
cout << line << ": -->" << lineTable[line] << "<--\n";
auto cr = lineTable[line].find('\n');
if (cr != string::npos){
lineTable[line].erase(cr);
}
}*/
				is.close;
			}
			else{
				cerr << "Cannot open file '" << filename << "'.\n";
				exit(3);
			}
		}
		~Text(){
			delete[] lineTable;
		}

		Text& operator= (const Text& rhs)// C++ assignment operator
		{
			if (this != &rhs){
				// if we have a lineTable, delete it
				delete[] lineTable;
				lineTable = nullptr;
				count = 0;
			}
			if (rhs.lineTable){
				count = rhs.count;
				lineTable = new string[count];
				for (size_t line = 0; line < count; line++){
					lineTable[line] = rhs.lineTable[line];
				}
			}
			return*this;
		}
		Text&& operator= (Text&& rhs){// C++ move assignment operator
			if (this != &rhs){
				delete[] lineTable;
				lineTable = nullptr;
				count = 0;
			}
			if (rhs.lineTable){
				//move pinter+count
				count = rhs.count;
				lineTable = rhs.lineTable;
				// turn rhs into zombie
				rhs.count = 0;
				rhs.lineTable = nullptr;
			}
			return std::move(*this);
		}
		Text(const Text& rhs){// copy constructor
			count = 0;
			lineTable = nullptr;
			*this = rhs;
		}
		Text(Text&& rhs){// move constructor
			count = 0;
			lineTable = nullptr;
			*this = move(rhs);
		}
	};// class Text
}// namespace w3