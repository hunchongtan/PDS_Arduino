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