#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
namespace w2{
	enum PASS_TYPE { STUDENT_PASS, ADULT_PASS, PASS_COUNT};
	class Station{
		string stationName;
		int passes[PASS_COUNT];
		public:
		Station(){}
		Station(istream& is)
		{
			string line;
			getline(is, line);
			cout << "Station(...) read -->" << line << "<--\n";
			stringstream ss(line);
			getline(ss, stationName, ';');
			ss >> passes[STUDENT_PASS];
			ss >> passes[ADULT_PASS];
			#if 0
			cout << "stationName,student,adult=" << stationName
				<< "," << passes[STUDENT_PASS]
				<< "," << passes[ADULT_PASS]
				<< "\n";
			#endif
		}
		void update(){
			// Spadina
			//  Student Passes sold : 5
			//  Adult Passes sold : 8
			int num;
			cout << stationName << "\n";

			cout << " Student Passes sold : ";
			cin >> num;
			passes[STUDENT_PASS] -= num;

			cout << " Adult Passes sold : ";
			cin >> num;
			passes[ADULT_PASS] -= num;
		}
		void restock(){
			int num;
			cout << stationName << "\n";

			cout << " Student Passes added : ";
			cin >> num;
			passes[STUDENT_PASS] += num;

			cout << " Adult Passes added : ";
			cin >> num;
			passes[ADULT_PASS] += num;
		}
		void report(){
			//Spadina               100   200
			//123456789-123456789-123456789-1
			cout << setw(19) << left << stationName;
			cout << setw(6) << right << passes[STUDENT_PASS];
			cout << setw(6) << right << passes[ADULT_PASS];
			cout << "\n";
		}
		void write(ostream& os){
			os << stationName          << ";" 
				<< passes[STUDENT_PASS] << " " 
				<< passes[ ADULT_PASS ] << "\n";
		}
	};
	class Stations{
		int stationCount;
		Station* stationTable;
		string dataFileName;
		public:
		~Stations(){
			ofstream os(dataFileName);
			if (os.is_open(), ios::trunc){
				os << stationCount << ";\n";
				for (int station = 0; station < stationCount; station++){
					stationTable[station].write(os);
				}
				os.close();
			}
			else{
				cerr << "Cannot create file '" << dataFileName << "'\n";
				exit(3);
			}
			delete[] stationTable;
		}
		Stations(const char* filename){
			dataFileName = filename;
			ifstream is(filename);
			if (is.is_open()){
				string line;
				getline(is, line);
				cout << "read ->>" << line << "<--\n"; 
				stringstream ss(line);
				ss >> stationCount;
				cout << "num= " << stationCount << endl;
				char c;
				ss >> c;
				if (c != ';'){
					cerr << "File '" << filename << "': epexted a ';', found " << c << " not our file, cannot continue" << "\n";
				}
				stationTable = new Station [stationCount];
				for (int station = 0; station < stationCount; station++){
					stationTable[station] = Station(is);
				}
				is.close();
			}
			else {
				cerr << "Cannot open file " << filename << "\n";
				exit(1);
			}
		}

		void update()
		{
			cout << "Passes Sold :\n";
			cout << "-------------\n";
			for (int station = 0; station < stationCount; station++){
				stationTable[station].update();
			}
		}

		void restock()
		{
			cout << "Passes Added :\n";
			cout << "--------------\n";
			for (int station = 0; station < stationCount; station++){
				stationTable[station].restock();
			}
		}
		void report()
		{
			cout << "Passese is Stock : Student Adult\n";
			cout << "--------------------------------\n";
			for (int station = 0; station < stationCount; station++){
				stationTable[station].report();
			}
		}
		void write(ostream& os){
			for (int station = 0; station < stationCount; station++){
				stationTable[station].write();
			}
		}
	};
}