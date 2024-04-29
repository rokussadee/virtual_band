//
// Created by Admin on 29/04/2024.
//
#include "VirtualBand/MidiListModel.h"

MidiListModel::MidiListModel() = default;

MidiListModel::~MidiListModel() = default;

void MidiListModel::addMessages(const MidiMessageSequence& sequence) {
  const auto numNewMessages = sequence.getNumEvents();
  const auto numToAdd = juce::jmin(numToStore, numNewMessages);
  const auto numToRemove =
      jmax(0, (int)messages.size() + numToAdd - numToStore);

  messages.erase(messages.begin(), std::next(messages.begin(), numToRemove));
  for (int i = 0; i < numToAdd; ++i)
    messages.push_back(sequence.getEventPointer(i)->message);

  if (onChange)
    onChange();
}

void MidiListModel::clear() {
  messages.clear();
  if (onChange)
    onChange();
}

size_t MidiListModel::size() const {
  return messages.size();
}

const MidiMessage& MidiListModel::operator[](size_t ind) const {
  return messages[ind];
}
