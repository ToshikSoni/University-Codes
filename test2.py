import serial
import socket
import struct
from collections import deque

def moving_average(new_value, history, window_size):
    history.append(new_value)
    if len(history) > window_size:
        history.popleft()
    return sum(history) / len(history)

def main():
    # Configure serial port (adjust 'COM6' to your port)
    serial_port = 'COM6'  # e.g., 'COM3' on Windows or '/dev/ttyUSB0' on Linux
    baud_rate = 115200

    # Configure UDP
    udp_ip = '127.0.0.1'  # localhost
    udp_port = 4242

    # Moving average window size
    window_size = 5

    # Initialize history deques for each parameter
    x_history = deque()  # For pitch (now assigned to X-axis)
    y_history = deque()  # For roll (now assigned to Y-axis)
    z_history = deque()  # For yaw (now assigned to Z-axis)
    acc_x_history = deque()
    acc_y_history = deque()
    acc_z_history = deque()

    try:
        # Initialize serial connection
        ser = serial.Serial(serial_port, baud_rate, timeout=1)
        print(f"Connected to {serial_port} at {baud_rate} baud.")
    except serial.SerialException as e:
        print(f"Error: {e}")
        return

    # Initialize UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    try:
        while True:
            # Read line from serial port
            line = ser.readline().decode('utf-8').strip()
            if line:
                # Parse the line into yaw, pitch, roll, acc_x, acc_y, acc_z
                try:
                    yaw, pitch, roll, acc_z, acc_y, acc_x = map(float, line.split(','))
                except ValueError:
                    print(f"Invalid data format: {line}")
                    continue

                # Apply moving average to each parameter
                smoothed_x = moving_average(pitch, x_history, window_size)  # X-axis is pitch
                smoothed_y = moving_average(roll, y_history, window_size)  # Y-axis is roll``````
                smoothed_z = moving_average(yaw, z_history, window_size)  # Z-axis is yaw
                smoothed_acc_x = moving_average(acc_x, acc_x_history, window_size)
                smoothed_acc_y = moving_average(acc_y, acc_y_history, window_size)
                smoothed_acc_z = moving_average(acc_z, acc_z_history, window_size)

                # Pack data in little-endian format
                packed_data = struct.pack('<6d', acc_x, 0, 0, yaw,pitch,roll)
                # packed_data = struct.pack('<6d', 0, 0, 0, smoothed_acc_y, smoothed_acc_z, smoothed_acc_x)
                #x,y,z, yaw, pitch roll
                #x=roll z=pitch

                # Send data over UDP
                sock.sendto(packed_data, (udp_ip, udp_port))
                print(f"Sent data: {smoothed_acc_x}")
    except KeyboardInterrupt:
        print("\nExiting...")
    finally:
        ser.close()
        sock.close()

if __name__ == '__main__':
    main()