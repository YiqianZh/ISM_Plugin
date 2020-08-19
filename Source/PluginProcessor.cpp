/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Ism_pluginAudioProcessor::Ism_pluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    
    nSampleRate = 48000;
    
}





Ism_pluginAudioProcessor::~Ism_pluginAudioProcessor()
{
}

//==============================================================================
const String Ism_pluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Ism_pluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Ism_pluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Ism_pluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Ism_pluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Ism_pluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Ism_pluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Ism_pluginAudioProcessor::setCurrentProgram (int index)
{
}

const String Ism_pluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void Ism_pluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Ism_pluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    dsp::ProcessSpec spec;
    //spec.sampleRate = sampleRate;
    //spec.maximumBlockSize = samplesPerBlock;
    //spec.numChannels = getTotalNumInputChannels();
    
    //nNumInputs = getTotalNumInputChannels();
    //nNumOutputs = getTotalNumOutputChannels();
   // nSampleRate = (int)(sampleRate + 0.5);
   // isPlaying = false;
   // convolution.loadImpulseResponse(<#const void *sourceData#>, <#size_t sourceDataSize#>, <#bool wantsStereo#>, <#bool wantsTrimming#>, <#size_t size#>);
    
    //convolution.loadImpulseResponse(ir_output, ir_output.size(), false, false, 0);
    sampleRate = spec.sampleRate;
    convolution.prepare(spec);
    updateParameters();
    

    //convolution.loadImpulseResponse(<#const File &fileImpulseResponse#>, <#bool wantsStereo#>, <#bool wantsTrimming#>, <#size_t size#>)
    



    
    
    
    
}

void Ism_pluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Ism_pluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Ism_pluginAudioProcessor::updateParameters(){
    
    // update your parameters for your processes here
}


void Ism_pluginAudioProcessor::process(dsp::ProcessContextReplacing<float>context){
    
    // do processing here and output
    
   // convolution.loadImpulseResponse(ir_output, ir_output.size(), false, false, 0);
    
}

void Ism_pluginAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    //rawVolume = 0.015;
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    dsp::AudioBlock <float> block (buffer);
    process(dsp::ProcessContextReplacing<float> (block));
    

    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
/*    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);
        for(int sample = 0; sample<buffer.getNumSamples(); ++sample)
        {
            channelData[sample] = buffer.getSample(channel, sample) * rawVolume;
            
        }

        // ..do something to the data...
    }
 */
    
}

//==============================================================================
bool Ism_pluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Ism_pluginAudioProcessor::createEditor()
{
    return new Ism_pluginAudioProcessorEditor (*this);
}

//==============================================================================
void Ism_pluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Ism_pluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Ism_pluginAudioProcessor();
}
