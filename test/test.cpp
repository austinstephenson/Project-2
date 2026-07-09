// #include <catch2/catch_test_macros.hpp>
// #include <iostream>
// #include <iomanip>
//
// #include "AVL.h"
// #include <sstream>
//
//
// // William Stephenoson
// // UFID: 76843288
//
// using namespace std;
//
//
// //USING TESTS FROM PROJECT TEST CHECKIN w/ SMALL ADJUSTMENTS
//
// TEST_CASE("Example BST Insert", "[flag]"){
// 		MyAVLTree tree;   // Create a Tree object
// 		tree.insert("Abel", "33333333");
// 		tree.insert("Ben", "22222222");
// 		tree.insert("Cain", "11111111");
// 		std::vector<string> actualOutput;
// 		actualOutput =tree.getInorder();
// 		std::vector<string> expectedOutput = {"Cain", "Ben", "Abel"};
// 		REQUIRE(expectedOutput.size() == actualOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// }
//
//
//
//
// TEST_CASE("Unsuccessful Inserts", "[flag]") {
// 	MyAVLTree tree;
//
// 	SECTION("Ufid contains letter") {
// 		REQUIRE(tree.insert("Alex", "0000000A")==false);
//
// 	};
// 	SECTION("Ufid contains symbol") {
//
// 		REQUIRE(tree.insert("Ben","0000000!")==false);
// 	}
// 	SECTION("Ufid below 8 digits") {
// 		REQUIRE(tree.insert("Catherine", "0000005")==false);
// 	}
// 	SECTION("Ufid above 8 digits") {
// 		REQUIRE(tree.insert("Catherine", "000000511")==false);
// 	}
// 	SECTION("Name contains non-alphabetic") {
// 		REQUIRE(tree.insert("LolCatXD<3", "12345678")==false);
// 	}
// }
// TEST_CASE("Rotations", "[flag]") {
// 	MyAVLTree tree;
//
// 	SECTION("LEFT ROTATION") {
//
// 		tree.insert("Alex", "00000001");
// 		tree.insert("Ben", "00000002");
// 		tree.insert("Catherine", "00000003");
// 		Node* root= tree.getRoot();
//
//
// 		REQUIRE(root != nullptr);
// 		REQUIRE(root->ufid == "00000002");
//
// 	}
// 	SECTION("Right ROTATION") {
//
// 		tree.insert("Alex", "00000006");
// 		tree.insert("Ben", "00000005");
// 		tree.insert("Catherine", "00000004");
// 		Node* root= tree.getRoot();
//
// 		REQUIRE(root != nullptr);
// 		REQUIRE(root->ufid == "00000005");
//
// 	}
// 	SECTION("Left-Right ROTATION") {
// 		tree.insert("Alex", "00000008");
// 		tree.insert("Ben", "00000005");
// 		tree.insert("Catherine", "00000006");
// 		Node* root= tree.getRoot();
//
// 		REQUIRE(root != nullptr);
// 		REQUIRE(root->ufid == "00000006");
// 	}
//
// 	SECTION("Right-Left ROTATION") {
// 		tree.insert("Alex", "00000007");
// 		tree.insert("Ben", "00000009");
// 		tree.insert("Catherine", "00000008");
// 		Node* root= tree.getRoot();
//
// 		REQUIRE(root != nullptr);
// 		REQUIRE(root->ufid == "00000008");
// 	}
// }
// TEST_CASE("Large Insert"){
// 	MyAVLTree tree;
// 	for (int i=0; i<100; i++) {
// 		stringstream ss;
// 		ss<< setw(8) << setfill('0')<<i;
// 		tree.insert("Alex", ss.str());
// 	}
// 	//removal
// 	for (int i=20; i<30; i++) {
// 		stringstream ss;
// 		ss<< setw(8) << setfill('0')<<i;
// 		tree.remove(ss.str());
// 	}
// 	}