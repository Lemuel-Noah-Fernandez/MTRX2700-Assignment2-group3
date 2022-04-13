# MTRX2700-Assignment2-group3
Exercise 1:

The exercise 1 functions include ‘SerialInitialise’ and the interrupt service routine ‘SCI1_ISR’. The serial document begins by declaring some serial port structs. These structs are declared as extern variables in serial.h and are used in the functions in serial and main.

SerialInitialise:
  -	SerialInitialise takes two variables, a serial port address, and a BAUD rate.
  -	Using these variables the function then uses switch cases to assign the corresponding BAUD rate
  -	It also enables the TE(transmit enable flag), the RE(receiver enable flag), and the TCIE(transmit complete interrupt flag) 

SCI_ISR:
  -	This is the interrupt service routine triggered by the TCIE interrupt 
  -	Takes four parameters, two serial port addresses, and two char pointers
  -	The first two parameters are the input and output serial ports, they can be the same or different
  -	When triggered the function reads in characters until the terminating character ‘x’ is reach, and then outputs characters until the terminating ‘x’ 
    character is reached. 
  -	The next two parameters are the string to store serial input in, and the string to send to the output serial port
  -	This can be configured to display a pre filled buffer or the input serial port

Testing:
  - Use show location of variable in data table, doing this can see if data is read from the serial port into memory
  - Changing input string and output string to test if it can handle a variety of strings
  - Using different serial ports, and different combinations of serial ports to see if module can work with any serial ports
