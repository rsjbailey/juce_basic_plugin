//
// Created by Richard Bailey on 25/11/2022.
//

#include "processor.hpp"
extern "C" {
  #include "mylib/mylib.h"
}

using namespace juce;

// Calling our get_value function in the external c lib to set the default gain.
Processor::Processor()
    : AudioProcessor (BusesProperties().withInput  ("Input",  AudioChannelSet::stereo())
                          .withOutput ("Output", AudioChannelSet::stereo())) {
  addParameter(
      gain = new AudioParameterFloat({"gain", 1}, "Gain", 0.0f, 1.0f, get_value()));
}

void Processor::prepareToPlay(double, int) {}
void Processor::releaseResources() {}

void Processor::processBlock(AudioBuffer<float> &buffer, MidiBuffer &) {
  buffer.applyGain (*gain);
}
void Processor::processBlock(AudioBuffer<double> &buffer, MidiBuffer &) {
  buffer.applyGain ((float) *gain);
}

juce::AudioProcessorEditor *Processor::createEditor() { return new juce::GenericAudioProcessorEditor (*this); }
bool Processor::hasEditor() const { return true;   }

const juce::String Processor::getName() const { return "Example Plugin"; }
bool Processor::acceptsMidi() const { return false; }
bool Processor::producesMidi() const { return false; }

double Processor::getTailLengthSeconds() const { return 0; }

int Processor::getNumPrograms() { return 1; }
int Processor::getCurrentProgram() { return 0; }
void Processor::setCurrentProgram(int) {}
const juce::String Processor::getProgramName(int) { return "None"; }

void Processor::changeProgramName(int, const String &) {}
void Processor::getStateInformation(MemoryBlock &destData) {
  juce::MemoryOutputStream (destData, true).writeFloat (*gain);
}
void Processor::setStateInformation(const void *data, int sizeInBytes) {
  gain->setValueNotifyingHost (juce::MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat());
}
bool Processor::isBusesLayoutSupported(
    const AudioProcessor::BusesLayout &layouts) const {
  const auto& mainInLayout  = layouts.getChannelSet (true,  0);
  const auto& mainOutLayout = layouts.getChannelSet (false, 0);

  return (mainInLayout == mainOutLayout && (! mainInLayout.isDisabled()));
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new Processor(); }