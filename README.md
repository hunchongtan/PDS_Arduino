# DIY SwitchBot with ESP32 Wi-Fi Module & Google Firebase
This tutorial will illustrate the working of a DIY SwitchBot.
<br />
💪 Beginner | ⌛ 45 minutes | 🎥 <a href="https://youtube.com/shorts/9i0o1jms224?feature=share"> Video Demo </a>

## Things used in this project
### Hardware components
|Image|Component|
|---|---|
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/470521b0-39d2-4729-95ea-c9b2d57a649e" width="50" height="50" /> | Espressif ESP32C3 x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/e7c2a8a6-5829-4b99-b2c0-9aa6a6edfcbe" width="50" height="50" /> | IR Receiver Module x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/afaab760-6f66-4ae0-897b-1c7edb900672" width="50" height="50" /> | Remote Control x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/33e17dd1-d392-4c0d-8e3f-4b458fe769ce" width="50" height="50" /> | SG90 Servo Motor x 2 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/238b49fe-a1a4-4469-a318-1cc11e583823" width="50" height="50" /> | Resistor 220 ohm x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/cce7aaf2-57fe-417b-bcb9-d44773cc0388" width="50" height="50" /> | Breadboard x 1 |
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/ee52d09e-47b5-478b-bdf2-fdebed566702" width="50" height="50" /> | Male/Male Jumper Wires x 9 |

### Software apps and online services
|Image|App|
|---|---|
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/ba182cba-b991-4659-b1a6-084f78d30854" width="50" height="50" /> | Arduino IDE	|
|<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/ec589b17-5ed1-42f2-ac26-1ba949dd5604" width="50" height="50" /> | Google Firebase |

## Story
### What is a SwitchBot?
A SwitchBot is a small gadget with a tiny arm that physically presses the switch or button for you. It can help you to switch on or off your switch without the need to walk over physically. Control your lights, appliances, and even blinds remotely. SwitchBot brings automation and convenience to your everyday life, all in a small, easy-to-install package.

<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/02ed8dfe-225f-4936-9bf0-fffef3d85403" width="500" />

In simple terms, a SwitchBot can turn almost any regular switch or button into a smart one!

### My Inspiration
I stay in my university hostel and the light switch is a distance away from the bed. I always face the issue of needing to get out of bed, walk over to the light switch and switch off the lights physically. 

<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/11478434-5ae3-4f39-9a51-e6ea1156ea42" width="300" />

It was then I found out about the SwitchBot. The SwitchBot is a must-get for any lazy or “efficient” person like me! However, the $40 SwitchBot price tag had me scrolling past right quickly. But then, a spark of inspiration hit. Why spend the big bucks when I could unleash my inner inventor? Here's the thing: with some Arduino know-how, I can build my own smart switch, customise it exactly how I want, and all for a fraction of the cost. Suddenly, my university Acai Bowl budget started looking a little brighter.  Plus, the challenge of building something myself? Way more exciting than hitting "add to cart."

## Basic Set-Up
### Essential Libraries
Download the following libraries:
- Arduino
- WiFi
- FirebaseESP32
- IRremote
- ESP32Servo (Normal Servo library does not work as well)

### IR Receiver Set-Up
Before typing-out the necessary code, you have to set up a basic circuit for the IR receiver as such: ( <a href="https://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/">Reference Link </a> )

<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/e0dbaf46-979e-44a0-b957-1bcde0e6ac80" width="500" />

Upload this code to Arduino IDE and open the serial monitor to find the key codes for your remote control.

```
#include <IRremote.h>

const int RECV_PIN = 6; // Please change according to your IR receiver pin.
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}
```
Now press each key on your remote and **write down the hexadecimal codes printed for Plus and Minus key presses**.
<br />
Note that you will receive a 0XFFFFFFFF code when you press a key continuously.
<br />
<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/0095d1ae-069a-4b67-a58b-b5f21330048d" width="200" />
<br />
In my case, my plus Button code is 0xA3C8EDDB and minus Button code is 0xF076C13B.

## Schematics
### Connection Schematic Diagram
Note: Due to limations on TinkerCAD, diagram shows an Arduino UNO instead. Just take note of the pinwiring.
<br />
<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/c6f1fb3d-3293-480c-bbe4-15c202c769f5" width="500" />
<br />
A 220 ohm resistor is connected to IR Receiver to prevent short circuit.
<br />
### Circuit Diagram
<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/57f1201d-5813-4fc6-982b-8e0b3c3ed1cf" width="500" />

## Demo
### Product Demo
<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/f4e860b2-7ff9-443e-b342-c55fe1cd8b67" width="500" />

### Firebase Demo
<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/500490c4-291a-498f-8710-32026adaabe8" width="500" />

