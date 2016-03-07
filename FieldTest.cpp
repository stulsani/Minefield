/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"

using namespace std;

class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, isSafe)
{
	Field minefield;
  	ASSERT_TRUE( minefield.isSafe(6,5) );
}

TEST(FieldTest, isSafe1)
{
	Field minefield;
  	ASSERT_TRUE( minefield.isSafe(0,5) );
}

TEST(FieldTest, isSafe2)
{
	Field minefield;
  	ASSERT_TRUE( minefield.isSafe(6,0) );
}

TEST(FieldTest, isSafe3)
{
	Field minefield;
  try
  {
  	ASSERT_TRUE( minefield.isSafe(69949,56387) );
  }
  catch(...)
  {
    cout << "Exeption occured" << endl;
  }
}

TEST(FieldTest, isSafe4)
{
	Field minefield;
  try
  {
  	ASSERT_TRUE( minefield.isSafe(-6,-5) );
  }
  catch(...)
  {
    cout << "Exeption occured" << endl;
  }
}

TEST(FieldTest, isSafe5)
{
	Field minefield;
  try
  {
  	ASSERT_TRUE( minefield.isSafe(-6,5) );
  }
  catch(...)
  {
    cout << "Exeption occured" << endl;
  }
}

TEST(FieldTest, isSafe6)
{
	Field minefield;
  try
  {
  	ASSERT_TRUE( minefield.isSafe(6,-5) );
  }
  catch(...)
  {
    cout << "Exeption occured" << endl;
  }
}

TEST(FieldTest, isSafe7)
{
	Field minefield;
  try
  {
  	ASSERT_FALSE( minefield.isSafe(-6,-5) );
  }
  catch(...)
  {
    cout << "Exeption occured" << endl;
  }
}
