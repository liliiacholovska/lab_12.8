#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.8/lab_12.8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(InsertSingleElement)
        {
            Place* head = nullptr;
            Insert(head, "Dro", 140);
            Assert::IsNotNull(head);
            Assert::AreEqual(string("Dro"), head->name);
            Assert::AreEqual(140, head->distance);
            Assert::IsTrue(head == head->next);
            Assert::IsTrue(head == head->prev);
        }

        TEST_METHOD(InsertMultipleElements)
        {
            Place* head = nullptr;
            Insert(head, "Dro", 140);
            Insert(head, "Lviv", 150);
            Insert(head, "Stryj", 90);

            Assert::AreEqual(string("Dro"), head->name);
            Assert::AreEqual(string("Lviv"), head->next->name);
            Assert::AreEqual(string("Stryj"), head->next->next->name);
            Assert::IsTrue(head == head->next->next->next);
        }

        TEST_METHOD(FindDistanceSimple)
        {
            Place* head = nullptr;
            Insert(head, "Dro", 140);
            Insert(head, "Lviv", 150);
            Insert(head, "Stryj", 90);

            int distance = FindDistance(head, "Dro", "Lviv");
            Assert::AreEqual(140, distance);
        }

        TEST_METHOD(FindClosestDistanceTest)
        {
            Place* head = nullptr;
            Insert(head, "Dro", 140);
            Insert(head, "Lviv", 150);
            Insert(head, "Stryj", 90);
            Insert(head, "Stebnyk", 120);

            auto result = FindClosestDistance(head, 145);
            Assert::AreEqual(string("Dro"), result.first);
            Assert::AreEqual(string("Lviv"), result.second);
        }
	};
}