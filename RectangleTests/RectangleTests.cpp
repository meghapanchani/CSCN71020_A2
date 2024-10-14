#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "../BCSRec/main.h"
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
	TEST_CLASS(RectangleTests)
	{
	public:
		
        // Test for getPerimeter
        TEST_METHOD(TestGetPerimeter)
        {
            int length = 10;
            int width = 20;
            int expectedPerimeter = 2 * (length + width); //  2 * (10 + 20) = 60

            int actualPerimeter = getPerimeter(&length, &width);

            Assert::AreEqual(expectedPerimeter, actualPerimeter);
        }

        // Test for getArea
        TEST_METHOD(TestGetArea)
        {
            int length = 11;
            int width = 11;
            int expectedArea = length * width;  //  11 * 11 = 121

            int actualArea = getArea(&length, &width);

            Assert::AreEqual(expectedArea, actualArea);
        }

        // Test for setLength
        TEST_METHOD(TestSetLengthNormal)
        {
            int length = 2; // Initial length set to 2
            setLength(20, &length); // Set new length to 20
            Assert::AreEqual(20, length);  // Verify that length was set to 20
        }

        TEST_METHOD(TestSetLengthLower)
        {
            int length = 0; 
            setLength(12, &length); 
            Assert::AreEqual(12, length);  
        }

        TEST_METHOD(TestSetLengthInvalid)
        {
            int length = 20;
            setLength(0, &length);  
            Assert::AreEqual(20, length);  

            setLength(100, &length);  
            Assert::AreEqual(20, length);  
        }

        // Test for setWidth
        TEST_METHOD(TestSetWidthNormal)
        {
            int width = 8; // Initial width set to 8
            setWidth(33, &width); // Set new width to 33
            Assert::AreEqual(33, width);  // Verify that width was set to 33
        }

        TEST_METHOD(TestSetWidthLower)
        {
            int width = 0; 
            setWidth(22, &width); 
            Assert::AreEqual(22, width);  
        }

        TEST_METHOD(TestSetWidthInvalid)
        {
            int width = 21; 
            setWidth(0, &width);  
            Assert::AreEqual(21, width);  

            setWidth(100, &width);  
            Assert::AreEqual(21, width);  
        }
	};
}
