#include"util.h"
#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<vector>
#pragma once
using namespace std;

double dx = 0.001;
double dt = 0.0001;
int X = 1000;
int T = 10000;

///////////////////////////////////////


Solver::Solver() {
	cout << "Solver constructed" << endl;
}
Solver::Solver(int a) {
	if (a == 1) {
		solve = 1;
	}
	else if (a == 2) {
		solve = 2;
	}
	else {
		solve = 3;
	}
}

Solution::Solution(){
	cout << "Solution constructed" << endl;
}

void Solution::put_to_file(ofstream & f) {
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < T; j++) {
			f<<mysol[i][j]<<",";
		}
		f << endl;
	}
}

void Solution::forward_solver(vector<double>ic, vector<double>bc, int a) {
	vector<double> fixt_x = ic;
	vector<double> fixx_t = bc;
	vector<double >temp_fixx=bc;
	for (int i = 0; i < X; i++) {
		vector<double> temp = temp_fixx;
		temp_fixx[0] = fixt_x[i];
		for (int j = 1; j < T; j++) {
			temp_fixx[j] = a * (dt / dx)*(temp_fixx[j] - temp[j]) + temp_fixx[j];
		}
		mysol.push_back( temp_fixx);
	}
	cout << "solved";
}

vector <double> Solution::init() {
	vector <double> IC;
	double xi = 0;
	for (int i = 0; i < X; ++i) {
		IC.push_back( sin(xi));
		xi = xi + dx;
	}
	return IC;
}
vector <double> Solution::bond(int k) {
	vector <double> BC;
	double tj = k;
	if (k == 0) {
		for (int j = 0; j < T; ++j) {
			BC.push_back(cos(tj));
			tj = tj + dt;
		}
	}
	else {
		for (int j = T; j >0; --j) {
			BC.push_back (cos(tj));
			tj = tj + dt;
		}
	}
	return BC;
}