import serial
import time

# Serial port and file setup
PORT = 'COM3'  # Replace with your Arduino serial port (e.g., '/dev/ttyUSB0' on Linux/Mac)
BAUD_RATE = 9600
FILE_NAME = 'ecg.csv'

# Open serial connection
ser = serial.Serial(PORT, BAUD_RATE, timeout=1)
time.sleep(2)  # Allow Arduino to reset
elapsed = 10

# Open file to save data
with open(FILE_NAME, 'w') as file:
    file.write('Timestamp,Voltage\n')  # Write header
    
    try:
        print(f"Recording data... Automatically stops after {elapsed} seconds.")
        start_time = time.time()  # Initialize start time
        while True:
            elapsed_time = time.time() - start_time  # Calculate elapsed time
            if elapsed_time > elapsed:  # Stop after 10 seconds
                print("10 seconds elapsed. Stopping recording.")
                break

            line = ser.readline().decode('utf-8').strip()
            if line:
                if ',' in line:  # Data with Arduino timestamp
                    voltage = line.split(',')[-1]  # Extract voltage value
                    file.write(f"{elapsed_time:.2f},{voltage}\n")
                else:  # If no timestamp from Arduino, add Python timestamp
                    file.write(f"{elapsed_time:.2f},{line}\n")
                    
    except KeyboardInterrupt:
        print("Data recording stopped by user.")
    finally:
        ser.close()
        print(f"Data saved to {FILE_NAME}")
