// ~/Remember,remember the 6th of March
#include <functional>
#include <iomanip>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include<complex>
#include <unordered_map>
#include<unordered_set>
#include <numeric>
#include <string>
#include<iostream>
#include <fstream>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include<cmath>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double  EPS = 1e-11;
const ll MOD = 1000000007;
const int N = 100000 + 7;
// --------------------- Complex Number and 2D Point -------------- //
#define angle(a)				  atan2(a.imag(),a.real())                // to get the angle.
#define length(a)				  hypot(a.imag() , a.real())              // to get r.
#define vec(a,b)				  (b-a)                                   // vector
#define dotP(a,b)				  (conj(a)*b).real()					   // Dot product.
#define crossP(a,b)				  (conj(a)*b).imag()			           // Cross Product.
#define rotate0(p,ang)            (p*exp(complex<double>(0,ang)))         // rotate around zero.
#define rotateA(p,ang,about)	  (rotate0(vec(about,p),ang,about)        // rotate around point.
#define reflect0(v,m)             (conj(v/m)*m)                            // v&m are vectors , reflect form origin around vectot.
// --------------------- Complex Number and 2D Point -------------- //
void fast()
{
	std::ios_base::sync_with_stdio(0);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
#endif
	complex<double> n1(1, 1), n2(5, 3);
	cout << n1 << endl;					  // (1,1);
	cout << abs(n1) << endl;              // 1.4142135623730950488016887242097   the radias called mudulas or absulute value.
	cout << arg(n1) << endl;              // angle alled argument , it will be in radian 
	cout << arg(n1) * 180 / PI << endl;   // 45 degree
	cout << norm(n1)<<endl;               // real^2 + imaginary^2
	cout << n1 * 3.0 << endl;			  // normaly product (real*3 , imaginary*3)
	cout << (n1 * 10.0)/2.0 << endl;	  // normaly division (real*10 /3 , imaginary*10 /3)
	cout << n1 + n2 << endl;			  // normaly addition (6,4).
	cout << n1 - n2 << endl;			  // normaly subtraction (-4 -2).	
	complex<double>n3 = polar(1.4142135623730950488016887242097, 45 * PI / 180);
	cout << n3 << endl;					  // you can creat the complex number from polar representation
										  // of course we can get each part alone. 
	cout << n2.real() << "  ,  " << n2.imag() << endl;  
	complex<double>n4;
	cout << n4 << endl;                   // will be zero for each part.
	complex<double>n5 = 33;
	cout << n5 << endl;                   // that is mean the real part equal 33 and the imagenarty part equal zero.
	cout << conj(n5) << endl;             // that is mean reflect the sign of imagenary part.
	cout << pow(n2, 2) << endl;           // this is equal to (5+3)^2.
	double ang_n1= angle(n1);
	cout << ang_n1 * 180.0 / PI << endl;
	double len = length(n1);
	cout << len << endl;
	double dotProduct, crossProduct;
	dotProduct = dotP(complex<double>(5, 12), complex<double>(-6, 8));
	cout << dotProduct << endl;
	crossProduct = crossP(complex<double>(5, 12), complex<double>(-6, 8));
	cout << crossProduct << endl;
	return 0;
}
