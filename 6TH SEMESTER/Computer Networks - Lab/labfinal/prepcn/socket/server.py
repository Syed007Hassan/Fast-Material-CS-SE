import socket as sock
HOST = "127.0.0.1"
PORT = 5300

with sock.socket(sock.AF_INET, sock.SOCK_STREAM) as s:
  s.bind((HOST, PORT))
  s.listen()
  conn, addr = s.accept()
  with conn:
    print(f"Connected by {addr}")
    while True:
      data = conn.recv(1024)
      print(f"Msg recieved from the client: {data}")
      if not data:
         break   
      conn.sendall(bytes(input() , encoding= 'utf8'))