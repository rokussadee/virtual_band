//
// Created by Admin on 28/04/2024.
//
#ifndef VIRTUAL_BAND_MIDIPROCESSOR_H
#define VIRTUAL_BAND_MIDIPROCESSOR_H

#pragma once

#include <JuceHeader.h>

#include "MidiQueue.h"
#include "MidiListModel.h"
#include "MidiTable.h"

class MidiProcessor {
public:
  MidiProcessor();
  ~MidiProcessor();
  void processMidi(MidiBuffer& midiMessages);

private:
  MidiQueue midiQueue;
  MidiListModel midiListModel;
};

#endif  // VIRTUAL_BAND_MIDIPROCESSOR_H
