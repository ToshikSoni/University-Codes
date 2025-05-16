import socket
host=socket.gethostname()
port=5000
client_socket=socket.socket()
client_socket.connect((host,port))
message=input("Enter text: ")
while message.lower().strip()!='bye':
    client_socket.send(message.encode())
    data=client_socket.recv(1024).decode()
    print("Received from server: " + data)
    message = input("Enter input: ")
client_socket.close()