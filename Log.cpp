#include <iostream>
#include "Number.h"
#include "Operation.h"
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
	Number a(15, 2);
	Number b(3, 2);
	a < b;
#endif
	
}
