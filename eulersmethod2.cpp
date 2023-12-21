// y' = 1/sqrt(x^2-1)
// y(1) = 0
//решить методом Эйлера

#include <iostream>
#include <math.h>
#include <vector> 

void function();

int main(){
	
	function();
	
	return 0;
}

void function(){
	
	double h = 1;
	double f;
	double pogr, max_pogr = 0;
	
	std::vector<double> y(10);
	y[0] = 0;
	
	for (int i = 1; i != 10; i++)
	 {
		 if (i==1) y[i] = y[i-1] + (h/2.0)*( 0 + 1.0/sqrt((i+1)*(i+1) - 1.0) );
		 else y[i] = y[i-1] + (h/2.0)*( 1.0/sqrt(i*i - 1.0) + 1.0/sqrt((i+1)*(i+1) - 1.0) ); 
		 f = log( fabs( sqrt((i+1)*(i+1)-1.0)+(i+1) ) );
		 pogr = (fabs(f-y[i])/f)*100.0;
		 
		 if (max_pogr < pogr) max_pogr = pogr;
		
		 std::cout << "y =" << y[i] << "\t\t" << "f =" << f << "\t\t" << "pogr =" << pogr << "\t\t" << "max_pogr =" << max_pogr << "\n";
	
	 }	
}
