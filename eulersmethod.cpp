//Метод Эйлера решения задачи Коши
#include <iostream>
#include <math.h>
#include <vector> 

void function();

int main(){
	
	function();
	
	return 0;
}

void function(){
	
	double h = 0.1;
	double f;
	double pogr, max_pogr = 0;
	std::vector<double> y(12);
	y[0] = 3;
	
	for (int i = 1; i != 12; i++)
	 {
		 y[i] = y[i-1] + (y[i-1] - ( (i-1)*0.1)*((i-1)*0.1) )*h;
		 f = exp(i*0.1) + (i*0.1)*(i*0.1) + 2.0*(i*0.1) + 2.0;
		 pogr = (fabs(f-y[i])/f)*100.0;
		 
		 if (max_pogr < pogr) max_pogr = pogr;
		
		 std::cout << " y = " << y[i] << " f = " << f << " pogr = " << pogr << " max_pogr = " << max_pogr << "\n";
	
	 }	
}

