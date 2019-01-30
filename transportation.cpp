#include "util.h" // solvers to solve different pdes
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;
int main() {
	cout << "What kind of PDE do you want to solve£¿" << endl;
	cout << "Choose between the following ones and Type in the corresponding number" << endl;
	cout << "1. Transportation Equation: Ux+ a*Ut=0" << endl;
	cout << "2. Wave Equation: Uxx+ c^2*Utt=0" << endl;
	cout << "3. Heat Equation: Ut=b*Uxx" << endl;
	cout << "At this point only choice 1 give you what you want." << endl;

	int choice_of_eqn;
	cin >> choice_of_eqn;

	if (choice_of_eqn == 1) {

		ofstream myfile;
		ofstream& f=myfile;

		cout << "Give me a choice of constant a, a cannot be 0." << endl;
		double a;
		cin >> a;
		cout << "The default solver solve the equation over [0,1] x [0, 1]." << endl;
		cout << "The initial condition is g(x) = U(x,0) when t=0, g(x)= sin(x). " << endl; // how to let user specify initial condition. ?? specific libarary recommendation?
		cout << "The boundary condition is f(t) = U(0/1,t) when x=0/1 (depends on the sign of a), f(t)= cos(t)." << endl;
		Solution sol;
		vector<double> IC = sol.init();

		vector <double> transport;
		if (a > 0) {
			vector<double> BC = sol.bond(0);
			sol.forward_solver(IC,BC,a);
		}

		else {
			vector<double> BC = sol.bond(1);
			//sol.backward_solver(IC,BC);
		}
		f.open("tranportation.txt");
		sol.put_to_file(f);
		f.close();
		//sol.plot();// how to plot a wave equation in c++

	}

	else {
		cout << "Currently not availabe.";
	}





	return 0;
}