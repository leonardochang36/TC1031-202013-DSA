//------------------------------------------------------------------------------
// Record the execution time of some code, in milliseconds. 
// By Leonardo Chang, 2011.
// eg:
//	DECLARE_TIMING(myTimer);
//	START_TIMING(myTimer);
//	  printf("A slow calc = %f\n", 1.0/sqrt(2.0) );
//	STOP_TIMING(myTimer);
//	SHOW_TIMING(myTimer, "My Timer");
//------------------------------------------------------------------------------
#ifndef my_timer_h
#define my_timer_h
#include <chrono>  // for high_resolution_clock
#include <iostream>

#define DECLARE_TIMING(s)	    	std::chrono::time_point<std::chrono::high_resolution_clock> timeStart_##s; std::chrono::duration<double> timeDiff_##s; double timeTally_##s = 0; long countTally_##s = 0
#define START_TIMING(s)		    	timeStart_##s = std::chrono::high_resolution_clock::now()
#define STOP_TIMING(s)		    	timeDiff_##s = (std::chrono::high_resolution_clock::now() - timeStart_##s); timeTally_##s += timeDiff_##s.count(); countTally_##s++
#define GET_TIMING(s)		    	(double)timeDiff_##s.count()
#define GET_AVERAGE_TIMING(s)		(double)(countTally_##s ? (double)timeTally_##s / ((double)countTally_##s)  : 0)
#define GET_TIMING_COUNT(s)  		(int)(countTally_##s)
#define SHOW_TIMING(s, msg)	    	std::cout << msg << " time: \t" <<  GET_TIMING(s) << " seconds (" << GET_TIMING(s) / 60 << "min)\t" << GET_AVERAGE_TIMING(s) << " sec average across " << GET_TIMING_COUNT(s) << " runs." << std::endl

#endif