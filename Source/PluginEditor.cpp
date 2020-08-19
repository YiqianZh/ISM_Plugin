/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;
//==============================================================================
Ism_pluginAudioProcessorEditor::Ism_pluginAudioProcessorEditor (Ism_pluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    setSize (656, 262);
    
    
    addAndMakeVisible(Room_Setting);
 //      Room_Setting.setText("Room Basic Setting", NotificationType::dontSendNotification);
       //Room_Setting.setFont(italic);
  /*
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow,true,100,25);
    gainSlider.setRange(0.0,1.0);
    gainSlider.setValue(0.5);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
 */
    
    addAndMakeVisible(roomLength);
    roomLength.setSliderStyle(Slider::LinearHorizontal);
    //roomLength.setTextBoxStyle(Slider::TextBoxLeft,true,50,20);
    roomLength.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    roomLength.setNumDecimalPlacesToDisplay(1);
    roomLength.setRange(0.0,50.0);
    roomLength.setValue(3);
   // roomLength_label.attachToComponent(&roomLength, true);

    addAndMakeVisible(roomWidth);
    roomWidth.setSliderStyle(Slider::LinearHorizontal);
    roomWidth.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    roomWidth.setNumDecimalPlacesToDisplay(1);
    roomWidth.setRange(0.0,50);
    roomWidth.setValue(8);
   // roomWidth_label.attachToComponent(&roomWidth, true);
    
    addAndMakeVisible(roomHeight);
    roomHeight.setSliderStyle(Slider::LinearHorizontal);
    roomHeight.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
    roomHeight.setNumDecimalPlacesToDisplay(1);
    roomHeight.setRange(0.0,50);
    roomHeight.setValue(5);
  //  roomHeight_label.attachToComponent(&roomHeight, true);
   
    addAndMakeVisible(roomAbsorption_1);
    roomAbsorption_1.setSliderStyle(Slider::Rotary);
    roomAbsorption_1.setTextBoxStyle(Slider::TextBoxBelow, false, 45, 15);
    //roomAbsorption_label.setText("Wall1", NotificationType::dontSendNotification);
    roomAbsorption_1.setRange(0,1);
    roomAbsorption_1.setValue(0.8);
    roomAbsorption_1.setNumDecimalPlacesToDisplay(1);

    roomAbsorption_label.attachToComponent(&roomAbsorption_1, true);
        
    addAndMakeVisible(roomAbsorption_2);
    roomAbsorption_2.setSliderStyle(Slider::Rotary);
    roomAbsorption_2.setTextBoxStyle(Slider::TextBoxBelow, false, 45, 15);
    roomAbsorption_2.setRange(0,1);
    roomAbsorption_2.setValue(0.8);
    //roomAbsorption_2_label.setText("Wall2", NotificationType::dontSendNotification);
    roomAbsorption_2.setNumDecimalPlacesToDisplay(1);
    roomAbsorption_2_label.attachToComponent(&roomAbsorption_2, true);
   
    
    addAndMakeVisible(roomAbsorption_3);
    roomAbsorption_3.setSliderStyle(Slider::Rotary);
    roomAbsorption_3.setTextBoxStyle(Slider::TextBoxBelow, false, 45, 15);
    roomAbsorption_3.setRange(0,1);
    roomAbsorption_3.setValue(0.8);
    roomAbsorption_3.setNumDecimalPlacesToDisplay(1);

   // roomAbsorption_3_label.setText("Wall1", NotificationType::dontSendNotification);
    roomAbsorption_3_label.attachToComponent(&roomAbsorption_3, true);
    
    addAndMakeVisible(roomAbsorption_4);
    roomAbsorption_4.setSliderStyle(Slider::Rotary);
    roomAbsorption_4.setTextBoxStyle(Slider::TextBoxBelow, false, 45, 15);
    roomAbsorption_4.setRange(0,1);
    roomAbsorption_4.setValue(0.8);
    roomAbsorption_4.setNumDecimalPlacesToDisplay(1);

  //  roomAbsorption_4_label.setText("Wall1", NotificationType::dontSendNotification);
    roomAbsorption_4_label.attachToComponent(&roomAbsorption_4, true);
    
    addAndMakeVisible(roomAbsorption_5);
    roomAbsorption_5.setSliderStyle(Slider::Rotary);
    roomAbsorption_5.setTextBoxStyle(Slider::TextBoxBelow, false, 45, 15);
    roomAbsorption_5.setRange(0,1);
    roomAbsorption_5.setValue(0.8);
    roomAbsorption_5.setNumDecimalPlacesToDisplay(1);

  //  roomAbsorption_5_label.setText("Wall1", NotificationType::dontSendNotification);
    roomAbsorption_5_label.attachToComponent(&roomAbsorption_5, true);
    
    addAndMakeVisible(roomAbsorption_6);
    roomAbsorption_6.setSliderStyle(Slider::Rotary);
    roomAbsorption_6.setTextBoxStyle(Slider::TextBoxBelow, false, 45, 15);
    roomAbsorption_6.setRange(0,1);
    roomAbsorption_6.setValue(0.8);
    roomAbsorption_6.setNumDecimalPlacesToDisplay(1);

      //roomAbsorption_6_label.setText("Wall1", NotificationType::dontSendNotification);
    roomAbsorption_6_label.attachToComponent(&roomAbsorption_6, true);
    
    //addAndMakeVisible(Source_label);
    //Source_label.setText("Source Position", NotificationType::dontSendNotification);

    addAndMakeVisible(Source_Editor_x);
    Source_Editor_x.setText("x");
    
    addAndMakeVisible(Source_Editor_y);
    Source_Editor_y.setText("y");
    
    addAndMakeVisible(Source_Editor_z);
    Source_Editor_z.setText("z");
    
   // addAndMakeVisible(Receiver_label);
   // Receiver_label.setText("Receiver Position", NotificationType::dontSendNotification);
    
    addAndMakeVisible(Receiver_Editor_x);
    Receiver_Editor_x.setText("x");
    
    addAndMakeVisible(Receiver_Editor_y);
    Receiver_Editor_y.setText("y");
    
    addAndMakeVisible(Receiver_Editor_z);
    Receiver_Editor_z.setText("z");
    
    
    
    addAndMakeVisible(Image_source);
    Image_source.setSliderStyle(Slider::IncDecButtons);
    Image_source.setRange(0,10);
    Image_source.setValue(1);
    Image_source.setTextBoxStyle(Slider::TextBoxLeft, false, 50, 30);
    Image_source.setNumDecimalPlacesToDisplay(0);
    Image_source.setIncDecButtonsMode(Slider::incDecButtonsDraggable_Vertical);

   // Image_Source_label.setText("Image Source Level", NotificationType::dontSendNotification);
   // Image_Source_label.attachToComponent(&Image_source, true);
    /*
    addAndMakeVisible(Am_Order);
    Am_Order.setText("Choose Order", NotificationType::dontSendNotification);
    */
    
    //addAndMakeVisible(t_flipPitch);
    //t_flipPitch.setButtonText(<#const String &newText#>)
    

    
    addAndMakeVisible(am_1st);
    addAndMakeVisible(am_2nd);
    addAndMakeVisible(am_3rd);
    am_1st.setButtonText("1 - Order");
    am_2nd.setButtonText("2 - Order");
    am_3rd.setButtonText("3 - Order");
    am_1st.setRadioGroupId(am_id);
    am_2nd.setRadioGroupId(am_id);
    am_3rd.setRadioGroupId(am_id);
    
    addAndMakeVisible(output_am);
    output_am.setToggleState(true, NotificationType::dontSendNotification);
    output_am.onClick = [this]() {};
    output_am.addListener(this);

     

}

