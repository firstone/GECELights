/*********************************************************************
 *
 *  File Name: ColorCycle.cpp
 *
 *  Description: Cycles through array of colors
 *
 *  Date Created: Sep 25, 2011
 * 
 *  Revision History:
 *  
 *  NNN - MMM YY - Name - Change
 *  
 *  Copyright (C) 2011, Erissoft
 *  
 *  This file is part of Erissoft GE CE Lights Controller
 *
 *  GE CE Lights Controller is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *  
 *********************************************************************/
#include "ColorCycle.h"

namespace ESoft {
  
  namespace GECELights {
    
    ColorCycle::ColorCycle(int colorCount, Color colors[])
      : colorCount_(colorCount), colors_(colors),
        curColor_(0), cycleDone_(false) {}
        
    ColorCycle::ColorCycle(const ColorCycle &cycle) 
      : colorCount_(cycle.colorCount_), colors_(cycle.colors_),
        curColor_(cycle.curColor_), cycleDone_(cycle.cycleDone_) {}
        
    ColorCycle &ColorCycle::operator++() {
      curColor_++;
      if (curColor_ == colorCount_) {
        cycleDone_ = true;
        curColor_ = 0;
      } else
        cycleDone_ = false;
    
      return *this;
    }
  
    ColorCycle ColorCycle::operator++(int) {
      ColorCycle old(*this);
    
      ++(*this);
    
      return old;
    }
    
  }
}

