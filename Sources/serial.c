#include <mc9s12dp256.h>        /* derivative information */

#include <stdio.h> 
#include <stdlib.h>

#include "serial.h"


// instantiate the serial port parameters
//   note: the complexity is hidden in the c file
SerialPort SCI1 = {&SCI1BDH, &SCI1BDL, &SCI1CR1, &SCI1CR2, &SCI1DRL, &SCI1SR1};
SerialPort SCI0 = {&SCI0BDH, &SCI0BDL, &SCI0CR1, &SCI0CR2, &SCI0DRL, &SCI0SR1};

int counter = 0;


// InitialiseSerial - Initialise the serial port SCI1
// Input: baudRate is tha baud rate in bits/sec
void SerialInitialise(int baudRate, SerialPort *serial_port) {
  
  // Baud rate calculation from datasheet
  switch(baudRate){
	case BAUD_9600:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=156;
	  break;
	case BAUD_19200:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=78;
	  break;
	case BAUD_38400:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=39;
	  break;
	case BAUD_57600:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=26;
	  break;
	case BAUD_115200:
      *(serial_port->BaudHigh)=0;
      *(serial_port->BaudLow)=13;
	  break;
  }
  
  *(serial_port->ControlRegister2) = SCI1CR2_RE_MASK | SCI1CR2_TE_MASK | SCI1CR2_TCIE_MASK;
  *(serial_port->ControlRegister1) = 0x00;
}



// look at the isr_vectors.c for where this function is 
//  added to the ISR vector table
#pragma CODE_SEG __NEAR_SEG NON_BANKED /* Interrupt section for this module. Placement will be in NON_BANKED area. */
__interrupt void SCI1_ISR(SerialPort *serial_port_in, SerialPort *serial_port_out, char *pt, char *input_string) {
  //set counter to read for 256 bits or until end character falg 'x' is reached
  char output_string[256];
  while(counter < 256 && *(serial_port_in->DataRegister) != 'x'){
    while((*(serial_port_in->StatusRegister) & SCI1SR1_RDRF_MASK) == 0){
    }
    //store read characters in output string and memory pointer
    output_string[counter] = *(serial_port_in->DataRegister);
    *pt = output_string[counter];
    pt++;
    counter++;
  }
 
  //output string until termination character is reached
  counter = 0;
  while(*input_string != 'x'){
    while((*(serial_port_out->StatusRegister) & SCI1SR1_TDRE_MASK) == 0){
    }
    //transmit output string to serial port
    *(serial_port_out->DataRegister) = *input_string;
    *input_string++;
    counter++;
    //termiante string if it reaches 256 chracters
    if(counter == 255){*input_string = 'x';}
  }
  //wait for final two chracters to be read
  while((*(serial_port_out->StatusRegister) & SCI1SR1_TDRE_MASK) == 0){
  }
  *(serial_port_out->DataRegister) = *input_string;
  *input_string++;
  while((*(serial_port_out->StatusRegister) & SCI1SR1_TDRE_MASK) == 0){
  }
  //terminate interrupts from TCIE
  *(SCI1.ControlRegister2) &= ~SCI1CR2_TCIE_MASK;
}





