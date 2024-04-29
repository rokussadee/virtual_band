//
// Created by Admin on 29/04/2024.
//

#ifndef VIRTUAL_BAND_VIRTUALBANDPLUGINPROCESSOR_H
#define VIRTUAL_BAND_VIRTUALBANDPLUGINPROCESSOR_H

#include <JuceHeader.h>

#include "PluginProcessor.h"

class VirtualBandPluginProcessor {
public:
  VirtualBandPluginProcessor();
  ~VirtualBandPluginProcessor();

  void processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages) {
    buffer.clear();
    midiProcessor.processMidi(midiMessages);
  }

private:
  MidiProcessor midiProcessor;
};

#endif  // VIRTUAL_BAND_VIRTUALBANDPLUGINPROCESSOR_H
