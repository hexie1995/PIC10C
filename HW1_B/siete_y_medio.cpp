#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Test for merge.


// Non member functions declarations (if any)
void draw_card(Hand& A);
void run_one_round(Player & p, Hand& d, ofstream& f);
void dealer_draw_card(Hand& A);
bool player_is_closer(Player A, Hand D);
// Non member functions implementations (if any)


// Stub for main
int main() {
	int count = 0;
	int init_money = 100;
	
	Player A(init_money);
	Hand Dealer;
	ofstream myfile;
	myfile.open("sample_run.txt");
	myfile << "--------------------------------------";

	while(A.money_left() >0){
		
		count = count + 1;
		myfile << "Game Round: " << count << endl;
		run_one_round(A , Dealer, myfile);
		myfile << "--------------------------------------";
		//record_one_round(count);
	
	}


	myfile.close();

	cout << "You have $0. GAME OVER!";
	cout << "Come back when you have more money.";
	cout << "Bye!";

	return 0;
}

void draw_card(Hand& A) {
	Card p;
	A.pushback_Card(p);
}

void dealer_draw_card(Hand& A) {
	Card p;
	A.dealer_pushback_Card(p);
}


void run_one_round(Player& p, Hand& d, ofstream& f) {



	cout << "You have $: " << p.money_left()<<endl;
	double bet;
	f << "Money left: " << p.money_left() << endl;
	cout << "Enter bet: ";
	cin >> bet;
	cout << endl;

	f << "Bet is: " << bet << endl;

	draw_card(p.myhand());
	p.myhand().print_Hand();
	
	dealer_draw_card(d);
	d.print_dealer_hand();
	
	
	while (true){
		string answer;
		cout << "Do you want to draw one more card? [y/n]";
		cin >> answer;
		if (answer == "n") {
			break;
		}
		else if(answer == "y") {
			draw_card(p.myhand());
			p.myhand().print_Hand();
		}
	}

	while (player_is_closer && d.print_dealer_total() <= 7.5) {
		dealer_draw_card(d);
		d.print_dealer_hand();
	}



	double player_total = p.myhand().print_total();
	double dealer_total = d.print_dealer_total();


	f << "Player Hand is: " << endl;
	p.myhand().output_hand(f);
	f << "Player Total is: " << player_total << endl;

	f << "Dealer Hand is: " << endl;
	d.output_dealer_hand(f);
	f << "Dealer Total is: " << dealer_total << endl;



	if (player_total == dealer_total && player_total<=7.5 && dealer_total<=7.5 ) {
		cout << "Nobody win." << endl;
	}

	else if ((player_total<=7.5 && dealer_total<=7.5 && player_is_closer)||(player_total <=7.5 && dealer_total>7.5) ){
		cout << "You win $" << bet<<endl;
		p.change_money(bet, true);
	}
	
	else if ((dealer_total <=7.5 && player_total <=7.5 && !player_is_closer) || (dealer_total <=7.5 && player_total>7.5)) {
		cout << "Dealer win. You lose $" << bet <<endl;
		p.change_money(bet, false);
	}

	else if (dealer_total > 7.5 && player_total > 7.5) {
		cout << "Dealer win, house benefit. You lose $" << bet<<endl;
		p.change_money(bet, false);
	}

	p.delete_hand();
	d.delete_myhand();



}

bool player_is_closer(Player A, Hand D){
	return (abs(7.5 - A.myhand().print_total()) < abs(7.5 - D.print_dealer_total()) ) ;
}