Ism_pluginAudioProcessorEditor::~Ism_pluginAudioProcessorEditor()
{
}

//==============================================================================
void Ism_pluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll(Colours::white);  // background whole black
    {
       int x = 0, y = 146, width = 656, height = 116;
        Colour fillColour1 = Colour (0xff1c3949), fillColour2 = Colour (0xff071e22);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       8.0f - 0.0f + x,
                                       264.0f - 146.0f + y,
                                       fillColour2,
                                       8.0f - 0.0f + x,
                                       192.0f - 146.0f + y,
                                       false));
        g.fillRect (x, y, width, height);
    }
    
    {  // background  main blue
        int x = 0, y = 30, width = 656, height = 116;
        Colour fillColour1 = Colour (0xff1c3949), fillColour2 = Colour (0xff071e22);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       8.0f - 0.0f + x,
                                       32.0f - 30.0f + y,
                                       fillColour2,
                                       8.0f - 0.0f + x,
                                       104.0f - 30.0f + y,
                                       false));
        g.fillRect (x, y, width, height);
    }
    
    { // top frame blue
        float x = 1.0f, y = 2.0f, width = 654.0f, height = 31.0f;
        Colour fillColour1 = Colour (0xff061c20), fillColour2 = Colour (0xff1c3949);
        Colour strokeColour = Colour (0xffb9b9b9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       0.0f - 1.0f + x,
                                       32.0f - 2.0f + y,
                                       fillColour2,
                                       656.0f - 1.0f + x,
                                       24.0f - 2.0f + y,
                                       false));
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 5.000f, 2.000f);
    }
    
     {
        int x = 12, y = 58, width = 226, height = 28;
        Colour fillColour = Colour (0x10f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }
    
     { //first rectangle
        int x = 12, y = 58, width = 226, height = 108;
        Colour fillColour = Colour (0x08f4f4f4);
        Colour strokeColour = Colour (0x35a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }
    
    
     {
        int x = 12, y = 166, width = 67, height = 85;
        Colour fillColour = Colour (0x10f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }
 /*
    {
          int x = 159, y = 166, width = 141, height = 28;
          String text (TRANS(" Wall Absorption Rate"));
          Colour fillColour = Colours::white;
          //[UserPaintCustomArguments] Customize the painting arguments here..
          //[/UserPaintCustomArguments]
          g.setColour (fillColour);
          g.setFont (Font (14.50f, Font::plain).withTypefaceStyle ("Bold"));
          g.drawText (text, x, y, width, height,
                      Justification::centredLeft, true);
      }
    */
    { //second rectangle
        int x = 12, y = 166, width = 434, height = 85;
        Colour fillColour = Colour (0x10f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }
 /*
     {
        int x = 12, y = 164, width = 73, height = 87;
        Colour fillColour = Colour (0x08f4f4f4);
        Colour strokeColour = Colour (0x3aa0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }
  */
    
     {
        int x = 238, y = 58, width = 208, height = 28;
        Colour fillColour = Colour (0x10f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }

   { // third rectangle
          int x = 238, y = 58, width = 208, height = 108;
          Colour fillColour = Colour (0x10f4f4f4);
          Colour strokeColour = Colour (0x67a0a0a0);
          //[UserPaintCustomArguments] Customize the painting arguments here..
          //[/UserPaintCustomArguments]
          g.setColour (fillColour);
          g.fillRect (x, y, width, height);
          g.setColour (strokeColour);
          g.drawRect (x, y, width, height, 1);

      }
    


    {   //Decoding Settings
        int x = 164, y = 32, width = 200, height = 30;
        String text (TRANS("Room Parameters Settings"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {  //output
        int x = 520, y = 32, width = 113, height = 30;
        String text (TRANS("Output"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }
    
    {
        int x = 459, y = 56, width = 165, height = 30;
        String text (TRANS("Choose Output IR Order:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 57, width = 141, height = 30;
        String text (TRANS("Room Size"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (14.50f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }
    
   
        
       roomLength.setBounds(85, 84, 150, 30);
       roomWidth.setBounds(85, 109, 150, 30);
       roomHeight.setBounds(85, 136, 150, 30);
  
    {
        int x = 19, y = 109, width = 132, height = 30;
        String text (TRANS("Width:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (14.50f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 136, width = 133, height = 30;
        String text (TRANS("Height:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 84, width = 125, height = 30;
        String text (TRANS("Length:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (14.50f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }
/*
    
    {
        int x = 125, y = 200, width = 63, height = 30;
        String text (TRANS("\\ypr[0]"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 223, y = 200, width = 63, height = 30;
        String text (TRANS("Ground"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 341, y = 200, width = 63, height = 30;
        String text (TRANS("Wall"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    
     {
        int x = 355, y = 225, width = 63, height = 24;
        String text (TRANS("+/-"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 240, y = 225, width = 63, height = 27;
        String text (TRANS("+/-"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 109, y = 225, width = 63, height = 27;
        String text (TRANS("+/-"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 93, y = 200, width = 60, height = 30;
        String text (TRANS("Ceilling"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 261, y = 200, width = 63, height = 30;
        String text (TRANS("Ground"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
*/
    {
        int x = 78, y = 205, width = 63, height = 30;
        String text (TRANS("Ceilling"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (8.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
    
    {
        int x = 143, y = 205, width = 63, height = 30;
        String text (TRANS("Ground"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (8.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
    
    {
        int x = 198, y = 205, width = 63, height = 30;
        String text (TRANS("Wall1"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (8.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
    
    {
        int x = 260, y = 205, width = 63, height = 30;
        String text (TRANS("Wall2"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (8.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
    
    {
        int x = 317, y = 205, width = 63, height = 30;
        String text (TRANS("Wall3"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (8.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
    
    {
        int x = 377, y = 205, width = 63, height = 30;
        String text (TRANS("Wall4"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (8.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }
    
    

    { // fourth rectangle
        int x = 446, y = 58, width = 196, height = 150;
        Colour fillColour = Colour (0x10f4f4f4);
        Colour strokeColour = Colour (0x67a0a0a0);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 1);

    }
    // 58 111
     { //below
         int x = 446, y = 208, width = 196, height = 43;
         Colour fillColour = Colour (0x10f4f4f4);
         Colour strokeColour = Colour (0x67a0a0a0);
         //[UserPaintCustomArguments] Customize the painting arguments here..
         //[/UserPaintCustomArguments]
         g.setColour (fillColour);
         g.fillRect (x, y, width, height);
         g.setColour (strokeColour);
         g.drawRect (x, y, width, height, 1);

     }
/*
    {
        int x = 457, y = 94, width = 132, height = 30;
        String text (TRANS("N dirs:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 457, y = 126, width = 132, height = 30;
        String text (TRANS("HRIR len:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 457, y = 157, width = 132, height = 30;
        String text (TRANS("HRIR fs:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 457, y = 213, width = 132, height = 30;
        String text (TRANS("DAW fs:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }
*/
   

    {
        int x = 659, y = -15, width = 80, height = 30;
        String text (TRANS("Comp. EQ:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }



    {
        int x = 19, y = 175, width = 61, height = 23;
        String text (TRANS("Wall"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 19, y = 197, width = 63, height = 23;
        String text (TRANS("Absorption"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }
    
    {
           int x = 19, y = 217, width = 63, height = 23;
           String text (TRANS("Rates"));
           Colour fillColour = Colours::white;
           //[UserPaintCustomArguments] Customize the painting arguments here..
           //[/UserPaintCustomArguments]
           g.setColour (fillColour);
           g.setFont (Font (11.00f, Font::plain).withTypefaceStyle ("Bold"));
           g.drawText (text, x, y, width, height,
                       Justification::centredLeft, true);
       }
    
    {
        int x = 16, y = 1, width = 196, height = 32;
        String text (TRANS("ISM Simulation|"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (18.80f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 145, y = 1, width = 184, height = 32;
        String text (TRANS("Ambisonics"));
        Colour fillColour = Colour (0xffdf8400);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (18.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 255, y = 57, width = 185, height = 30;
        String text (TRANS("ISM Parameters"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (14.50f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 255, y = 84, width = 185, height = 30;
        String text (TRANS("Source Position:"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (13.50f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 255, y = 109, width = 185, height = 30;
        String text (TRANS("Receiver Position: "));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (13.50f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }
    
    {
        int x = 255, y = 136, width = 185, height = 30;
        String text (TRANS("Image Level: "));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (13.50f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 0, y = 0, width = 656, height = 2;
        Colour strokeColour = Colour (0xffb9b9b9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = 654, y = 0, width = 2, height = 262;
        Colour strokeColour = Colour (0xffb9b9b9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = 0, y = 0, width = 2, height = 262;
        Colour strokeColour = Colour (0xffb9b9b9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }

    {
        int x = 0, y = 260, width = 656, height = 2;
        Colour strokeColour = Colour (0xffb9b9b9);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 2);

    }
 
    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}





void Ism_pluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(getLocalBounds());
    
    Room_Setting.setBounds(10, 15, 180, 20);
    roomLength.setBounds(90,50,170,20);
    roomWidth.setBounds(90,80,170,20);
    roomHeight.setBounds(90,110,170,20);
    

    roomAbsorption_1.setBounds(70,165,80,80);
    roomAbsorption_2.setBounds(130,165,80,80);
    roomAbsorption_3.setBounds(190,165,80,80);
    roomAbsorption_4.setBounds(250,165,80,80);
    roomAbsorption_5.setBounds(310,165,80,80);
    roomAbsorption_6.setBounds(370,165,80,80);

    
    //Source_label.setBounds(10, 240, 180, 20);
    Source_Editor_x.setBounds(370,88,17,17);
    Source_Editor_y.setBounds(385,88,17,17);
    Source_Editor_z.setBounds(400,88,17,17);
    
  //  Receiver_label.setBounds(10, 280, 180, 20);
    Receiver_Editor_x.setBounds(370,115,17,17);
    Receiver_Editor_y.setBounds(385,115,17,17);
    Receiver_Editor_z.setBounds(400,115,17,17);
    
    //Image_Source_label.setBounds(10, 300, 180, 20);
    Image_source.setBounds(345, 142, 90, 20);
    //roomAbsorption_label.setBounds(80, 130, 120, 20);
    //group_ambisonics.setBounds(120, 450, 130, 20);
    Am_Order.setBounds(10, 420, 180, 20);


    
    //x = 457, y = 94, width = 132, height = 30;
    am_1st.setBounds (457, 94, 132, 30);
    am_2nd.setBounds (457, 126, 132, 30);
    am_3rd.setBounds (457, 157, 132, 30);
    //MfileChooser.setBounds (458, 86, 174, 20);
    output_am.setBounds (476, 213, 132, 30);
    //int x = 457, y = 213, width = 132, height = 30;
    
    
}


void Ism_pluginAudioProcessorEditor::sliderValueChanged(Slider *slider){
    if (slider == &gainSlider)
    {
        processor.rawVolume = gainSlider.getValue();
    }
}


void Ism_pluginAudioProcessorEditor::buttonClicked (Button *button){
    
    if ( button == &output_am ){
        if ( playState == PlayState::Stop )
        {
            output_am.onClick = [this]() { play(); };
        }
        else if ( playState == PlayState::Play )
        {
            output_am.onClick = [this]() { stop(); };
        }
    }
    
}

void Ism_pluginAudioProcessorEditor::play(){
    
    playState = PlayState::Play;
    output_am.setColour(TextButton::ColourIds::buttonColourId, Colours::limegreen);
    output_am.setButtonText("playing");
    processor.ir_output = ISM_Simulation();
    Timer::startTimer (100);
    
}

void Ism_pluginAudioProcessorEditor::stop(){

    playState = PlayState::Stop;
    output_am.setColour(TextButton::ColourIds::buttonColourId, Colours::limegreen);
    output_am.setButtonText("Stoped");
    Timer::startTimer (100);
    
}

void Ism_pluginAudioProcessorEditor::buttonStateChanged (Button *){
    
}


void Ism_pluginAudioProcessorEditor::timerCallback(){
    
    
}

std::vector<double> Ism_pluginAudioProcessorEditor::ISM_Simulation(){
    
        const double cair = 343; // Speed of sound in air(m/s)
        const double alpha = 0.1;         //Acousrics Absorption
        const double reflection_coefficient = sqrt(1 - alpha); // Reflection coefficient
        const double fs = 48000;        // frequency

        // Lengths along x, y and z directions
        const double Lx = 5;
        const double Ly = 4;
        const double Lz = 3;

        double V = Lx * Ly * Lz;                            // Volume of room

        // Area of room walls
        double A1 = Lx * Ly;
        double A2 = Lx * Lz;
        double A3 = Ly * Lz;


        double alpha_bar = 2 * alpha * (A1 + A2 + A3);            // Formula for alpha_bar
        double T60 = (24 * log(10) * V) / (cair * alpha_bar);         // Formula for T60

        // Number of reflections Nx, Ny, Nz
        int Nx = (int)round(cair * T60 / Lx);
        int Ny = (int)round(cair * T60 / Ly);
        int Nz = (int)round(cair * T60 / Lz);

        // Position of source in cartesian coordinates(p, q, r)
        double p = 2;
        double q = 2;
        double r = 2;

        // Position of receiver in cartesian coordinates(a, b, c)
        double a = Lx / sqrt(2);
        double b = Ly / sqrt(2);
        double c = Lz / sqrt(2);

        int i = -Nx;
        int j = -Ny;
        int k = -Nz;

        double Ad;
        double Be;
        double Cf;
        double l_def; //

        const int vec_size = (int)ceil(fs * T60);
        vector<double> ir(vec_size);
        vector<double> ir_x(vec_size);
        vector<double> ir_y(vec_size);
        vector<double> ir_z(vec_size);

        vector<double> ir_v(vec_size);
        vector<double> ir_t(vec_size);
        vector<double> ir_r(vec_size);
        vector<double> ir_s(vec_size);
        vector<double> ir_u(vec_size);

        vector<double> ir_q(vec_size);
        vector<double> ir_o(vec_size);
        vector<double> ir_m(vec_size);
        vector<double> ir_k(vec_size);
        vector<double> ir_l(vec_size);
        vector<double> ir_n(vec_size);
        vector<double> ir_p(vec_size);



        ofstream outfile;
        outfile.open("./c.txt", ios::app | ios::in | ios::out);
        
        while (i <= Nx)
        {
            j = -Ny;
            if (i % 2 != 0)
            {
                Ad = ((double)i + 1) * Lx - p - a;
            } // Odd case
            else
            {
                Ad = i * Lx + p - a;
            }// Even case


            while (j <= Ny)
            {
                k = -Nz;
                if (j % 2 != 0)
                {
                    Be = ((double)j + 1) * Ly - q - b;
                } // Odd case
                else
                {
                    Be = j * Lx + q - b;
                }// Even case


                while (k <= Nz)
                {
                    if (k % 2 != 0)
                    {
                        Cf = ((double)k + 1) * Lz - r - c;
                    } // Odd case
                    else
                    {
                        Cf = k * Lz + r - c;
                    }// Even case

                    // Calculation of distances
                    l_def = sqrt(Ad * Ad + Be * Be + Cf * Cf);

                    double w = 1;

                    // 1-order
                    double x = Ad / l_def;
                    double y = Be / l_def;
                    double z = Cf / l_def;

                    // 2-order
                    double v_2 = sqrt(3) * x * y;
                    double t_2 = sqrt(3) * y * z;
                    double r_2 = (1 / 2) * (3 * pow(z, 2) - 1);
                    double s_2 = sqrt(3) * x * z;
                    double u_2 = sqrt(3 / 4) * (pow(x, 2) - pow(y, 2));

                    // 3-order
                    double q_3 = sqrt(5 / 8) * y * (3 * pow(x, 2) - pow(y, 2));
                    double o_3 = sqrt(15) * x * y * z;
                    double m_3 = sqrt(3 / 8) * y * (5 * pow(z, 2) - 1);
                    double k_3 = (1 / 2) * z * (5 * pow(z, 2) - 3);
                    double l_3 = sqrt(3 / 8) * x * (5 * pow(z, 2) - 1);
                    double n_3 = sqrt(15 / 4) * z * (pow(x, 2) - pow(y, 2));
                    double p_3 = sqrt(5 / 8) * x * (pow(x, 2) - 3 * pow(y, 2));


                    // Number of reflections
                    int omiga = abs(i) + abs(j) + abs(k);

                    double g = pow(reflection_coefficient, omiga) / l_def;

                    // Calculation of arrival times
                    double t = l_def / cair;

                    // Calculation of sample bin
                    size_t bin = (size_t)round(t * fs);

    #if 0
                    cout << std::fixed << g << endl;
                    cout << std::fixed << w << endl;
                    cout << g << endl;
                    cout << w << endl;
                    cout << "bin: " << bin << endl;
                    cout << "ir.size(): " << ir.size() << endl;
                    cout << "i = " << i << "\t";
                    cout << "j = " << j << "\t";
                    cout << "k = " << k << "\t" << endl;
    #endif
                    if (bin < ir.size())
                    {
                        ir[bin] += g * w;   // Impulse response and its magnitude
                         ir[bin] = ir[bin] + g * w;   // Impulse response and its magnitude

                        ir_x[bin] = ir_x[bin] + g * x;   // Impulse response and its magnitude


                        ir_y[bin] = ir_y[bin] + g * y;   // Impulse response and its magnitude

                        ir_z[bin] = ir_z[bin] + g * z;   // Impulse response and its magnitude
                        ir_k[bin] = ir_k[bin] + g * k_3;
                        ir_r[bin] = ir_r[bin] + g * r_2;
                       // cout<<"EEE"<<endl;

                        ir_v[bin] = ir_v[bin] + g * v_2;
                        ir_u[bin] = ir_u[bin] + g * u_2;
                        ir_q[bin] = ir_q[bin] + g * q_3;
                        ir_p[bin] = ir_p[bin] + g * p_3;


                        ir_s[bin] = ir_s[bin] + g * s_2;
                        ir_l[bin] = ir_l[bin] + g * l_3;


                        ir_t[bin] = ir_t[bin] + g * t_2;
                        ir_m[bin] = ir_m[bin] + g * m_3;


                        ir_o[bin] = ir_o[bin] + g * o_3;
                        ir_n[bin] = ir_n[bin] + g * n_3;

                       // cout<<bin<<" "<<ir.size()<<"\n";
                       // cout << index << "\t" << std::fixed << ir[bin] << endl;
                       // outfile << index++ << "\t" << std::fixed << ir[bin] << endl;
                    }

                  

                    k++;
                }
                j++;
            }
            i++;
        }
    
   // processor.ir_ambisonics = ir;
    //processor.buf.getWritePointer(16);
    
    return ir;
    
}
