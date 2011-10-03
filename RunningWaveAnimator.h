/*********************************************************************
 *
 *  File Name: RunningWaveAnimator.cpp
 *
 *  Description: Gradually changes color one light at a time
 *              iterating through mutliple colors
 *
 *  Date Created: Sep 20, 2011
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
#ifndef __GE_CE_LIGHTS_RUNNING_WAVE_ANIMATOR_H__
#define __GE_CE_LIGHTS_RUNNING_WAVE_ANIMATOR_H__

#include <WProgram.h>

#include <Color.h>
#include <Light.h>
#include <TrackAnimator.h>

#include "ColorCycle.h"
#include "StepAnimator.h"

namespace ESoft {
  
  namespace GECELights {
    
    using GECEWriter::Light;
    using GECEWriter::Color;
    
    template <class RUNNING, typename T = bool>
    class RunningWaveAnimator : public GECEWriter::TrackAnimator {
    public:
      RunningWaveAnimator(uint8_t track, uint8_t lightCount, ColorCycle cycle,
            uint8_t brightness, uint8_t step, 
            const T &param1 = false, unsigned int param2 = 0,
            unsigned int delay = 0)
        : TrackAnimator(track, lightCount), cycle_(cycle),
            brightness_(brightness), step_(step), 
            param1_(param1), param2_(param2), delay_(delay),
            animator_(new GECEWriter::StepAnimator(track, lightCount, 
              new RUNNING(brightness, step, cycle.getCurColor(), cycle.getNewColor(),
                param1, param2), delay)) {}
      ~RunningWaveAnimator() { delete animator_; }

      bool isDone() { return cycle_.isCycleDone(); }

    protected:
      Light getLight_() {
        Light light = animator_->getLight();

        if (animator_->isDone() && !(++cycle_).isCycleDone()) {
          delete animator_;
          animator_ = new GECEWriter::StepAnimator(track_, lightCount_, 
            new RUNNING(brightness_, step_, 
              cycle_.getCurColor(), cycle_.getNewColor(), param1_, param2_), delay_);
        }
            
        return light;
      }

    private:
      ColorCycle cycle_;
      TrackAnimator *animator_;
      uint8_t brightness_, step_;
      const T &param1_;
      unsigned int delay_, param2_;
  
    };
    
  }
}

#endif //__GE_CE_LIGHTS_RUNNING_WAVE_ANIMATOR_H__


