#include <iostream>
//using namespace std;
//int main() {
	//std::cout << "Hello world" << std::endl;
//	return 0;
//}
int main(int agrc, char* argv[]) {
	
	for (int i = 0; i < agrc; i++) {
		

		std::cout << argv[i]<<' ';
	}
	std::cout << std::endl;
}