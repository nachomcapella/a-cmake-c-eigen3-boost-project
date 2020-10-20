#include <iostream>
#include <Eigen/Dense>
#include <boost/timer/timer.hpp>
#include <list>
#define BOOST_TEST_MODULE boost_test_sequence
#include <boost/test/included/unit_test.hpp>

using namespace boost::timer;
using namespace Eigen;

using boost::timer::cpu_timer; 

BOOST_AUTO_TEST_CASE( test_collections_vectors )
{

 std::list<int> listOfInts( {250});
 
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
               if(row==col){
    		B(row,col) = 1;
    		}
    		else{
                B(row,col) = 0;
		}
    	}
    } 
    
 	MatrixXd C = A*B;
 	
 	
 	std::cout << "Matrix size: " << C.rows() << "x" << C.cols() << ". Time: " << timer.format(2, "%t sec.\n") <<  std::endl;
	BOOST_TEST(A == C);
 }


}