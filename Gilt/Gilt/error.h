//********************************************************
//
//	Michael J Phillips
//	Copyright 2015
//	All rights reserved.
//
//********************************************************

#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>
#include <iostream>
#include "stdlib.h"

using namespace std;

inline void fatalError(const std::string& msg)
{
	cout << "ERROR: " << msg << endl;
	cout << "Press any key to exit" << endl;
	cin.get();

	//
	//	Windows-specific termination of program
	//
	exit(EXIT_FAILURE);
}

#endif