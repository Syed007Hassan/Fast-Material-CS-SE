# -*- coding: utf-8 -*-
"""
Created on Sun Jan 29 17:51:00 2023

@author: Anabia
"""
import json
import socket
import threading
import os
def handle_client(client_socket):
 request = client_socket.recv(1024)
 request = request.decode()
 print(f"[*] Received: {request}")
 dict=[]
 dict.append(request)
 # Add the message to the JSON file
 try:
  with open("messages.json", "a") as f:
    json.dump({"Value": dict}, f)
    f.write('\n')
    data = {"messages": []}
 except FileNotFoundError:
   with open("messages.json", "w") as f:
    json.dump({"Value": dict}, f)
    data = {"messages": []}
 client_socket.send(b"ACK!")
 client_socket.close()
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("0.0.0.0", 12345))
server.listen(5)
print("[*] Listening on 0.0.0.0:1234")
while True:
 client, addr = server.accept()
 print(f"[*] Connection from {addr[0]}:{addr[1]}")
 client_handler = threading.Thread(target=handle_client, args=(client,))
 client_handler.start()
