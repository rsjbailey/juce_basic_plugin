#include "juce_audio_processors/juce_audio_processors.h"

class Processor : public juce::AudioProcessor {
public:
  Processor();

  void prepareToPlay(double sampleRate,
                     int maximumExpectedSamplesPerBlock) override;
  void releaseResources() override;

  void processBlock(juce::AudioBuffer<float> &buffer,
                    juce::MidiBuffer &) override;
  void processBlock(juce::AudioBuffer<double> &buffer,
                    juce::MidiBuffer &) override;

  juce::AudioProcessorEditor *createEditor() override;
  bool hasEditor() const override;

  const juce::String getName() const override;
  bool acceptsMidi() const override;
  bool producesMidi() const override;
  double getTailLengthSeconds() const override;

  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram(int index) override;
  const juce::String getProgramName(int index) override;
  void changeProgramName(int index, const juce::String& newName) override;

  void getStateInformation(juce::MemoryBlock &destData) override;
  void setStateInformation(const void *data, int sizeInBytes) override;

  bool isBusesLayoutSupported(const BusesLayout &layouts) const override;

private:
  juce::AudioParameterFloat *gain;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Processor)
};
