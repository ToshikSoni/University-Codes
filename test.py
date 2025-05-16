import socket

def udp_server():
    udp_ip = '127.0.0.1'
    udp_port = 4242

    # Create UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((udp_ip, udp_port))

    print(f"Listening on {udp_ip}:{udp_port}")

    try:
        while True:
            data, addr = sock.recvfrom(1024)  # Buffer size is 1024 bytes
            print(f"Received message: {data.decode('utf-8')} from {addr}")
    except KeyboardInterrupt:
        print("\nServer shutting down...")
    finally:
        sock.close()

if __name__ == '__main__':
    udp_server()
