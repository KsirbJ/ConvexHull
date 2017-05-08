#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "common.h"
#include "giftwrapping.cpp"
#include "grahamscan.cpp"
#include <set>

using namespace std;

vector<point> gen_points(int total){

	int x = 0, y = 0;
	vector<point> points;

	for(x = 0; x < total/4; ++x){
		point p;
		p.x = x;
		p.y = y;
		points.push_back(p);
	}

	for(y = 0; y < total/4; ++y){
		point p;
		p.x = x;
		p.y = y;
		points.push_back(p);
	}

	//cout << "here " << points.size() << endl;
	while(x > 0){
		point p;
		p.x = x;
		p.y = y;
		points.push_back(p);
		--x;
	}

	while(y > 0){
		point p;
		p.x = x;
		p.y = y;
		points.push_back(p);
		--y;
	}

	//cout << points.size() << endl;
	return points;
}

int main(int argc, char const *argv[])
{

	// read in files
	string files[10] = {"1k", "10k", "50k", "100k", "250k", "400k", "550k", "700k", "850k", "1m"};
	int sizes[10] = {1000, 10000, 50000, 100000, 250000, 400000, 550000, 700000, 850000, 1000000};

	ifstream inx;
	ifstream iny;
	
	for(int i = 0; i < 10; ++i){
		inx.open(files[i]+"x.txt");
		iny.open(files[i]+"y.txt");
		set<point> points_;
		//points.reserve(sizes[i]);

		int xline, yline;
		int j = 0;
		while(inx >> xline && iny >> yline){
			point p;
			p.x = xline;
			p.y = yline;
			points_.insert(p);
			j++;
		}


		// Copy to vector for easier use
		vector<point> points(points_.begin(), points_.end());

		//sort(points.begin(), points.end());
		//points.erase(unique(points.begin(), points.end()), points.end());
		
		// start timing the program execution
		auto start = chrono::high_resolution_clock::now();
		// run the giftwrapping algorithm on the points
		int res = do_giftwrapping(points);
		// end the timer
		auto end = chrono::high_resolution_clock::now();
		// calculate the duration
		auto span = chrono::duration_cast<chrono::duration<double>>(end - start);

		cout << "Gifwrapping took " << span.count() << " seconds for " << sizes[i] << " points." << endl;
		cout << "Number of points on the hull: " << res << endl;

		auto start2 = chrono::high_resolution_clock::now();
		int res2 = doGrahamscan(points);
		auto end2 = chrono::high_resolution_clock::now();
		auto span2 = chrono::duration_cast<chrono::duration<double>>(end2 - start2);

		
		cout << "Graham Scan took " << span2.count() << " seconds for " << sizes[i] << " points." << endl;
		cout << "Number of points on the hull: " << res2 << endl;
		inx.close();
		iny.close();

	}

	// int sizes_[10] = {1000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000};
	// for(int x = 0; x < 10; ++x){
	// 	vector<point> points(gen_points(sizes_[x]));

	// 	// start timing the program execution
	// 	auto start = chrono::high_resolution_clock::now();
	// 	// run the giftwrapping algorithm on the points
	// 	int res = do_giftwrapping(points);
	// 	// end the timer
	// 	auto end = chrono::high_resolution_clock::now();
	// 	// calculate the duration
	// 	auto span = chrono::duration_cast<chrono::duration<double>>(end - start);


	// 	auto start2 = chrono::high_resolution_clock::now();
	// 	int res2 = doGrahamscan(points);
	// 	auto end2 = chrono::high_resolution_clock::now();
	// 	auto span2 = chrono::duration_cast<chrono::duration<double>>(end2 - start2);

	// 	cout << "Gifwrapping took " << span.count() << " seconds for " << sizes_[x] << " points." << endl;
	// 	cout << "Number of points on the hull: " << res << endl;
	// 	cout << "Graham Scan took " << span2.count() << " seconds for " << sizes_[x] << " points." << endl;
	// 	cout << "Number of points on the hull: " << res2 << endl;
	// }

	// vector<point> p = {{876, 911}, {935, 481}, {973, 510}, {625, 5},
 //                      {843, 352}, {810, 14}, {980, 775}, {759,910}, {83,411}, {874, 836}};

 //    cout <<  do_giftwrapping(p) << endl;

  	return 0;

}


