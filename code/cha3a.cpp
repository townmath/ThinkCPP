#include <cmath>

int main(){
	
	double pi = acos(-1.0); 
	double degrees = 90; 
	double angle = degrees*2*pi/360.0;
	//composition
	double x = cos (angle + pi/2);
	//all in one
	double y = sin (90*2*acos(-1.0)/360.0 + acos(-1.0)/2);
	
}
