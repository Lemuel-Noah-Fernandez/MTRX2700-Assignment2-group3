# MTRX2700-Assignment2-group3
###Exercise 1:

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

###Exercise 2:
The Parser is the intermediatary that allows the serial inputs to be converted into usable parameters and definitions to run and act on the program. This sub-program is split into two primary parts. These are the
   - The operator identifier, which idenfies which operation should be called of which there are two being 'run' which runs a function defined in main and other is say      which sends the string to the serial output port
   - The operator handler which is the second step and is what determines what todo with the operand and parameters of the command

The say command simplt outputs to serial what is put in the parameters section of the command ie "say the moon is big" the output to serial will be "the moon is big".

The run command is comprised of three seperate sections, first being the operator to run, second being the function to be ran, and the parameters which the function may take in each seperated by a space

TESTING
   - Done using test strings which were hardcoded in and sent to the function  

###Exercise 3:
The exercise 3 module utilised interrupts from the TC5 timer module, to output different frequencies onto the Dragonboard's PT5 port. This resulted in a tune being played. First, a variable `score` is defined as an unsigned int array and is sent to the terminal through use of the Exercise 2's functions. This variable is then used as an input argument for the `making_music` function, which loops through the score changing the `note` variable with each iteration, therby triggering the TC5 interrupt.

Additionaly, there are various functions with `making_music`. `Delay(time)` takes in an int as an argument and creates a delay equal to that integer * 10 ms. `timer_setup` initialises the timer and interrupt sequance and `octave_checker` changes the `note` variable depending on which octave the note is in. 

Testing
- Running through various scores and checking it's effect on the Dragonboard's music in real time
- Checking the variables associated with `time` and `note` in the debugger to see if it is changing correctly
