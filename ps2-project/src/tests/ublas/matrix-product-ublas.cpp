#include <iostream>
#include <boost/timer/timer.hpp>
#include <list>
#include <boost/numeric/ublas/matrix.hpp> 
#include <boost/numeric/ublas/io.hpp>

using namespace boost::timer;
using namespace boost::numeric::ublas;

using boost::timer::cpu_timer; 

int main()
{
 // boost::timer::auto_cpu_timer timer;
 
 std::list<int> listOfInts( { 100, 250, 500, 750, 1000, 1250, 1500});
 
 for (int val : listOfInts)
 {
    cpu_timer timer;
    
    unsigned int row, col;
    
    matrix<double> A(val,val); 
    
    for (row=0; row!=val; ++row)
    {
    	for (col=0; col!=val; ++col)
    	{
    		A(row,col) = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
    	}
    } 
    		
    matrix<double> B(val,val); 
    
    for (row=0; row!=val; ++row)
    {
    	for (col=0; col!=val; ++col)
    	{
    		B(row,col) = static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX); 
    		
		}
		
	}
    matrix <double > C(val,val);
    C = prod(A,B);
    
    
    
 	//MatrixXd A = MatrixXd::Random(val,val);
 	//MatrixXd B = MatrixXd::Random(val,val);
 	//MatrixXd C = A*B;
 	
 	
 	//std::cout << "Matrix size: " << C.rows() << "x" << C.cols() << ". Time: " << timer.format(2, "%t sec.\n") <<  std::endl;
 	std::cout << "Matrix size: " << C.size1 () << ". Time: " << timer.format(2, "%t sec.\n") <<  std::endl;

}

}



