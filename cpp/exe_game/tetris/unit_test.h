#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "global.h"
#include "Display.class.h"
#include "Control.class.h"
#include "TetrisCalc.class.h"
#include "Matrix.class.h"

//--------------------------------------

using namespace std;
void test_Control() ; // FUNC
void test_Matrix() ;// FUNC
void test_flow() ;// FUNC
void test_flow_tick() ;// FUNC
void test_Point() ;// FUNC
void test_deleteFromVector(); // FUNC
void test_time_engine();
void deleteFromVector(vector<Point*>* vecPtr, Point* item); // FUNC
#endif
