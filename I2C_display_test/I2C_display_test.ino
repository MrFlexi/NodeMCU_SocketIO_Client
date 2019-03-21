

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>


// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Frame Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected



//U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // Adafruit Feather ESP8266/32u4 Boards + FeatherWing OLED
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);   // pin remapping with ESP8266 HW I2C

void setup(void) { 
  
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x12_tr);
}

const char *string_list = 
  "Altocumulus\n"
  "Altostratus\n"
  "Cirrocumulus\n"
  "Cirrostratus\n"
  "Cirrus\n"
  "Cumulonimbus\n"
  "Cumulus\n"
  "Nimbostratus\n"
  "Stratocumulus\n"
  "Stratus";

uint8_t current_selection = 0;


void loop(void) {

  current_selection = u8g2.userInterfaceSelectionList(
    "Cloud Types",
    current_selection, 
    string_list);

  if ( current_selection == 0 ) {
    u8g2.userInterfaceMessage(
	"Nothing selected.", 
	"",
	"",
	" ok ");
  } else {
    u8g2.userInterfaceMessage(
	"Selection:", 
	u8x8_GetStringLineStart(current_selection-1, string_list ),
	"",
	" ok \n cancel ");
  }
}
