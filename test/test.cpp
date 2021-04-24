#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "libgeometry/inputProcessing.h"
#include "libgeometry/infoOutput.h"
#include "libgeometry/Circle.h"
#include <string.h>
TEST_CASE("normal. check", "")
{
	string input = "cirCle";
	SECTION("normal.")
	{
		normalization(input);
		CHECK(input=="circle");
	}
	system("pause");	
}

