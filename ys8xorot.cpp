#include <fstream>
#include <iostream>
#include <string>

int main (int argc, char* argv[]) 
{
	if (argc < 2) {
		std::cout << "Please provide file name!" << std::endl;
		return -1;
	}
	
	std::string fname_in(argv[1]);
	std::string fname_out = fname_in + ".decrypt";
	
	std::ifstream f_in (fname_in, std::fstream::binary);
	if (f_in) {
		std::cout << "Reading from " << fname_in << std::endl;
		
		std::ofstream f_out (fname_out, std::fstream::trunc | std::fstream::binary);

		unsigned char b;
		while (f_in.read(reinterpret_cast<char*>(&b), 1)) {		
			b = 0x0F ^ (b << 4 | b >> 4);
			f_out.put(b);
		}

		std::cout << "Write to " << fname_out << std::endl;
	} else {
		std::cout << "File not found " << fname_in << std::endl;
		return 1;
	}
	return 0;
}