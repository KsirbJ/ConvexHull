#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include "common.h"
#include "giftwrapping.cpp"
#include "grahamscan.cpp"
#include <set>


using namespace std;


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


		// Copy to vector for easier use (slow but easy way to filter duplicates)
		vector<point> points(points_.begin(), points_.end());

		
		// start timing the program execution
		auto start = chrono::high_resolution_clock::now();
		// run the giftwrapping algorithm on the points
		int res = do_giftwrapping(points);
		// end the timer
		auto end = chrono::high_resolution_clock::now();
		// calculate the duration
		auto span = chrono::duration_cast<chrono::duration<double>>(end - start);
		cout << "For "<< sizes[i] << " points:" << endl;

		cout << "\tGifwrapping took " << span.count() << endl;
		

		auto start2 = chrono::high_resolution_clock::now();
		doGrahamscan(points);
		auto end2 = chrono::high_resolution_clock::now();
		auto span2 = chrono::duration_cast<chrono::duration<double>>(end2 - start2);

		
		cout << "\tGraham Scan took " << span2.count() << endl;

		cout << "\tNumber of points on the hull: " << res << endl << endl;
		inx.close();
		iny.close();

	}

  	return 0;

}


