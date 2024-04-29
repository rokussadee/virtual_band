//
// Created by Admin on 28/04/2024.
//

#ifndef VIRTUAL_BAND_MIDIQUEUE_H
#define VIRTUAL_BAND_MIDIQUEUE_H
#pragma once

#include <vector>

#include <JuceHeader.h>

class MidiQueue {
public:
  MidiQueue();
  ~MidiQueue();

  void push(const MidiMessage& message);
  template <typename OutputIt>
  void pop(OutputIt out);

private:
  static constexpr auto queueSize = 1024;
  AbstractFifo fifo{queueSize};
  std::vector<MidiMessage> messages;
};

#endif  // VIRTUAL_BAND_MIDIQUEUE_H
