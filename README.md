# Emotions-Arduino-Q: Edge Face Emotion Recognition 🎭

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Arduino-UNO%20Q-00979D.svg?style=flat&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![GitHub](https://img.shields.io/badge/GitHub-Repository-blue?logo=github)](https://github.com/jsarmientor/emotions-arduino-q.git)

**Emotions-Arduino-Q** is a real-time face emotion recognition system running on the edge using **Arduino UNO Q**, **Python**, and **face-api.js**. This project bridges the gap between high-level browser-based AI and low-level hardware interaction.


![Project Banner](images/linux-blink-banner.png)

## 📌 Overview

This application analyzes human facial expressions in real-time through a web browser and triggers physical responses on an Arduino board. It demonstrates how to implement Edge AI with a seamless communication bridge between a web frontend and a microcontroller.

## 📂 Project Structure

```text
emotions-arduino-q/

├── Code/               # Core source code
│   ├── arduino/        # Firmware for Arduino UNO Q (.ino)
│   ├── models/         # Pre-trained face-api.js models
│   ├── libs/           # WebSocket and UI libraries
│   ├── main.py         # Python Backend (Bridge & WebUI)
│   ├── app.yaml        # Configuration for App Lab
│   └── ...             # Web UI (HTML, CSS, JS)
├── images/             # Project media and documentation
└── README.md           # This file
```

## 🛠️ Key Features
- **Real-time Detection**: Millisecond-level emotion inference in the browser.
- **Edge Computing**: No heavy cloud processing required.
- **Privacy First**: All facial data remains local to the browser.
- **Hardware Interaction**: Direct control of Arduino LED matrix based on sentiment.

## 🏗️ Architecture

```mermaid
graph LR
    A[Web Camera] --> B[Face Detector]
    B --> C[Expression Analysis]
    C --> D[Python Backend]
    D --> E[Router Bridge]
    E --> F[Arduino LED Matrix]
```

## 🎥 Visual Gallery

### 🤖 Project in Action
These demonstrations showcase the real-time interaction between facial expressions and the Arduino LED matrix.

<img src="images/demo_emotions.gif" width="400">

*The system recognizes emotions in real-time and updates the Arduino LED matrix accordingly.*

| **Face Tracking** | **Hardware Response** | **Inference Result** |
| :---: | :---: | :---: |
| <img src="images/IMG_4580.jpg" height="300"> | <img src="images/IMG_4581.jpg" height="300"> | <img src="images/IMG_5811.jpg" height="300"> |

> [!TIP]
> **Watch the Main Demo**: [🎬 Emotions-Arduino-Q in Action (Video)](images/60A774FE-E03A-437D-AB5A-84C6252F988F%20Copy.mov)


## 📸 Project Media



You can find more project media (images) in the [images/](images/) directory.

```text
- Images: JPG format (Previews)
```



## 📝 License


This project is licensed under the MIT License.
