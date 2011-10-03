/*********************************************************************
 *
 *  File Name: ColorCycleAnimator.cpp
 *
 *  Description: Color array animator
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
#include "ColorCycleAnimator.h"

namespace ESoft {
  
  namespace GECELights {
    
    ColorCycleAnimator::ColorCycleAnimator(ColorCycle cycle, uint8_t brightness, 
        int lightCount) 
      : cycle_(cycle), lightCount_(lightCount), curCount_(0),
        brightness_(brightness) {}

    void ColorCycleAnimator::reset() {
      LightAnimator::reset();
      cycle_.reset();
      curCount_ = 0;
    }

    Light ColorCycleAnimator::getLight_() {
      Light light;
      light.setColor(cycle_.getNewColor()).setBrightness(brightness_);
        
      if (++curCount_ >= lightCount_) {
        curCount_ = 0;
        ++cycle_;
      }
        
      return light;
    }
    
  }
}

