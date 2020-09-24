# Autonomous Vehicle based on Dublin's Luas Light Rail System

The aim of this project is to develop an autonomous vehicle based on the Luas Light Rail System of Dublin, Ireland, using Arduino (Atmega-328p) & remote wireless supervisory control (using, XCTU & XBee or C#) with capability of ultrasonic obstacle detection & avoidance, self-parking, stopping at gantries in its path & safely co-existing with other vehicles. 

<p align="center">
    <img width="550" height="300" src = 'https://github.com/aviralchharia/Autonomous-Vehicle-based-on-Dublin-Luas-Light-Rail-System/blob/master/Images/Luas%20Light%20Rail%20Dublin.jpg?raw=true'
</p>

The Infra-Red module, Transmitter & Receiver circuits were designed & fabricated on a PCB from scratch to develop the vehicle.

## Receiver Circuit

A receiver circuit is developed which is used to identify different locations on the path i.e., the receiver circuit will be attached/mounted on to the vehicle and when it will pass through the gantries, the IR signals emitted from the IR Emitter Diodes of the gantries, will fall on the Receiver Circuit, which in turn will signal the vehicle to stop at the gantries for some time. 

### Working of the Receiver Circuit

The Receiver circuit is based on the PWM (Pulse Width Modulation) Technique. The MBD701 Schottky Diode acts as the Receiver which senses the Infra-Red Radiations and sends then to the circuit accordingly. The infra-red radiations received by the diode is sent to the op-amp comparator which are then further sent to the capacitor where the signal is rectified to proper DC pulse. 

<p align="center">
    <img width="450" height="350" src = 'https://github.com/aviralchharia/Autonomous-Vehicle-based-on-Dublin-Luas-Light-Rail-System/blob/master/Images/PWM%20based%20Receiver%20Circuit.jpg?raw=true'
</p>

An infra-red sensor is placed at the Gantries, so that when the vehicle will pass through it, the MBD701 Schottky diode will sense the IR Radiations and the vehicle will stop. Following this, after a certain interval the vehicle restarts its motion as the signals being sent to the diode from the comparator has been changed. Moreover, the first signal is sent directly from the diode to the comparator but the second signal is sent through the resister R2.

## Transmitter Circuit

<p align="center">
    <img width="800" height="450" src = 'https://github.com/aviralchharia/Autonomous-Vehicle-based-on-Dublin-Luas-Light-Rail-System/blob/master/Images/PWM%20based%20Transmitter%20Circuit.jpg?raw=true'
</p>


## IR Module


<p align="center">
    <img width="700" height="450" src = 'https://github.com/aviralchharia/Autonomous-Vehicle-based-on-Dublin-Luas-Light-Rail-System/blob/master/Images/IR%20Module.png?raw=true'
</p>

## Final Vehicle

<p align="center">
    <img width="450" height="250" src = 'https://github.com/aviralchharia/Autonomous-Vehicle-based-on-Dublin-Luas-Light-Rail-System/blob/master/Images/Buggy%20Project-01.jpg?raw=true'
</p>
  
  
  
  
