// This file is part of XmlPlus package
// 
// Copyright (C)   2010   Satya Prakash Tripathi
//
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __XPLUS_STRINGUTILS_H__ 
#define __XPLUS_STRINGUTILS_H__

#include <sstream>
#include <string>
#include <iostream>

#include "XPlus/Exception.h"

using namespace std;

namespace XPlus
{
  template <class T> string toString (const T & t)
  {
    string result;
    ostringstream oss;
    oss << t;
    if (!oss) {
      throw StringException("toString failed");
    }
    return oss.str();
  }

  template <class T> T fromString(const string& s)
  {
    T result;
    istringstream iss (s);
    if (iss >> result)
      return result;
      
      
    throw StringException(string("fromString failed. string:[") + s + "]");
  }

}
#endif
