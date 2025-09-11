import argparse
import socket
import threading
import time

HOST = 'localhost'
PORT = 50007 # Arbitrary non-privileged port

def handle_client(conn, addr):
  with conn:
    print('Connected by', addr)
    while True:
      time.sleep(5)
      data = conn.recv(1024)
      if not data: break
      conn.sendall(data)

def client():
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hello, world')
    data = s.recv(1024)
  print('Received', repr(data))

def server():
  with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen(2)
    print(f"Servidor ouvindo em {HOST}:{PORT}")

    while True:
      conn, addr = s.accept()
      thread = threading.Thread(target=handle_client, args=(conn, addr))
      thread.start()

parser = argparse.ArgumentParser()
parser.add_argument('-s', '--server', action='store_true')
args = parser.parse_args()
if args.server: server()
else: client()