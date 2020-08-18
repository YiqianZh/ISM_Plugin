/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include <time.h>
#include <iostream>
#include <thread>
#include <string.h>
#include <chrono>

typedef enum _SPARTA_WARNINGS{
    k_warning_none,
    k_warning_frameSize,
    k_warning_supported_fs,
    k_warning_mismatch_fs,
    k_warning_osc_connection_fail,
    k_warning_NinputCH,
    k_warning_NoutputCH
}SPARTA_WARNINGS;
//==============================================================================
/**
*/
class Ism_pluginAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Slider::Listener,
                                        public Button::Listener,
                                        public Timer
//,
{
public:
    Ism_pluginAudioProcessorEditor (Ism_pluginAudioProcessor&);
    ~Ism_pluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider *slider) override;
    void buttonClicked (Button *button) override;
    void buttonStateChanged (Button *) override;
    std::vector<double> ISM_Simulation();
    void play();
    void stop();
    void timerCallback() override;
   // void buttonClicked (Button* buttonThatWasClicked) override;
    
    
    
    

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    
    
    Ism_pluginAudioProcessor& processor;
    Slider gainSlider;
    
    Slider roomLength;
    Slider roomWidth;
    Slider roomHeight;
       
    Slider roomAbsorption_1,roomAbsorption_2,roomAbsorption_3,roomAbsorption_4,roomAbsorption_5,roomAbsorption_6;
    Slider Image_source;
       
    TextEditor Source_Editor_x,Source_Editor_y,Source_Editor_z;
    TextEditor Receiver_Editor_x, Receiver_Editor_y, Receiver_Editor_z;

    ToggleButton am_1st, am_2nd, am_3rd;
    
    Label Room_Setting,roomWidth_label,roomLength_label,roomHeight_label, roomAbsorption_label, Image_Source_label, Source_label, Receiver_label,roomAbsorption_2_label,roomAbsorption_3_label,roomAbsorption_4_label,roomAbsorption_5_label,roomAbsorption_6_label, Am_Order;
    
    //TextButton output_am{"Run Start"};
    
    
    enum class PlayState{
        
        Play,
        Stop
    };
    
    PlayState playState{ PlayState::Stop};
    TextButton output_am{"Stop"};


    int am_id = 1;
    
    ToggleButton t_flipPitch;

    SPARTA_WARNINGS currentWarning;
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Ism_pluginAudioProcessorEditor)
};
