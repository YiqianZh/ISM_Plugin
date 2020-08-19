/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <string.h>

#include <iostream>
#include <thread>
#include <string.h>
#include <chrono>
//#include "multiconv.h"
//==============================================================================
/**
*/
class Ism_pluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Ism_pluginAudioProcessor();
    ~Ism_pluginAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    
    
    
    std::vector<double> ir_output;
    double rawVolume;
   
    
    void process(dsp::ProcessContextReplacing<float>context);
    void updateParameters();
    
    int getCurrentNumInputs(){ return nNumInputs; }
    int getCurrentNumOutputs(){ return nNumOutputs; }
    AudioBuffer<float> buf;

private:
    
    //Slider gainSlider;
    int nNumInputs;         /* current number of input channels */
    int nNumOutputs;        /* current number of output channels */
    int nSampleRate;        /* current host sample rate */
    bool isPlaying;
    
    dsp::Convolution convolution;
    
    //AudioBuffer<float> buf;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Ism_pluginAudioProcessor)
};
