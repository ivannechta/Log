#include "pch.h"
#include "string.h"
#include "../../Log/Number.h"
#include "../../Log/Operation.h"

int cmp(int *a,int *b) {
	int i = 0;
	while (	(a[i]) != TERMINATOR || 
			(b[i] != TERMINATOR)) {
	
		if (a[i] < b[i]) return -1;
		else
			if ((a[i] > b[i])) return 1;
		i++;
	}
	return 0;
}
TEST(SetNumber, n15p2) {
	Number n;
	int s[] = { 1,1,1,1,TERMINATOR };
	n.SetNonation(2);
	n.Set(15);
	ASSERT_EQ(cmp(n.digit, s), 0);	
}

TEST(SetNumber, n20p7) {
	Number n(20,7);
	int s[] = { 2,6,TERMINATOR };
	ASSERT_EQ(cmp(n.digit, s), 0);
}

TEST(SetNumber, n44p7) {
	Number n(44, 7);
	int s[] = { 6,2,TERMINATOR };
	ASSERT_EQ(cmp(n.digit, s), 0);
}

TEST(SetNumber, n125p8) {
	Number n(125,8);
	int s[] = { 1,7,5,TERMINATOR };
	ASSERT_EQ(cmp(n.digit, s), 0);
}

TEST(SetWrongNotation, NonationIsIncorrect) {
	Number n;
	EXPECT_THROW(n.SetNonation(1), int);
}

TEST(GetWrongDig, OutOfBounds1) {
	Number n(125,8);
	EXPECT_THROW(n[6], int);
}

TEST(GetWrongDig, OutOfBounds2) {
	Number n(15, 2);
	EXPECT_THROW(n[4], int);
}

TEST(GetWrongDig, OutOfBounds3) {
	Number n(15, 2);
	EXPECT_THROW(n[-1], int);
}

TEST(Compare, Equal1) {
	Number a(15, 2);
	Number b(15, 2);
	ASSERT_EQ(a == b, true);	
}
TEST(Compare, Equal2) {
	Number a(15, 2);
	Number b(16, 2);
	ASSERT_EQ(a == b, false);
}
TEST(Compare, NotEqual1) {
	Number a(15, 2);
	Number b(15, 2);
	ASSERT_EQ(a != b, false);
}
TEST(Compare, NotEqual2) {
	Number a(15, 2);
	Number b(16, 2);
	ASSERT_EQ(a != b, true);
}

TEST(Compare, Less15_3) {
	Number a(15, 2);
	Number b(3, 2);
	ASSERT_EQ(a < b, false);
}

TEST(Compare, Less3_15) {
	Number a(3, 2);
	Number b(15, 2);
	ASSERT_EQ(a < b, true);
}

TEST(Compare, Less15_10) {
	Number a(15, 2);
	Number b(10, 2);
	ASSERT_EQ(a < b, false);
}

TEST(Compare, Less10_15) {
	Number a(10, 2);
	Number b(15, 2);
	ASSERT_EQ(a < b, true);
}





TEST(Compact, AllZero) {
	int s[] = { 0,0,0,TERMINATOR };
	Number a(s, 3, 2);
	Number b(0, 2);
	-a;
	ASSERT_EQ(a == b, true);
}
TEST(Compact, OneZero) {
	int s[] = { 0,1,1,TERMINATOR };
	Number a(s,3, 2);
	Number b(3, 2);
	-a;	
	ASSERT_EQ(a == b, true);
}

TEST(Compact, NoZero) {
	int s[] = { 1,1,TERMINATOR };
	Number a(s, 2, 2);
	Number b(3, 2);
	-a;
	ASSERT_EQ(a == b, true);
}

TEST(Sub, Sub4_3) {
	Number a(0b100, 2);
	Number b(0b11, 2);
	Number r(0b1, 2);
	Number c;
	c=a-b;
	ASSERT_EQ(c == r, true);
}

TEST(Sub, Sub150_63) {
	Number a(150, 10);
	Number b(63, 10);
	Number r(87, 10);
	Number c;
	c = a - b;
	ASSERT_EQ(c == r, true);
}

TEST(Sub, Sub23_12) {
	Number a(23, 7);
	Number b(12, 7);
	Number r(11, 7);
	Number c;
	c = a - b;
	ASSERT_EQ(c == r, true);
}

TEST(Shift, Shift0_1) {
	Number a(0, 7);	
	Number r(0, 7);
	a << 1;	
	ASSERT_EQ(a == r, true);
}

TEST(Shift, Shift1_1) {
	Number a(1, 7);
	Number r(7, 7);
	a << 1;
	ASSERT_EQ(a == r, true);
}
TEST(Get, Get15) {
	Number a(15, 2);
	ASSERT_EQ(a.Get(), 15);
}
TEST(Divide, Div_11_2) { //7^3%11=2
	Number a(1, 7);
	ASSERT_EQ(a.Divide(11, 2), 3);
}

TEST(Divide, Div_10_37_10) { //10^1%37=10
	Number a(1, 10);
	ASSERT_EQ(a.Divide(37, 10), 1);
}

TEST(Divide, Div_6_17_14) { //6^7%17=14
	Number a(1, 6);
	ASSERT_EQ(a.Divide(17, 14),7);
}

TEST(Divide, Div_4_11_4) { //4^1%11=4
	Number a(1, 4);
	ASSERT_EQ(a.Divide(11, 4),1);
}

TEST(Divide, Div_3_13_3) { //3^1%13=3
	Number a(1, 3);
	ASSERT_EQ(a.Divide(13, 3),1);
}

TEST(Divide, Div_9_19_16) { //9^5%19=16
	Number a(1, 9);
	ASSERT_EQ(a.Divide(19, 16),5);
}

TEST(Divide, Div_3_11_1) { //3^10%11=1
	Number a(1, 3);
	ASSERT_EQ(a.Divide(11, 1), 5);	
}