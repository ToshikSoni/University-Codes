import socket
import time

def generate_traffic(target_ip):
    for port in range(1, 65535):
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            s.connect((target_ip, port))
            s.close()
        except Exception as e:
            pass
        time.sleep(0.01)

if __name__ == '__main__':
    target_ip = '172.16.28.31'
    generate_traffic(target_ip)