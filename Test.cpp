/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"}, c22{"22"}, c123{"123"}, c123456{"123456"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"}, g22{"22"}, g45{"45"}, g123456{"123456"}, g123{"123"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		
		/////////////////////////////// - Our Tests - ///////////////////////////////
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1324"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0000","1111"), "0,0")	   // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("7878","7777"), "2,0")	   // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6781","6789"), "3,0")	   // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("7543","7845"), "2,1")	   // 2 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4567","4756"), "1,3")	   // 1 bull, 3 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c22, g22, 2, 100), 1)			 // guesser wins in one turn.
		.CHECK_EQUAL(play(c22, g45, 2, 100), 101)		 // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c123456, g12345, 5, 100), 0)   // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c1234,g123456, 4, 100), 101)	 // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=10, true);  // smarty should always win in at most 10 turns!
		}
		
		/////////////////////////////// - Our Tests - ///////////////////////////////
		
		for (uint i=0; i<100; ++i) { 
			testcase.CHECK_EQUAL(play(c1234, smarty, 4, 100)<=10, true);  // Dummy chooser vs. smart guesser
		}
		for (uint i=0; i<100; ++i) { 
			testcase.CHECK_EQUAL(play(c12345, smarty, 5, 100)>=10, true); // Dummy chooser vs. smart guesser
		}
		for (uint i=0; i<100; ++i) { 
			testcase.CHECK_EQUAL(play(c12345, smarty, 3, 100), 0);  // chooser loses technically by choosing an illegal number (too long).
		}
		
		
		testcase.setname("Check learn")
		c1234.learn("1,2")
		CHECK_EQUAL(c1234.bull, 1)
		CHECK_EQUAL(c1234.pgia, 2)
		c22.learn("2,0")
		CHECK_EQUAL(c22.bull, 2)
		CHECK_EQUAL(c22.pgia, 0)
		g123456.learn("3,3")
		CHECK_EQUAL(g123456.bull, 3)
		CHECK_EQUAL(g123456.pgia, 3)
		
		
		testcase.setname("Check learn with invalid input")
		//"Caught exception! - the sum of bull+pgia is not equal to the length of the player choice"
		CHECK_THROWS(c1234.learn("3,3"))
		CHECK_THROWS(c22.learn("0,4"))
		CHECK_THROWS(g12345.learn("2,5"))
		CHECK_THROWS(g45.learn("2,2"))
		CHECK_THROWS(g45.learn("3,0"))

		
		
		

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}