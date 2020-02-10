#include <vector>
#include <gtest/gtest.h>
#include "proj1.hpp"

namespace{

	TEST(SampleTests, TestCostOfJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 1000}, 
				{1, 0, 6, 4}, 
				{1000, 7, 0, 8}, 
				{6, 3, 1000, 0}
		};
		std::vector<unsigned> journey = {0, 2, 3, 1};
		EXPECT_TRUE( costOfJourney(distances, journey) == 21);
	}

	TEST(SampleTests, TestFindJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 0}, 
				{1, 0, 6, 4}, 
				{0, 7, 0, 8}, 
				{6, 3, 0, 0}
		};
		std::vector<unsigned> expected = {0, 2, 3, 1}; // remember, we expect the journey to start at 0 in project 1.
		std::vector<unsigned> journey = tsp_dynamic_program(distances, 4);
		EXPECT_TRUE( journey == expected  || costOfJourney(distances, journey) == 21);

	}

// SUGGESTION:  COMMENT THIS OUT UNTIL THE FIRST TWO CASES WORK.


	TEST(SampleTests, LargerTest)
	{
		std::vector< std::vector< long > > distances = 
		{
			{0, 0, 0, -1, 54, 0, 51, 102, 80, 52, 0, 68, 51, 44, 100},
			{0, 0, 56, 102, 63, 70, 0, 0, 0, 93, -6, 48, 0, 0, 0},
			{84, -9, 0, 83, 0, 73, 20, 38, 0, -8, 105, 0, 43, 73, 2},
			{0, 0, 36, 0, 54, 24, 0, 59, 0, 83, 40, 75, 15, 74, 0},
			{14, 30, 87, 96, 0, 48, 84, 0, 0, 14, 0, 75, 0, 49, 0},
			{0, 103, 62, 0, 88, 0, 84, 11, 79, 27, 2, 102, 61, 16, 1},
			{0, 0, 33, 0, 79, 86, 0, 26, 1, 2, 12, 74, 0, 84, 50},
			{0, 1, 0, 68, 86, 19, 0, 0, 100, 12, 95, 25, 55, -2, 97},
			{100, 76, 0, 59, 0, 69, 47, 72, 0, 76, 19, 47, 91, 94, 11},
			{21, 48, 0, 30, 74, 2, -1, 0, 104, 0, 33, 22, 38, 68, 95},
			{0, 79, 15, 0, 28, 100, 91, 103, 0, 9, 0, 76, 41, 0, 102},
			{39, 83, 0, 49, 0, 101, 40, 0, 0, 55, 82, 0, 0, 0, 0},
			{101, 71, -2, 26, 109, 0, 82, 33, 7, 0, -1, -5, 0, 19, 11},
			{62, 98, 27, 39, 78, 0, 106, 0, 64, 24, 0, 58, 29, 0, 49},
			{10, 18, 26, 62, 6, 90, 75, 0, 0, 24, 46, 0, -7, 41, 0}
		};
		std::vector<unsigned> expected = {0, 3, 5, 7, 13, 2, 1, 10, 4, 9, 6, 8, 14, 12, 11};
		std::vector<unsigned> journey = tsp_dynamic_program(distances, 15);
		EXPECT_TRUE( journey == expected || costOfJourney(distances, journey) == 124);
	}

}
