#include "pch.h"
#include "../Rect_intersection/Point.h" 
#include "../Rect_intersection/IntersectionProccesing.h"
#include "../Rect_intersection/RectIntersection.h"
#include "../Rect_intersection/Rectangle.h"
#include <iostream>
#include <fstream>
#include <Utils.h>
using json = nlohmann::json;
json jsonInput, jsonOutput;
string  fileNameInput = "test.json";
string  fileNameOutput = "testResult.json";

namespace RectIntersection
{

    vector<shared_ptr<Rectangle>> expected_result;

    void read_json(string fileName, json& jsonRoot)
    {


        ifstream ifs(fileName, ifstream::in);


        if (ifs.is_open())
        {
            try
            {
                ifs >> jsonRoot;
            }
            catch (exception e)
            {
                cout << "Badly formed json input" << endl;
            }
            ifs.close();

        }
    }

    void parseFromJson(const json& rectanglesJsonArray)
    {
        int count = (int)rectanglesJsonArray.size();

        expected_result.reserve(count);

        for (int i = 0; i < count; i++)
        {
            auto rectangle = shared_ptr<Rectangle>(new Rectangle(rectanglesJsonArray[i]));
            expected_result.push_back(rectangle);
        }
    }

    /* Correct json file */

    TEST(TestCaseName, CorrectJsonInput) {
        read_json("json/testCorrectInput.json", jsonInput);
        read_json("json/TestCorrectOutput.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        EXPECT_EQ(result.getRectangles().size(), expected_result.size());


        int index = 0;
        for (auto res_iter : result.getRectangles())
        {
            EXPECT_EQ( (*res_iter).getTopLeft().getX(), (* (expected_result[index])).getTopLeft().getX() );
            EXPECT_EQ((*res_iter).getTopLeft().getY(), (*(expected_result[index])).getTopLeft().getY() );
            EXPECT_EQ((*res_iter).getWidth(), (*(expected_result[index])).getWidth() );
            EXPECT_EQ((*res_iter).getHeight(), (*(expected_result[index])).getHeight() );
            index++;
        }
        expected_result.clear();
    }

    /* Check that json is empty */
    TEST(TestCaseName, EmptyJsonFormat)
    {
        read_json("json/testEmptyInput.json", jsonInput);
        RectIntersection result(jsonInput["rects"]);
        EXPECT_EQ(result.getRectangles().size(), 0);

    }

    /* Two rectangles with intersection  */

    TEST(TestCaseName, TwoRectIntersection)
    {
        read_json("json/TwoRectIntersection.json", jsonInput);
        read_json("json/TwoRectIntersectionResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());


        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Two rectangles with intersection, with the same X coordinate and Widht  */

    TEST(TestCaseName, TwoRectIntersectionSameXandW)
    {
        read_json("json/TwoRectIntersectionSameXandW.json", jsonInput);
        read_json("json/TwoRectIntersectionSameXandWResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());


        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Two rectangles with intersection, with the same Y coordinate and Height  */

    TEST(TestCaseName, TwoRectIntersectionSameYandH)
    {
        read_json("json/TwoRectIntersectionSameYandH.json", jsonInput);
        read_json("json/TwoRectIntersectionSameYandHResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());


        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Two rectangles with intersection, one lies totally inside another  */

    TEST(TestCaseName, TwoRectIntersectionTotallyInside)
    {
        read_json("json/TwoRectIntersectionTotallyInside.json", jsonInput);
        read_json("json/TwoRectIntersectionTotallyInsideResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());


        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Check that intersection doesn't changed if we change rectangles order in list */

    TEST(TestCaseName, TwoRectIntersectionChangeOrder)
    {
        read_json("json/TwoRectIntersectionChangeOrder.json", jsonInput);
        read_json("json/TwoRectIntersectionChangeOrderResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());


        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Two rectangles with intersection by cross  */

    TEST(TestCaseName, TwoRectIntersectionCross)
    {
        read_json("json/TwoRectIntersectionCross.json", jsonInput);
        read_json("json/TwoRectIntersectionCrossResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());


        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Two rectangles with intersection, coordinates are closed to INT_MAX */

    TEST(TestCaseName, TwoRectIntersectionBigNumbers)
    {
        read_json("json/TwoRectIntersectionBigNumbers.json", jsonInput);
        read_json("json/TwoRectIntersectionBigNumbersResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());


        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Two rectangles no intersection  */

    TEST(TestCaseName, TwoRectNoIntersect)
    {
        read_json("json/TwoRectNoIntersect.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 0);

    }

    /* Two rectangles with intersection by one Y side  */

    TEST(TestCaseName, TwoRectNoOverlapIntersectY)
    {
        read_json("json/TwoRectNoOverlapIntersectY.json", jsonInput);
        read_json("json/TwoRectNoOverlapIntersectYResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();

    }

    /* Two rectangles with intersection by one X side  */

    TEST(TestCaseName, TwoRectNoOverlapIntersectX)
    {
        read_json("json/TwoRectNoOverlapIntersectX.json", jsonInput);
        read_json("json/TwoRectNoOverlapIntersectXResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Three rectangles with no intersection, with shift left */

    TEST(TestCaseName, TwoRectNoIntersectLeftShift)
    {
        read_json("json/TwoRectNoIntersectLeftShift.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 0);

    }

    /* Three rectangles with no intersection, with shift right */

    TEST(TestCaseName, TwoRectNoIntersectRightShift)
    {
        read_json("json/TwoRectNoIntersectRightShift.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 0);
    }

    /* Three rectangles with no intersection, with shift up */

    TEST(TestCaseName, TwoRectNoIntersectUpShift)
    {
        read_json("json/TwoRectNoIntersectUpShift.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 0);

    }

    /* Three rectangles with no intersection, with shift down */

    TEST(TestCaseName, TwoRectNoIntersectDownShift)
    {
        read_json("json/TwoRectNoIntersectDownShift.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 0);
    }

     /* Three rectangles lies one inside another with one common corner */

    TEST(TestCaseName, ThreeRectFromOneCorner)
    {
        read_json("json/ThreeRectFromOneCorner.json", jsonInput);
        read_json("json/ThreeRectFromOneCornerResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Three rectangles intersection */

    TEST(TestCaseName, ThreeRectIntersection)
    {
        read_json("json/ThreeRectIntersection.json", jsonInput);
        read_json("json/ThreeRectIntersectionResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Three rectangles, 2 have intersection, 1 stand alone */

    TEST(TestCaseName, ThreeRect2Intersection1Alone)
    {
        read_json("json/ThreeRect2Intersection1Alone.json", jsonInput);
        read_json("json/ThreeRect2Intersection1AloneResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Three rectangles, intersection by 2 */

    TEST(TestCaseName, ThreeRectIntersectionBy2)
    {
        read_json("json/ThreeRectIntersectionBy2.json", jsonInput);
        read_json("json/ThreeRectIntersectionBy2Result.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Three rectangles, no intersection*/

    TEST(TestCaseName, ThreeRectNoIntersect)
    {
        read_json("json/ThreeRectNoIntersect.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 0);
    }

    /* Four rectangles, random intersection */

    TEST(TestCaseName, FourIntersection)
    {
        read_json("json/FourIntersection.json", jsonInput);
        read_json("json/FourIntersectionResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();

    }

    /* Ten rectangles, random intersection */

    TEST(TestCaseName, TenIntersection)
    {
        read_json("json/TenRectRandomIntersection.json", jsonInput);
        read_json("json/TenRectRandomIntersectionResult.json", jsonOutput);

        parseFromJson(jsonOutput["rects"]);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), expected_result.size());

        int index = 0;
        for (auto res_iter : intersection_result)
        {

            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getX(), expected_result[index]->getTopLeft().getX());
            EXPECT_EQ(res_iter->getIntersection()->getTopLeft().getY(), expected_result[index]->getTopLeft().getY());
            EXPECT_EQ(res_iter->getIntersection()->getWidth(), expected_result[index]->getWidth());
            EXPECT_EQ(res_iter->getIntersection()->getHeight(), expected_result[index]->getHeight());

            index++;
        }
        expected_result.clear();
    }

    /* Check interssection for 10 rectangles with one common corner */

    TEST(TestCaseName, TenIntersectionWithOneCorner)
    {
        read_json("json/TenIntersectionWithOneCorner.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 1013);
    }

    /* Check that 11th rectange doesn't used in calculation */

    TEST(TestCaseName, ElevenIntersection)
    {
        read_json("json/ElevenIntersection.json", jsonInput);

        RectIntersection result(jsonInput["rects"]);

        vector<shared_ptr<Intersection>> intersection_result;
        intersection_result = result.getIntersections();

        EXPECT_EQ(intersection_result.size(), 1013);
    }

    /* Check what weidht can't be negative number */

    TEST(TestCaseName, ExceptionWidhtNegative)
    {
        auto createInvalidRectangle = []() {
            Point point(100, 100);
            Rectangle invalidrect(point, -5, 10);
        };

        EXPECT_THROW(createInvalidRectangle(), std::invalid_argument);
    }

    /* Check what height can't be negative number */

    TEST(TestCaseName, ExceptionHeightNegative)
    {
        auto createInvalidRectangle = []() {
            Point point(100, 100);
            Rectangle invalidrect(point, 5, -10);
        };

        EXPECT_THROW(createInvalidRectangle(), std::invalid_argument);
    }

    /* Check what x-coordinate can't be negative number */

    TEST(TestCaseName, ExceptionXCoorNegative)
    {
        auto createInvalidRectangle = []() {
            Point point(-100, 100);
            Rectangle invalidrect(point, 5, 10);
        };

        EXPECT_THROW(createInvalidRectangle(), std::invalid_argument);
    }

    /* Check what y-coordinate can't be negative number */

    TEST(TestCaseName, ExceptionYCoorNegative)
    {
        auto createInvalidRectangle = []() {
            Point point(100, -100);
            Rectangle invalidrect(point, 5, 10);
        };

        EXPECT_THROW(createInvalidRectangle(), std::invalid_argument);
    }

    /* Check behavior when we can't open json file */

    TEST(TestCaseName, ExceptionCantOpenJson)
    {
        string filename = "test2.json";
        int res;
        res = read_json_file(filename, jsonInput);

        EXPECT_EQ(res, -1);
    }

    /* Check behavior when we can't open json file */

    TEST(TestCaseName, ExceptionOneRowJSON)
    {
        string filename = "test.json";
        int res;
        res = read_json_file(filename, jsonInput);

        EXPECT_EQ(res, -1);
    }
}