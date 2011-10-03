/*********************************************************************
 *
 *  File Name: StaticColorAnimator.cpp
 *
 *  Description: Static color animator adapter to run 
 *               with RunningWaveAnimator
 *
 *  Date Created: Sep 26, 2011
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
#ifndef __GE_CE_LIGHTS_STATIC_COLOR_ANIMATOR_H__
#define __GE_CE_LIGHTS_STATIC_COLOR_ANIMATOR_H__

#include <WProgram.h>

#include <Color.h>
#include <StaticColorAnimator.h>

namespace ESoft {
  
  namespace GECELights {
    
    using GECEWriter::Color;
    
    class StaticColorAnimator : public GECEWriter::StaticColorAnimator {
    public:
      StaticColorAnimator(uint8_t brightness, uint8_t step, 
            const Color &dummy, const Color &color, 
            bool dummy2 = false, unsigned int dummy3 = 0)
        : GECEWriter::StaticColorAnimator(brightness, color) {}
    };
    
  }
}

#endif //__GE_CE_LIGHTS_STATIC_COLOR_ANIMATOR_H__


