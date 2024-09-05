# Smart Blind Stick Project

This project uses an IP webcam feed and TensorFlow for object detection to identify potholes on roads. The goal is to provide an automated system to detect potholes, which can help in timely maintenance and repair.

## Demo Screenshot
![WhatsApp Image 2024-07-31 at 18 00 33_01c1d1eb](https://github.com/user-attachments/assets/957f9858-0728-4bef-91e9-38bdc74b812e)


## Features
- Real-time video feed capture from IP webcam
- Object detection using TensorFlow
- Pothole identification and marking
- Visualization of detected potholes

## Requirements
- Python 3.6+
- OpenCV
- TensorFlow
- NumPy
- IP Webcam (for video feed)

## Setup
Follow these steps to get the project up and running on your local machine:

1. **Clone the Repository**
    ```sh
    git clone https://github.com/yourusername/pothole-detection.git
    cd pothole-detection
    ```

2. **Create a Virtual Environment**
    ```sh
    python3 -m venv env
    source env/bin/activate
    ```

3. **Install Dependencies**
    ```sh
    pip install -r requirements.txt
    ```
    If `requirements.txt` is not available, manually install the dependencies:
    ```sh
    pip install opencv-python-headless tensorflow numpy
    ```

4. **Run the Detection Script**
    ```sh
    python Pathholedetection.py
    ```

## Directory Structure
```plaintext
pothole-detection/
│
├── GPS.cpp
├── Pathholedetection.py
├── Arduino.cpp
├── README.md
├── requirements.txt
└── LICENSE
