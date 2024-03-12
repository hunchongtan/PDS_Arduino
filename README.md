# DIY SwitchBot with ESP32 Wi-Fi Module & Google Firebase
This tutorial will illustrate the working of a DIY SwitchBot.
<br />
💪 Beginner | ⌛ 45 minutes

## Things used in this project
### Hardware components
|Image|Component|
|---|---|
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/470521b0-39d2-4729-95ea-c9b2d57a649e" width="50" height="50" /> | Espressif ESP32C3 x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/e7c2a8a6-5829-4b99-b2c0-9aa6a6edfcbe" width="50" height="50" /> | IR Receiver Module x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/afaab760-6f66-4ae0-897b-1c7edb900672" width="50" height="50" /> | Remote Control x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/33e17dd1-d392-4c0d-8e3f-4b458fe769ce" width="50" height="50" /> | SG90 Servo Motor x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/238b49fe-a1a4-4469-a318-1cc11e583823" width="50" height="50" /> | Resistor 220 ohm x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/cce7aaf2-57fe-417b-bcb9-d44773cc0388" width="50" height="50" /> | Breadboard x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/ee52d09e-47b5-478b-bdf2-fdebed566702" width="50" height="50" /> | Male/Male Jumper Wires x 6 |

### Software apps and online services
|Image|App|
|---|---|
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/ba182cba-b991-4659-b1a6-084f78d30854" width="50" height="50" /> | Arduino IDE	|
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/ec589b17-5ed1-42f2-ac26-1ba949dd5604" width="50" height="50" /> | Google Firebase |

## Story
### What is a SwitchBot?
A SwitchBot is a small gadget with a tiny arm that physically presses the switch or button for you. It can help you to switch on or off your switch without the need to walk over physically. Control your lights, appliances, and even blinds remotely. SwitchBot brings automation and convenience to your everyday life, all in a small, easy-to-install package.

![switchbot-pull](https://github.com/hunchongtan/PDS_Arduino/assets/87000020/02ed8dfe-225f-4936-9bf0-fffef3d85403)

In simple terms, a SwitchBot can turn almost any regular switch or button into a smart one!

### My Inspiration
The SwitchBot is a must-get for any lazy or “efficient” person like me! However, the $40 SwitchBot price tag had me scrolling past right quickly. But then, a spark of inspiration hit. Why spend the big bucks when I could unleash my inner inventor? Here's the thing: with some Arduino know-how, I can build my own smart switch, customise it exactly how I want, and all for a fraction of the cost. Suddenly, my university Acai Bowl budget started looking a little brighter.  Plus, the challenge of building something myself? Way more exciting than hitting "add to cart."

### Basic Set-Up
Before typing-out the necessary code, you have to set up the IR receiver. Follow this guide
