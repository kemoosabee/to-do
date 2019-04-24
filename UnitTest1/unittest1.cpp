#include "stdafx.h"
#include "CppUnitTest.h"
#include"../todo/function.h"
#include<iostream>
#include<fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			std::string task1 = "unit testing ";
			char fname[] = ("unittest");
			createTask(fname, task1);
			ifstream fin(fname);
			get_task(fname, "ALL");
			
		}

	};
}