#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<vector>
#pragma once
using namespace std;

class Solution {
public:
	Solution();
	void forward_solver(vector<double>ic, vector<double>bc, int a);
	//void backward_solver(vector<double>ic, vector<double>bc);
	//void plot();
	void put_to_file(ofstream& f);

	vector <double> init();
	vector <double> bond(int k);



private:
	vector<vector<double>> mysol;
	double dx = 0.001;
	double dt = 0.0001;
	int X = 1000;
	int T = 10000;
};


class Solver {
public:
	Solver();
	Solver(int a);
	void transportaion_solver();

private:
	double dx = 0.001;
	double dt = 0.0001;
	int X = 1000;
	int T = 10000;
	int solve;
};
