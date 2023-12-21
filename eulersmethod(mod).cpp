//Метод Эйлера с пересчетом (модифицированный) решения задачи Коши
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
	
	std::vector<double> y(12); //новый вектор, т.е y
	y[0] = 3;
	
	std::vector<double> y_(12); //старый вектор, т.е y*
	
	for (int i = 1; i != 12; i++)
	 {
		 y_[i] = y[i-1] + h*(y[i-1] - ( (i-1)*0.1)*((i-1)*0.1) ); 
		 y[i] = y[i-1] + (h/2.0)*( y[i-1]-((i-1)*0.1)*((i-1)*0.1) + y_[i]-(i*0.1)*(i*0.1) );
		 f = exp(i*0.1) + (i*0.1)*(i*0.1) + 2.0*(i*0.1) + 2.0;
		 pogr = (fabs(f-y[i])/f)*100.0;
		 
		 if (max_pogr < pogr) max_pogr = pogr;
		
		 std::cout << " y_ = " << y_[i] << " y = " << y[i] << " f = " << f << " pogr = " << pogr << " max_pogr = " << max_pogr << "\n";
	
	 }	
}
