import socket
HOST = "127.0.0.1"
PORT = 65432
with socket.socket() as s:
    s.connect((HOST, PORT))
    s.sendall(b"Hello world")
    data=s.recv(1024)
print(f"Recieved {data!r}")