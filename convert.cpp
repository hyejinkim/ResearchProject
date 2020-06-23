#include "convert.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

int convert(){
	string s, line, str, str2 ;
	fstream dataFile ;


	// From text to binary
	// Open and create text file
	ifstream iFile("gradebook1.txt") ;
	ofstream oFile("binary.txt") ;

	// If file not open output error message
	if(!iFile){
		cout << "ERROR opening file\n" ;
		return 0 ;
	}

	// Change to binary
	cout << "gradebook1.txt" << endl ;
	cout << "--------------\n" ;

	while(!iFile.eof()){
		getline(iFile, line) ;
		cout << line << endl ;

		for(size_t i=0; i < line.length(); i++){
			oFile << bitset<8>(line.c_str()[i]) << " " ;
		}
		oFile << endl ;
	}

	// Close files
	iFile.close() ;
	oFile.close() ;


	// From binary to text
	// Open and create text file
	ifstream fin("binary.txt") ;
	ofstream fout("gradebook2.txt");

	// Change back to text
	cout << "\ngradebook2.txt" << endl;
	cout << "--------------\n";

	while(!fin.eof()){
		getline(fin, s);
		string text = "";
		stringstream sstream(s);
		while(sstream.good()){
			bitset<8> bits;
			sstream >> bits;
			text += char(bits.to_ulong());
		}
		cout << text << endl;
		fout << text << endl;
	}

	// Close files
	fin.close();
	fout.close();


	// Compare two text files by content
	// Open two text files
    ifstream f1("gradebook1.txt");
    ifstream f2("gradebook2.txt");

	// If file not open output error message
    if(f1.fail() || f2.fail()){
        cout << "ERROR opening file\n";
        return 0 ;
    }

	// Read characters and store
    while(f1 && f2){
    	if(f1 && f2){
    		str += (char)f1.get();
    		str2 += (char)f2.get();
		}
	}

	// Check and if files are same output message
	if(str.compare(str2)==0){
		cout << "files are identical" << endl;
	}else{
		cout << "files are different" << endl;
	}

	// Close files
	f1.close();
	f2.close();
	return 0;
}
