#include <iostream>
#include <Eigen/Dense>
#include <boost/timer/timer.hpp>
#include <list>

using namespace boost::timer;
using namespace Eigen;

using boost::timer::cpu_timer; 

int main()
{

 std::list<int> listOfInts( { 100, 250, 500, 750, 1000, 1250, 1500});
 
 for (int val : listOfInts)
 {
    cpu_timer timer;
 	
    unsigned int row, col;
 	
 	MatrixXd A(val,val);
 	for (row=0; row!=val; ++row)
    {
    	
    	    for (col=0; col!=val; ++col)
    	{
    		A(row,col) = static_cast<double>(std::rand()) /
    		
    		static_cast<double>(RAND_MAX);
    	}
    } 
    
        MatrixXd B(val,val);
 	for (row=0; row!=val; ++row)
    {
    	
    	    for (col=0; col!=val; ++col)
    	{
    		B(row,col) = static_cast<double>(std::rand()) /
    		
    		static_cast<double>(RAND_MAX);
    	}
    } 
    
 	MatrixXd C = A*B;
 	
 	
 	std::cout << "Matrix size: " << C.rows() << "x" << C.cols() 
 	
 	<< ". Time: " << timer.format(2, "%t sec.\n") <<  std::endl;
 }


}