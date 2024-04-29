//
// Created by Admin on 29/04/2024.
//
#include "VirtualBand/MidiQueue.h"

MidiQueue::MidiQueue() {}
MidiQueue::~MidiQueue() {}

void MidiQueue::push(const MidiMessage& message) {
  int size1, start1, size2, start2;
  fifo.prepareToWrite(1, start1, size1, start2, size2);
  if (size1 > 0)
    messages[start1] = message;
  if (size2 > 0)
    messages[start2] = message;
  fifo.finishedWrite(size1 + size2);
}

template <typename OutputIt>
void MidiQueue::pop(OutputIt out) {
  int size1, start1, size2, start2;
  fifo.prepareToRead(fifo.getNumReady(), start1, size1, start2, size2);
  for (int i = start1; i < start1 + size1; i++)
    *out++ = messages[i];
  for (int i = start2; i < start2 + size2; i++)
    *out++ = messages[i];
  fifo.finishedRead(size1 + size2);
}
template void
    MidiQueue::pop<std::back_insert_iterator<std::vector<MidiMessage>>>(
        std::back_insert_iterator<std::vector<MidiMessage>>);