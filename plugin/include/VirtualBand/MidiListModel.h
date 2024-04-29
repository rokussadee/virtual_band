//
// Created by Admin on 28/04/2024.
//

#ifndef VIRTUAL_BAND_MIDILISTMODEL_H
#define VIRTUAL_BAND_MIDILISTMODEL_H

#pragma once

#include <JuceHeader.h>

#include <vector>

class MidiListModel {
public:
  MidiListModel();
  ~MidiListModel();
  void addMessages(const juce::MidiMessageSequence& sequence);

  void clear();

  const MidiMessage& operator[](size_t ind) const;

  size_t size() const;

  std::function<void()> onChange;

private:
  static constexpr auto numToStore = 1000;
  std::vector<MidiMessage> messages;
};

#endif  // VIRTUAL_BAND_MIDILISTMODEL_H
