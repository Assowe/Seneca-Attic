#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace w5{
	class Notifications{
		const size_t CAPACITY = 10;
		Message* = msgTable;
		int count;
	public:
		Notifications(): msgTable(nullptr), count(0){
			msgTable = new Message[CAPACITY];
		}
		Notifications(const Notifications& rhs){
			for (int i = 0; i < count; i++){ // deep copy
				msgTable[i] = rhs.msgTable[i];
			}
		}
		Notifications& operator=(const Notifications& rhs){
			if (this != &rhs){
				if (!msgTable){
					if (!msgTable) msgTable = new Message[CAPACITY], count = 0;

					for (int i = 0; i < count; i++){ // deep copy
						msgTable[i] = rhs.msgTable[i];
					}
				}
				return *this;
			}
		}
		//Notifications(Notifications&& rhs) - Move Constructor
		Notifications(Notifications&& rhs) : msgTable(rhs.msgTable), count(rhs.count) { // steal containts from rhs
			rhs.msgTable = nullptr, count = rhs.count;
		}
		// Notification&& operator=(Notification&&) - move assignment operator
		Notifications&& operator=(Notifications&&){
			if (this != &rhs){
				if (msgTable) delete[] msgTable;
				
				msgTable = rhs.msgTable;
				count = rhs.count;

				rhs.count = 0;
				rhs.msgTable = nullptr;
			}
			return move(*this);
		}
		~Notifications(){

		}
		void operator+=(const Message& msg){
			if (count < CAPACITY){
				msgTable[i].display(os);
			}
		}
		void display(std::ostream& os) const{
			for (int i = 0; i < count; i++){
				msgTable[i].display(os);
			}
		}
	};
}