
# 💣 BadUSB Downloader
Download &amp; Execute file using DigiSpark ATtiny85, RubberDucky or Arduino Pro Micro.

## 🔌 Devices tested:
+ [USB Rubber ducky (Doesn't support ALT Codes)](https://shop.hak5.org/products/usb-rubber-ducky) 
+ [ATtiny85 Digispark (Doesn't support ALT Codes)](https://www.aliexpress.com/w/wholesale-Digispark-attiny85.html)
+ [Arduino Pro Micro (Supports ALT Codes)](https://www.aliexpress.com/w/wholesale-arduino-pro-micro.html)



<details>
<summary> ❔ What is Alt Codes</summary>
Alt codes are a method of typing characters that are not readily available on a keyboard by pressing the `Alt` key in combination with a numeric code on the numeric keypad. For example, `Alt + 065` produces an uppercase 'A'.
So alt codes will work even if OS doesn't have installed English layout.
</details>


<details>
<summary> ✨ Digispark support for Arduino IDE</summary>
To add support for Digistump boards (like the Digispark) to the Arduino IDE, you need to install the Digistump board definitions. Here's how you can do it:

1. **Open Arduino IDE**: Start the Arduino IDE on your computer.

2. **Add Digistump Board Manager URL**:
   - Go to `File` > `Preferences`.
   - In the "Additional Boards Manager URLs" field, add the following URL:
     ```
     https://raw.githubusercontent.com/ArminJo/DigistumpArduino/master/package_digistump_index.json
     ```
   - If there are already URLs in that field, separate them with commas.
   - Click "OK" to close the Preferences window.

3. **Install Digistump Boards**:
   - Go to `Tools` > `Board` > `Boards Manager...`.
   - In the Boards Manager, type "Digistump" in the search bar.
   - Find the entry for "Digistump AVR Boards" by Digistump and click the "Install" button.

4. **Select Your Board**:
   - After installation, go to `Tools` > `Board` and select the appropriate Digistump board (e.g., "Digispark (Default - 16.5MHz)").

5. **Install Drivers (if necessary)**:
   - Depending on your operating system and the specific Digistump board you are using, you may need to install additional [drivers](https://github.com/digistump/DigistumpArduino/releases).
   - For Digispark boards, drivers are often required for Windows. You can find driver installation instructions on the Digistump Wiki or in the documentation that came with your board.

6. **Start Using the Board**:
   - Connect your Digistump board to your computer.
   - You might need to follow specific procedures for uploading sketches, as some Digistump boards do not use a standard bootloader like other Arduino boards.

</details>

<details>
<summary> ⭐ Some helpful links</summary>
   
+ [DuckyScript Encoder](https://payloadstudio.hak5.org/community/)
+ [Download Arduino IDE](https://www.arduino.cc/en/software)
+ [Digistump Drivers](https://github.com/digistump/DigistumpArduino/releases)
  
</details>


