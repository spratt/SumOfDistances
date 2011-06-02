///////////////////////////////////////////////////////////////////////////////
//                       Copyright (c) 2011 - 2012 by                        //
//                                Simon Pratt                                //
//                           (All rights reserved)                           //
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// FILE:    SumOfDifferences.h                                               //
//                                                                           //
// MODULE:  Sum of Differences                                               //
//                                                                           //
// PURPOSE: To compare different methods of summing differences.             //
//                                                                           //
// NOTES:   None.                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
// Public Variable:                     Description:                         //
// ----------------                     ------------                         //
///////////////////////////////////////////////////////////////////////////////
//                             Public Methods:                               //
// naiveSum(vector<coord_T>)                                                 //
// neatSum(vector<coord_T>)                                                  //
///////////////////////////////////////////////////////////////////////////////

#include <vector>

using namespace std;

namespace SumOfDifferences {
  template <class coord_T>
  coord_T naiveSum(const vector<coord_T>& v)  {
    coord_T t = 0;
    for(int i = 0; i < ((int)v.size())-1; i++) {
      for(int j = i+1; j < (int)v.size(); j++) {
	t += j - i;
      }
    }
    return t;
  }
  /////////////////////////////////////////////////////////////////////////////
  //                                                                         //
  // FUNCTION NAME: neatSum                                                  //
  //                                                                         //
  // PURPOSE:       Uses a neat algorithm to determine the sum of            //
  //                differences between points.                              //
  //                                                                         //
  // SECURITY:      none                                                     //
  //                                                                         //
  // PARAMETERS                                                              //
  //   Type/Name:   vector<coord_T>/v                                        //
  //   Description: A vector of points.                                      //
  //                                                                         //
  // RETURN:        The sum of distance(i,j) where i is not equal to         //
  //                j, for all i and j.                                      //
  //                                                                         //
  // NOTES: Imagine these points:                                            //
  //        0     1     2     3     4   total                                //
  //        |-----|     |     |     |   d(0,1)                               //
  //        |-----|-----|     |     |   d(0,1) + d(1,2)                      //
  //        |-----|-----|-----|     |   d(0,1) + d(1,2) + d(2,3)             //
  //        |-----|-----|-----|-----|   d(0,1) + d(1,2) + d(2,3) + d(3,4)    //
  //        |     |-----|     |     |   d(1,2)                               //
  //        |     |-----|-----|     |   d(1,2) + d(2,3)                      //
  //        |     |-----|-----|-----|   d(1,2) + d(2,3) + d(3,4)             //
  //        |     |     |-----|     |   d(2,3)                               //
  //        |     |     |-----|-----|   d(2,3) + d(3,4)                      //
  //        |     |     |     |-----|   d(3,4)                               //
  //           ^     ^     ^     ^                                           //
  //           4     6     6     4                                           //
  //                                                                         //
  //        Notice that every interval is counted i*(n-i) times.             //
  //                                                                         //
  /////////////////////////////////////////////////////////////////////////////

  template <class coord_T>
  coord_T neatSum(const vector<coord_T>& v) {
    coord_T d = 0;
    int n = (int)v.size();
    for(int i = 1; i < n; i++) {
      d += i*(n-i)*(v[i]-v[i-1]);
    }
    return d;
  }
}
