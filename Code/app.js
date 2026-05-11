const socket = io(`http://${window.location.host}`);

function sendEmotion(emotion) {
  console.log("Emotion detected:", emotion);
  socket.emit("set_emotion", { emotion: emotion });
}

