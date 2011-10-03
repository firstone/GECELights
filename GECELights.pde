/*********************************************************************
 *
 *  File Name: GECELights.pde
 *
 *  Description: GE Color Effects lights controller main file
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
#include <AnimationExecutor.h>
#include <Color.h>
#include <CppDefs.h>
#include <RainbowAnimator.h>
#include <StringAnimator.h>

#include "ColorCycle.h"
#include "ColorCycleAnimator.h"
#include "FlipAnimator.h"
#include "RunningWaveAnimator.h"
#include "StaticColorAnimator.h"
#include "SyncAnimator.h"

using namespace ESoft::GECEWriter;
using namespace ESoft::GECELights;

const uint8_t TRACK_COUNT = 1;
const uint8_t TRACK = 5;
const uint8_t LIGHT_COUNT = 50;
const uint8_t MAX_BRIGHTNESS = 0xCC;

void setup() { 
  Serial.begin(9600);
  Writer::initialize(TRACK, LIGHT_COUNT, MAX_BRIGHTNESS, true);
}


void loop() {
  
  /*
  {
    StepAnimator animator(3, LIGHT_COUNT, new ESoft::GECEWriter::StaticColorAnimator(MAX_BRIGHTNESS, Color::RED), 30);
  
    TrackAnimator *list[] = { &animator };
    AnimationExecutor exec(1, list);
    exec.animate();
    
  }
  */
  
  {
    MultiAnimator *multi = new MultiAnimator(3);
    multi->addAnimator(new RainbowAnimator(MAX_BRIGHTNESS));
    multi->addAnimator(new RainbowAnimator(MAX_BRIGHTNESS, 0, 1, true));
    multi->addAnimator(new ESoft::GECEWriter::StaticColorAnimator(MAX_BRIGHTNESS, Color::BLACK));
    
    StringAnimator animator(TRACK, LIGHT_COUNT, multi);
  
    TrackAnimator *list[] = { &animator };
    AnimationExecutor exec(1, list);
    exec.animate();
    
  }
  
  {
    Color colors[] = { Color::RED, Color::YELLOW, Color::GREEN, Color::CYAN, Color::BLUE, Color::VIOLET, Color::BLACK };
    RunningWaveAnimator<FlipAnimator, Color> animator(TRACK, LIGHT_COUNT, ColorCycle(7, colors), MAX_BRIGHTNESS, 6, Color::WHITE, 100);
    //RunningWaveAnimator<FadeToColorAnimator> animator(TRACK, LIGHT_COUNT, ColorCycle(7, colors), MAX_BRIGHTNESS, 6);
    //RunningWaveAnimator<ESoft::GECELights::StaticColorAnimator> animator(TRACK, LIGHT_COUNT, ColorCycle(7, colors), MAX_BRIGHTNESS, 6, false, 0, 30);

    TrackAnimator *list[] = { &animator };
    AnimationExecutor exec(1, list);
    exec.animate();

  }

  {  
    Color two[] = { Color::RED, Color::GREEN };
  
    for (int count = 1; count <= LIGHT_COUNT / 2; count++) {
      SyncAnimator animator(TRACK, LIGHT_COUNT, new ColorCycleAnimator(ColorCycle(2, two), MAX_BRIGHTNESS, count));
    
      TrackAnimator *list[] = { &animator };
      AnimationExecutor exec(1, list);
      exec.animate();

      delay(300);
    }  
    
    delay(1000);
  }
  
  {
 
    Color fullColors[] = { Color::RED, Color::YELLOW, Color::GREEN, Color::CYAN, Color::BLUE, Color::VIOLET, Color::WHITE };
    SyncAnimator animator(TRACK, LIGHT_COUNT, new ColorCycleAnimator(ColorCycle(7, fullColors), MAX_BRIGHTNESS, 1));

    TrackAnimator *list[] = { &animator };
    AnimationExecutor exec(1, list);
    exec.animate();
  }
  
  delay(5000);
  
}

