#ifndef SCI1_HEADER
#define SCI1_HEADER


// NOTE: these are stored as pointers because they 
//       are const values so we can't store them directly
//       in the struct
typedef struct SerialPort {
  byte *BaudHigh;
  byte *BaudLow;
  byte *ControlRegister1;
  byte *ControlRegister2;
  byte *DataRegister;
  byte *StatusRegister;
} SerialPort;


// make two instances of the serial port (they are extern because
//   they are fixed values)
extern SerialPort SCI0, SCI1;


enum {
  BAUD_9600,
  BAUD_19200,
  BAUD_38400,
  BAUD_57600,
  BAUD_115200
};

 
// SerialInitialise - initialise the serial port
// Input: baud rate as defined in the enum
void SerialInitialise(int baudRate, SerialPort *serial_port);



__interrupt void SCI1_ISR(SerialPort *serial_port_in, SerialPort *serial_port_out, char *pt, char *input_string);
 
 
#endif