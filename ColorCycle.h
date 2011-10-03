/*********************************************************************
 *
 *  File Name: ColorCycle.h
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
#ifndef __GE_CE_LIGHTS_COLOR_CYCLE_H__
#define __GE_CE_LIGHTS_COLOR_CYCLE_H__

#include <Color.h>

namespace ESoft {
  
  namespace GECELights {
    
    using GECEWriter::Color;
    
    class ColorCycle {
    public:
      ColorCycle(int colorCount, Color colors[]);
      ColorCycle(const ColorCycle &cycle);
      
      void reset() { 
        cycleDone_ = false;
        curColor_ = 0;
      }
      
      const Color &getNewColor() { return colors_[curColor_]; }
      const Color &getCurColor() { 
        return curColor_ == 0 
          ? colors_[colorCount_ - 1] 
          : colors_[curColor_ - 1]; 
      }
      
      bool isCycleDone() { return cycleDone_; }
  
      ColorCycle &operator++();
      ColorCycle operator++(int);

    private:
      int colorCount_, curColor_;
      Color *colors_;
      bool cycleDone_;
  
    };
    
  }
}

#endif //__GE_CE_LIGHTS_COLOR_CYCLE_H__


