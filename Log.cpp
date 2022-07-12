#include <iostream>
#include "Number.h"
#include "Operation.h"
using namespace std;
//#define UnitTEST

#ifdef UnitTEST
#include "gtest/gtest.h"
#endif // Test

int main(int argc, char* argv[])
{
#ifdef UnitTEST
/*	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	*/
#else // UnitTEST
	int a = 3;
	int p = 11;
	int y = 1;

	Number A(1, a);
	cout << A.Divide(p, y);
	system("pause");
#endif
	
}
