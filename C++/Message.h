

namespace w5{
	class Message{
		int count;
	public:
		Message(std::ifstream& in, char c){

		}

		bool empty(){
			return tweet.empty();
		}
		void display(std::ostream& os) const{
			os << " Message\n";
			os << " User : " << name << "\n";
			if (!reply.empty())
				os << " Reply " <<
		}
	};
}