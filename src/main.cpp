//------------------------------------------------------------
// Author:			Alejandro Dominguez
// Origin Date:		July 11, 2017
// Last Modified:	July 11, 2017
// Description:		Main program, all spwans from here.
//------------------------------------------------------------
#include "declarations.h"

using namespace std;

int main(int argc, char **argv){
	int line_num = 0;
	string line;

	cout << date_time() << " [FASTNet]: Where is the file located." << endl;
	getline(cin, line);

	ifstream file(line);
	ofstream logs("../doc/logs/fastnet.txt", ios::out | ios::app);

	cout << date_time() << " [FASTNet]: Program started running..." << endl;
	logs << date_time() << " [FASTNet]: Entered function." << endl;

	setup_algorithm();

	if(file.is_open()){
		logs << date_time() << " [FASTNet]: File " << line << " succesfully opened." << endl;

		while(getline(file, line)){
			line_num++;
			logs << date_time() << " [FASTNet]: Line: " << line << endl;
			logs << date_time() << " [FASTNet]: Line Number: " << line_num << endl;
			line_reader(line,line_num);
		}
	}
	else logs << date_time() << " [ERROR][FASTNet]: File was not opened, line 26." << endl;

	cout << date_time() << " [FASTNet]: What would you like to find." << endl;
	getline(cin, line);
	find_function(line);

	logs << date_time() << " [FASTNet]: Exiting function." << endl;
	cout << date_time() << " [FASTNet]: Closing program." << endl;

	file.close();
	logs.close();

	return 0;
}
