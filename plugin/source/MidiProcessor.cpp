//
// Created by Admin on 29/04/2024.
//

#include "VirtualBand/MidiProcessor.h"

MidiProcessor::MidiProcessor() {}

MidiProcessor::~MidiProcessor() {}

void MidiProcessor::processMidi(juce::MidiBuffer& midiMessages) {
  MidiMessageSequence sequence;

  for (const MidiMessageMetadata metadata : midiMessages) {
    const MidiMessage message = metadata.getMessage();

    const String description = message.getDescription();

    DBG(description);

    midiQueue.push(message);
    sequence.addEvent(message, metadata.samplePosition);
  }

  std::vector<MidiMessage> messages;
  midiQueue.pop(std::back_inserter(messages));
  midiListModel.addMessages(sequence);
}
