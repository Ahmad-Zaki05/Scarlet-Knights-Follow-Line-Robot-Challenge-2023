# Scarlet-Knights-Follow-Line-Robot-Challenge-2023
This repository is made to showcase the work done by my students and myself in order to compete in the Follow Line category in Robot Challenge Egypt 2023 and winning 2nd place.

The team's members are:
  - Yahia Osama, works as the mechanical designer
  - Galal, works as the electrical and PCB designer
  - Yahia Amr, works as the programmer

The robot's components are:
  - 5 * TCRT5000 IR sensors: https://makerselectronics.com/product/infrared-line-follower-sensor
  - 2 * 620 RPM motors: https://ampere-electronics.com/product/25ga370-dc-gear-motor-12v-620rpm/
  - 1 * Arduino Nano: https://makerselectronics.com/product/arduino-nano-with-ch340-uploader-micro-usb
  - 1 * Cytron Dual Channel: https://store.fut-electronics.com/products/dual-channel-dc-motor-driver-10a-each?_pos=2&_sid=8398b2827&_ss=r
  - 2 * motor holders

Explanations for the mechanical parts and PCB are in the description of each file.

The code is based on a bang-bang control scheme. We opted for this method as it is easier to test and is less time-consuming, unlike other methods, such as PID, that need a lot of time to reach the optimal kp, kd and ki values. We tried solving the main issue with the bang-bang method, which is the oscillations that occur due to the rapid changing of states, by putting the inner IR sensors at a close distance and implemented two while loops, one for the right turn and one for the left, to always make the robot return to the neutral position. The close distance and the tested speeds made the oscillations very small that it sometimes did not even occur. When the outer sensors read black, the robot has to make a sharp turn until it returns to the neutral position. The two functions whileright and whileleft were implemented in order to quickly change from a sharp right turn to a sharp left turn or vice versa in sharp consecutive corners.

This is all that we have been able to make during the three months we have been working for and we hope that we will use this year's experience in order to make a much better robot next year and win first place in RC 2024 in Inshaa'Allah.
