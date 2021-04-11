Introduction-
Human Machine Interface or HMI is a system comprising of hardware
and software that helps in communication and exchange of information
between the user (human operator) and the machine.
In this project, we have implemented a simple Arduino based hand gesture
control where you can control few functions of your web browser like
switching between tabs, scrolling up and down in web pages, shift between
tasks (applications), play or pause a video and increase or decrease the
volume (in VLC Player) with the help of hand gestures.







Concept Behind The Project-
The principle behind the Arduino based Hand Gesture Control of
Computer is actually very simple. All you have to do is use two Ultrasonic
Sensors with Arduino, place your hand in front of the Ultrasonic Sensor and
calculate the distance between the hand and the sensor. Using this
information, relevant actions in the computer can be performed.
The position of the Ultrasonic Sensors is very important. Place the two
Ultrasonic Sensors on the top of a laptop screen at either end. The distance
information from Arduino is collected by a Python Program and a special
library called PyAutoGUI will convert the data into keyboard click actions.








The following are the 5 different hand gestures or actions that are
programmed for demonstration purpose.
Gesture 1: Place your hand in front of the Right Ultrasonic Sensor
at a distance (between 15CM to 35CM) for a small duration and
move your hand away from the sensor. This gesture will Scroll
Down the Web Page or Decrease the Volume.
Gesture 2: Place your hand in front of the Right Ultrasonic Sensor
at a distance (between 15CM to 35CM) for a small duration and
move your hand towards the sensor. This gesture will Scroll up the
Web Page or Increase the Volume.
Gesture 3: Swipe your hand in front of the Right Ultrasonic Sensor.
This gesture will move to the Next Tab.
Gesture 4: Swipe your hand in front of the Left Ultrasonic Sensor.
This gesture will move to the Previous Tab or Play/Pause the Video.
Gesture 5: Swipe your hand across both the sensors (Left Sensor
first). This action will Switch between Tasks.