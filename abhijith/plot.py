import pandas as pd
import matplotlib.pyplot as plt

# Load data from CSV
data = pd.read_csv('abi10.csv')

# Convert timestamp to float (if it's Unix-based)
data['Timestamp'] = pd.to_numeric(data['Timestamp'], errors='coerce')

# Plotting
plt.figure(figsize=(12, 6))
plt.plot(data['Timestamp'], data['Voltage'], label='Voltage')
plt.xlabel('Time (s)')
plt.ylabel('Voltage (V)')
plt.title('Voltage vs Time')
plt.legend()
plt.show()
