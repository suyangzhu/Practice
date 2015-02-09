#include <iostream>
#include <fstream>
using namespace std;
void Test() {
	ifstream fp("txt");
	string str;
	fp.seekg(2);
	while (getline(fp, str)) {
		std::cout << str <<std::endl;
	}
	ofstream fp2("rad"); 
		fp2 <<"Hello" <<std::endl;
	
	fp2.close();
}
int main(){
	Test();
}
