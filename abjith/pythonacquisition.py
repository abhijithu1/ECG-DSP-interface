import serial
import time
#make sure to install pyserial
# pip install pyserial matplotlib
# Serial port and file setup
PORT = 'COM3'  # Replace with your Arduino serial port (e.g., '/dev/ttyUSB0' on Linux/Mac)
BAUD_RATE = 9600
FILE_NAME = 'voltage_data.csv'

# Open serial connection
ser = serial.Serial(PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # Allow Arduino to reset

# Open file to save data
with open(FILE_NAME, 'w') as file:
    file.write('Timestamp,Voltage\n')  # Write header
    
    try:
        print("Recording data... Press Ctrl+C to stop.")
        while True:
            line = ser.readline().decode('utf-8').strip()
            if line:
                if ',' in line:  # Data with Arduino timestamp
                    file.write(line + '\n')
                else:  # If no timestamp from Arduino, add Python timestamp
                    timestamp = time.time()
                    file.write(f"{timestamp},{line}\n")
                    
    except KeyboardInterrupt:
        print("Data recording stopped by user.")
    finally:
        ser.close()
        print(f"Data saved to {FILE_NAME}")
