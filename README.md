
# 💣 BadUSB Downloader
Download &amp; Execute file using DigiSpark ATtiny85 or RubberDucky

## 🔌 Devices used:
+ [USB Rubber ducky](https://shop.hak5.org/products/usb-rubber-ducky) 
+ [ATtiny85 Digispark](https://www.aliexpress.com/item/1005005100542239.htm)

## ✨ Digispark support for Arduino IDE

To add support for Digistump boards (like the Digispark) to the Arduino IDE, you need to install the Digistump board definitions. Here's how you can do it:

1. **Open Arduino IDE**: Start the Arduino IDE on your computer.

2. **Add Digistump Board Manager URL**:
   - Go to `File` > `Preferences`.
   - In the "Additional Boards Manager URLs" field, add the following URL:
     ```
     http://digistump.com/package_digistump_index.json
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



## ⭐ Some helpful links
+ [DuckyScript Encoder](https://payloadstudio.hak5.org/community/)
+ [Download Arduino IDE](https://www.arduino.cc/en/software)
+ [Digistump Drivers](https://github.com/digistump/DigistumpArduino/releases)
