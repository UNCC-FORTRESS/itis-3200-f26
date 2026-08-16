import socket

HOST = '127.0.0.1'  # The server's hostname or IP address
PORT = 65432         # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    # 1. TODO: Connect to the server using the HOST and PORT variables
    # 2. TODO: Create a string variable named 'message' containing your Student ID and the word "robux"
    # 3. TODO: Encode the message string to bytes and send it to the server
    # 4. TODO: Receive the server's response (buffer size 1024) and assign it to a variable called 'reply'
    # 5. TODO: Decode and print the 'reply' variable to your terminal
    pass
