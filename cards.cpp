#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
   Card class
   ************************************************* */

   /*
	  Default constructor for the Card class.
	  It could give repeated cards. This is OK.
	  Most variations of Blackjack are played with
	  several decks of cards at the same time.
   */
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "coin";
		break;
	case COPAS:
		suitName = "cup";
		break;
	case ESPADAS:
		suitName = "spade";
		break;
	case BASTOS:
		suitName = "club";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "one";
		break;
	case DOS:
		rankName = "two";
		break;
	case TRES:
		rankName = "three";
		break;
	case CUATRO:
		rankName = "four";
		break;
	case CINCO:
		rankName = "five";
		break;
	case SEIS:
		rankName = "six";
		break;
	case SIETE:
		rankName = "seven";
		break;
	case SOTA:
		rankName = "ten";
		break;
	case CABALLO:
		rankName = "eleven";
		break;
	case REY:
		rankName = "twelve";
		break;
	default: break;
	}
	return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;

}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
   // Implemente the member functions of the Hand class here.

Hand::Hand(){
	vector<Card> A = my_hand;
	vector<Card> B = dealer_hand;
}

void Hand::pushback_Card(Card A) {
	my_hand.push_back(A);
}

void Hand::dealer_pushback_Card(Card A) {
	dealer_hand.push_back(A);
}

void Hand::print_Hand() {
	
	double total = 0;
	cout << "Your Hand is: ";
	for (int i = 0; i< my_hand.size() ;i++ ) {
		cout << my_hand[i].get_english_suit();
		cout << " of ";
		cout << my_hand[i].get_english_rank()<<endl;
		if (my_hand[i].get_rank() > 8) {
			total = total + 0.5;
		}
		else {
			total += my_hand[i].get_rank();
		}
	}
	cout << "Your total is: "<<total<<endl;
}

void Hand::print_dealer_hand() {
	
	double total = 0;
	cout << "Dealer's hand is:  ";
	for (int i = 0; i < dealer_hand.size(); i++) {
		cout << dealer_hand[i].get_english_suit();
		cout << " of ";
		cout << dealer_hand[i].get_english_rank()<< endl;
		if (dealer_hand[i].get_rank() > 8) {
			total = total + 0.5;
		}
		else {
			total += dealer_hand[i].get_rank();
		}
	}
	cout << "Dealer's total is: "<<total<<endl;

}


double Hand::print_total() {
	double total = 0;

	for (int i = 0; i < my_hand.size(); i++) {
		if (my_hand[i].get_rank() > 8) {
			total = total + 0.5;
		}
		else {
			total += my_hand[i].get_rank();
		}
	}

	return total;
}

double Hand::print_dealer_total() {
	double total = 0;

	for (int i = 0; i < dealer_hand.size(); i++) {
		if (dealer_hand[i].get_rank() > 8) {
			total = total + 0.5;
		}
		else {
			total += dealer_hand[i].get_rank();
		}
		cout << endl;
	}

	return total;
}

void Hand::delete_myhand() {
	vector <Card> A;
	vector <Card> B;
	my_hand = A;
	dealer_hand = B;
}

void Hand::output_dealer_hand(ofstream& F) {
	for (int i = 0; i < dealer_hand.size(); i++) {
		F << dealer_hand[i].get_english_suit();
		F << " of ";
		F << dealer_hand[i].get_english_rank() << endl;
	}
}

void Hand::output_hand(ofstream& F) {
	for (int i = 0; i < my_hand.size(); i++) {
		F <<  my_hand[i].get_english_suit();
		F << " of ";
		F << my_hand[i].get_english_rank() << endl;
	}
}


   /* *************************************************
	  Player class
	  ************************************************* */
	  // Implemente the member functions of the Player class here.
Player::Player(int m) {
	money = m;
}

void Player::print_money() {
	cout << "Your money is: $" << money;
}

int Player::money_left() const {
	return money;
}

Hand& Player::myhand() {
	return hand;
}

void Player::change_money(int bet, bool op) {
	if (op){
		money = money + bet;
	}
	else {
		money = money - bet;
	}


}

void Player::delete_hand() 
{
	Hand A;
	hand = A;
}


