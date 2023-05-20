import socket

HOST = "127.0.0.1" 
PORT = 5300 

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    while True:  
        s.sendall(bytes(input() , encoding= 'utf8'))
        data = s.recv(1024)
        if not data:
            break
        print(f"Received data from server : {data}")