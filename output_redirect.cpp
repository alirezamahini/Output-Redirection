// output_redirect.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
using namespace std;
class RdrStdOut {
private:
        streambuf* prtStrbuf;
		streambuf* ptrStrBackup;
   
public:
        RdrStdOut(ofstream& file) : prtStrbuf(file.rdbuf()), ptrStrBackup(cout.rdbuf())
        {
            std::cout.rdbuf(prtStrbuf);
        }

        ~RdrStdOut() {
            cout.rdbuf(ptrStrBackup);
        }

};

int main(int argc, _TCHAR* argv[])
{
		cout<<"hello console\n";	
		ofstream file(".\\test.txt");
		RdrStdOut *r= new RdrStdOut(file);
		cout<<"Hello file\n";
		cout<<"bye file\n";
		delete r;
		cout<<"bye console\n";
		file.close();
		return 0;
}



