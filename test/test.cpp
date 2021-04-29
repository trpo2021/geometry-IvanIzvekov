#define CATCH_CONFIG_MAIN
#include "thirdparty/catch.hpp"
#include "libgeometry/Circle.h"
#include "libgeometry/infoOutput.h"
#include "libgeometry/inputProcessing.h"
TEST_CASE("normal. check", "")
{
    SECTION("normal.")
    {
        CHECK(normalization("CIrCLE") == "circle");
        CHECK(normalization("ciRCLE") == "circle");
        CHECK(normalization("CIRclE") == "circle");
        CHECK(normalization("cIrCLE(1 2,3)") == "circle(1 2,3)");
        CHECK(normalization("CIRCLe") == "circle");
    }
}
TEST_CASE("check errors", "")
{
    vector<Circle> circles;
    SECTION("Errors")
    {
        CHECK(parser(circles, "") == false);
        CHECK(parser(circles, "ciraebtar (1 2,3)") == false);
        CHECK(parser(circles, "circle 1 2,3)") == false);
        CHECK(parser(circles, "circle ( 2,3)") == false);
        CHECK(parser(circles, "circle (1 ,3)") == false);
        CHECK(parser(circles, "circle (1 2,)") == false);
        CHECK(parser(circles, "circle (1 2,3") == false);
        CHECK(parser(circles, "circle (1 2 3)") == false);
        CHECK(parser(circles, "circle (1 2, 3)1") == false);
        CHECK(parser(circles, "circle ()") == false);
    }
}
TEST_CASE("parsernum.", "")
{
    double result;
    SECTION("")
    {
        numberParser("128", result);
        CHECK(result == 128.0);
        numberParser("128.2", result);
        CHECK(result == 128.2);
    }
    SECTION("")
    {
        numberParser(".0.2", result);
        CHECK(result == 0.0);
        numberParser("1s8.2", result);
        CHECK(result == 0.0);
    }
}
TEST_CASE("splitt.", "")
{
    SECTION("split")
    {
        CHECK(splitting("circle (1 2,3)")
              == vector<string>({"circle", "(", "1", "2", ",", "3", ")"}));
        CHECK(splitting("circle (1.2 2,3)")
              == vector<string>({"circle", "(", "1.2", "2", ",", "3", ")"}));
        CHECK(splitting("circle ((1 2,3)")
              == vector<string>({"circle", "(", "(", "1", "2", ",", "3", ")"}));
        CHECK(splitting("circle ((1.2 2,3)")
              == vector<string>(
                      {"circle", "(", "(", "1.2", "2", ",", "3", ")"}));
    }
}
TEST_CASE("info", "")
{
    SECTION("Area")
    {
        CHECK(circleArea(3) == Approx(28.274));
        CHECK(circleArea(1) == Approx(3.142));
        CHECK(circleArea(2) == Approx(12.566));
        CHECK(circleArea(1.5) == Approx(7.069));
    }
    SECTION("Perimetr")
    {
        CHECK(circlePerimetr(3) == Approx(18.850));
        CHECK(circlePerimetr(1) == Approx(6.283));
        CHECK(circlePerimetr(2) == Approx(12.566));
        CHECK(circlePerimetr(1.5) == Approx(9.425));
    }
}
TEST_CASE("intersection", "")
{
    SECTION("true")
    {
        CHECK(intersection(Circle(5, 5, 3), Circle(6, 6, 2)) == true);
        CHECK(intersection(Circle(1, 3, 9), Circle(2, 2, 2)) == true);
    }
    SECTION("false")
    {
        CHECK(intersection(Circle(2, 2, 2), Circle(9, 9, 2)) == false);
        CHECK(intersection(Circle(1, 1, 2), Circle(6, 6, 1)) == false);
    }
}
