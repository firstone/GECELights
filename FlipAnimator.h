/*********************************************************************
 *
 *  File Name: FlipAnimator.cpp
 *
 *  Description: Fades to color through an intermediate color
 *               with a delay in the middle
 *
 *  Date Created: Sep 24, 2011
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
#ifndef __GE_CE_LIGHTS_FLIP_ANIMATOR_H__
#define __GE_CE_LIGHTS_FLIP_ANIMATOR_H__

#include <WProgram.h>

#include <Color.h>
#include <Light.h>
#include <MultiAnimator.h>
#include <SleepAnimator.h>

#include "FadeToColorAnimator.h"

namespace ESoft {
  
  namespace GECELights {
    
    using GECEWriter::Color;
    
    class FlipAnimator : public GECEWriter::MultiAnimator {
    public:
      FlipAnimator(uint8_t brightness, uint8_t step, 
            const Color &curColor, const Color &newColor, const Color &flipColor,
            unsigned int sleep)
        : MultiAnimator(3) {
        addAnimator(new FadeToColorAnimator(brightness, step, curColor, flipColor));
        addAnimator(new GECEWriter::SleepAnimator(sleep));
        addAnimator(new FadeToColorAnimator(brightness, step, flipColor, newColor));
      }  
    };
    
  }
}

#endif //__GE_CE_LIGHTS_FLIP_ANIMATOR_H__


