/*
RAMSoc Morse Code excercise starter code

*/

// Lets define a unit of time for a dot. Dashes and spaces are a multiple of this
int dotDelay = 200;

// Lets then define a string which we want to 
const char string[] = "sos";

// We also need the morse code patterns for each of the letters
char* letters[] = {
  ".-",   // a
  "-...", // b
  "-.-.", // c
  "-..",  // d
  ".",    // e
  "..-.", // f
  "--.",  // g
  "....", // h
  "..",   // i
  ".---", // j
  "-.-",  // k
  ".-..", // l
  "--",   // m
  "-.",   // n
  "---",  // o
  ".--.", // p
  "--.-", // q
  ".-.",  // r
  "...",  // s
  "-",    // t
  "..-",  // u
  "...-", // v
  ".--",  // w
  "-..-", // x
  "-.--", // y
  "--.."  // z
};

// This code is run once at the start of the program
void setup() {
  Serial.begin(9600);
  // The pinMode function Configures the specified pin to behave 
  // either as an input or an output.
  // Here we initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// This code runs infinitely and is the body of our program
void loop() {
  // To display the string as morse code we need to iterate through it character by character
  // So first lets initialize a character:
  char ch = string[0];
  
  // And create a loop with a range from 0 to the length of the string:
  for (int i = 0; i < strlen(string); i++) {
    // now set char to equal the character at the current index:
    ch = string[i];
    // Now check if the character is within the range a to z. by adding two conditional statements in the brackets
    if (ch >= 'a' && ch <= 'z'){
          // now we find the letter's morse code pattern by subtracting the ascii value of 'a' from that of the character
          flashCharacter(letters[ch - 'a']);
      } else if (ch == ' ') {
          // if the character is a space wait 4 units of time.
          delay(4000);
      }
  }
}

// The flashCharacter() function takes a pointer to a string of dots and dashes (a "pattern")
// It then loops through the pattern and flashes the light
void flashCharacter (char* pattern){
    // Use the function strlen() to calculate the length of the morse code pattern for the character
    // Loop through the string. for every dot or dash in the pattern call the flash funciton to flash the LED
    int length = strlen(pattern);
    for (int i = 0; i < length; i++) {
      Serial.println(pattern[i]);
      flash(pattern[i]);
    }
    // After each character we have a 3 dot long break
    delay(dotDelay*3);
}

// The flash() function turns the LED on or off for a specified amount of time, depending on if it is passed a dot or a dash
void flash(char dotOrDash) {
    // We use the digitalWrite funciton to set the value of the specified pin
    // Turn the builtin LED on:
    digitalWrite(LED_BUILTIN, HIGH);

    // Use an if statement to decide how long the LED should stay on for:
    if (dotOrDash == '.') {
      delay(dotDelay);
    } else if (dotOrDash == '-') {
      delay(dotDelay*2);
    }

    // Now turn the LED off:
    digitalWrite(LED_BUILTIN, LOW);
    // Now wait one unit of time:
    delay(dotDelay);
}