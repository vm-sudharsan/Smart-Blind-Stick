import cv2
import numpy as np
import pyttsx3

# Initialize text-to-speech engine
engine = pyttsx3.init()
engine.setProperty('rate', 150)  # Speed of speech

# Capture video from mobile phone camera
# Replace 'http://your_ip_address:port/video' with the actual URL
url = 'http://192.168.207.134:8080/video'
cap = cv2.VideoCapture(url)

alert_triggered = False

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print("Failed to grab frame")
        break

    # Convert frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Apply GaussianBlur to reduce noise and improve edge detection
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    # Use Canny edge detection
    edges = cv2.Canny(blurred, 50, 150)

    # Find contours
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    damage_detected = False
    for contour in contours:
        # Get bounding box
        x, y, w, h = cv2.boundingRect(contour)
        # Filter out small contours that may not be relevant (adjust threshold as needed)
        if cv2.contourArea(contour) > 500:
            # Draw bounding box around detected damage
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
            damage_detected = True

    if damage_detected and not alert_triggered:
        # Trigger alert
        engine.say("Alert: an object is detected")
        engine.runAndWait()
        alert_triggered = True

    if not damage_detected:
        alert_triggered = False

    # Display the processed frame
    cv2.imshow('Road Damage Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
