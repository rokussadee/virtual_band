//
// Created by Admin on 28/04/2024.
//

#ifndef VIRTUAL_BAND_MIDITABLE_H
#define VIRTUAL_BAND_MIDITABLE_H

#pragma once

#include <JuceHeader.h>

#include "MidiListModel.h"

class MidiTable final : public Component, private TableListBoxModel {
public:
  explicit MidiTable(MidiListModel& m);
  ~MidiTable() override;

  void paintRowBackground(juce::Graphics& g,
                          int rowNumber,
                          int width,
                          int height,
                          bool rowIsSelected) override;
  void paintCell(juce::Graphics& g,
                 int rowNumber,
                 int columnId,
                 int width,
                 int height,
                 bool rowIsSelected) override;
  int getNumRows() override;
  juce::String getColumnText(const int row, const int columnId) const;

private:
  enum ColumnIDs { messageColumn = 1, timeColumn, channelColumn, dataColumn };

  MidiListModel& messages;
  TableListBox table;
};

#endif  // VIRTUAL_BAND_MIDITABLE_H
