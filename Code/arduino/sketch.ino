#include <Arduino_LED_Matrix.h>
#include <Arduino_RouterBridge.h>

Arduino_LED_Matrix matrix;

// 8x13 Matrix Structure (Direct Visual Mapping)
// Style: Classic Rectangular Robot

// 🤖 HAPPY ROBOT
uint8_t happy_map[104] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0, // Top border
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,1,1,0,0,0,0,0,1,1,0,0, // Square eyes
  0,0,1,1,0,0,0,0,0,1,1,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,1,0,0,0,0,0,0,0,1,0,0, // Corners
  0,0,0,1,1,1,1,1,1,1,0,0,0, // Smiling mouth
  0,0,0,0,0,0,0,0,0,0,0,0,0  // Bottom border
};

// 🤖 SAD ROBOT
uint8_t sad_map[104] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,1,1,0,0,0,0,0,1,1,0,0, // Square eyes
  0,0,1,1,0,0,0,0,0,1,1,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,1,1,1,1,1,0,0,0,0, // Sad mouth (curved up)
  0,0,0,1,0,0,0,0,0,1,0,0,0, // Corners down
  0,0,0,0,0,0,0,0,0,0,0,0,0
};

// 🤖 NEUTRAL ROBOT
uint8_t neutral_map[104] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,1,1,0,0,0,0,0,1,1,0,0,
  0,0,1,1,0,0,0,0,0,1,1,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,1,1,1,1,1,1,1,0,0,0, // Straight line
  0,0,0,0,0,0,0,0,0,0,0,0,0
};

// 🤖 ANGRY ROBOT
uint8_t angry_map[104] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,1,0,0,0,0,0,0,0,0,0,1,0, // Low eyebrows
  0,0,1,1,0,0,0,0,0,1,1,0,0,
  0,0,1,1,0,0,0,0,0,1,1,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,1,1,1,1,1,1,1,0,0,0, // Tense mouth
  0,0,1,1,1,1,1,1,1,1,1,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0
};


// 🎓 ROSARIO UNIVERSITY LOGO (UR)
uint8_t ur_map[104] = {
  0,0,1,0,1,0,0,0,0,1,1,0,0, // Frame
  0,0,1,0,1,0,0,0,1,0,0,1,0, // U      R
  0,0,1,0,1,0,0,0,1,0,1,0,0, // U      R R
  0,0,1,0,1,0,0,0,1,1,0,0,0, // U      R R
  0,0,1,0,1,0,0,0,1,0,1,0,0, // U      R  R
  0,0,0,1,1,0,0,0,1,0,0,1,0, //  UU    R   R
  0,0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,0  // Frame
};

void set_emotion(String emotion) {
  emotion.trim();
  emotion.toLowerCase();

  if (emotion == "happy") matrix.draw(happy_map);
  else if (emotion == "sad") matrix.draw(sad_map);
  else if (emotion == "neutral") matrix.draw(neutral_map);
  else if (emotion == "angry") matrix.draw(angry_map);
  else if (emotion == "ur") matrix.draw(ur_map);
}

void setup() {
  matrix.begin();
  matrix.setGrayscaleBits(1); 

  Bridge.begin();
  Bridge.provide("set_emotion", set_emotion);

  matrix.draw(happy_map); // Start with happy robot
}

void loop() {
  // Bridge handles communication with your Python script
}