## Code
#### In this piece of code, you need to amend the codes that are commented with //.
```
#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <IRremote.h>
#include <ESP32Servo.h>

/* Define the WiFi credentials */
#define WIFI_SSID "your_wifi_ssid" // Please indicate your own WIFI_SSID.
#define WIFI_PASSWORD "your_wifi_password" // Please indicate your own WIFI_PASSWORD.

/* Define the API Key */
#define API_KEY "your_api_key" // Please indicate your own API_KEY.
#define DATABASE_URL "your_database_url" // Please indicate your own DATABASE_URL.

/* Define the IR remote button codes */
#define backButton 0x52A3D41F // Please change according to your button code tested from the Set Up procedure.
#define frontButton 0xD7E84B1B // Please change according to your button code tested from the Set Up procedure.
#define plusButton 0xA3C8EDDB // Please change according to your button code tested from the Set Up procedure.
#define minusButton 0xF076C13B // Please change according to your button code tested from the Set Up procedure.

/* Define the pins */
#define RECV_PIN 6  // Please change according to your IR receiver pin.
#define SERVO_TOP_PIN 7 // Please change according to your Top Servo pin.
#define SERVO_BTM_PIN 8 // Please change according to your Btm Servo pin.

/* Define the Firebase user credentials */
#define USER_EMAIL "your_user_email" // Please indicate your own USER_EMAIL.
#define USER_PASSWORD "your_user_password" // Please indicate your own USER_PASSWORD.

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

IRrecv irrecv(RECV_PIN);
decode_results results;
Servo top;
Servo btm;

void setup() {
  /* Initalise Serial Monitor */
  Serial.begin(9600); // Please change according to the baud value stated on the top right of Serial Monitor.

  /* Start the IR Receiver */
  irrecv.enableIRIn();
  irrecv.blink13(true);

  /* Attach the servo to its pin and Initalise it to the 90 degrees position */
  servo.attach(SERVO_PIN);
  servo.write(90);
  
  /* Connect to WiFi */
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println("\nConnected to WiFi");

  /* Initialise Firebase */
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  /* Assign the api key (required) */
  config.api_key = API_KEY;
  /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
  /* Comment or pass false value when WiFi reconnection will control by your code or third party library e.g. WiFiManager */
  Firebase.reconnectNetwork(true);
  /* Since v4.4.x, BearSSL engine was used, the SSL buffer need to be set. */
  /* Large data transmission may require larger RX buffer, otherwise connection issue or data read time out can be occurred. */
  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);
  Firebase.begin(&config, &auth);
  Firebase.setDoubleDigits(5);
  /* Check Firebase connection */
  if (Firebase.ready()) {
    Serial.println("Connected to Firebase!");
  } else {
    Serial.println("Failed to connect to Firebase!");
  }
}

void loop() {
  if (irrecv.decode(&results)){
      Serial.println(results.value, HEX);
      /* Under State-key branch, add and initalise keys (on & off) with the values 0 to Firebase. */

      /* Left Switch Functions */
      if (results.value == plusButton) {
        Serial.println("Plus button pressed!");
        /* Rotate the servo motor 150 degrees */
        top.write(150);
        /* Delay for 1 second */
        delay(1000);
        /* Stop the servo motor */
        top.write(90);
        /* Change on-key value to 1 */
        Firebase.set(fbdo, "State/Left", 0);
      }
      if (results.value == minusButton) {
        Serial.println("Minus button pressed!");
        /* Rotate the servo motor 30 degrees */
        btm.write(30);
        /* Delay for 1 second */
        delay(1000);
        /* Stop the servo motor */
        btm.write(90);
        /* Change off-key value to 1 */
        Firebase.set(fbdo, "State/Left", 1);
      }

      /* Right Switch Functions */
      if (results.value == frontButton) {
        Serial.println("Front button pressed!");
        /* Rotate the servo motor 30 degrees */
        top.write(30);
        /* Delay for 1 second */
        delay(1000);
        /* Stop the servo motor */
        top.write(90);
        /* Change on-key value to 1 */
        Firebase.set(fbdo, "State/Right", 0);
      }
      if (results.value == backButton) {
        Serial.println("Back button pressed!");
        /* Rotate the servo motor 150 degrees */
        btm.write(150);
        /* Delay for 1 second */
        delay(1000);
        /* Stop the servo motor */
        btm.write(90);
        /* Change off-key value to 1 */
        Firebase.set(fbdo, "State/Right", 1);
      }

      /* Receive the next value */
      irrecv.resume();
  }
}
```

## Physical Set Up
Ideally, the code is for a top-btm servo motor set up for 2 switches as shown in this<a href="https://www.hackster.io/tharindusrt/servo-light-switch-mqtt-1ff492"> example online</a>:
<img src="https://github.com/hunchongtan/PDS_Arduino/assets/87000020/4ff9fd5a-e4ae-4788-b7e2-05214ac071b1" width="500" />
Due to space constraints above the switch, I have gone for a top-btm servo motor set up for just the light switch.

## Troubleshooting Tips
- Tweak the angle of rotation (0 - 180) based on the amount of strength needed to turn the switch on/off.
- Firmly secure the servo motor with Bluetac or any adhesive.
- Make sure the cable connected is a data cable.
- Use a portable battery pack to power the circuit.
