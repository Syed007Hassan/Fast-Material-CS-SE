import time
import os
from Crypto.Cipher import DES, AES

# Define the file paths
TEXT_FILE_PATH = "hassan.txt"
EXE_FILE_PATH = "hassan.exe"

# Define the encryption and decryption functions for DES algorithm


def des_encrypt(key, data):
    cipher = DES.new(key, DES.MODE_ECB)
    padded_data = data + b"\0" * (8 - len(data) % 8)
    return cipher.encrypt(padded_data)


def des_decrypt(key, data):
    cipher = DES.new(key, DES.MODE_ECB)
    return cipher.decrypt(data)

# Define the encryption and decryption functions for AES algorithm


def aes_encrypt(key, data):
    cipher = AES.new(key, AES.MODE_ECB)
    padded_data = data + b"\0" * (16 - len(data) % 16)
    return cipher.encrypt(padded_data)


def aes_decrypt(key, data):
    cipher = AES.new(key, AES.MODE_ECB)
    return cipher.decrypt(data)

# Define the function to read the file and return its contents


def read_file(file_path):
    with open(file_path, "rb") as file:
        data = file.read()
    return data

# Define the function to write the file with the given data


def write_file(file_path, data):
    with open(file_path, "wb") as file:
        file.write(data)

# Define the function to encrypt and decrypt the file using the given algorithm and key


def encrypt_decrypt_file(file_path, algorithm, key):
    # Read the file contents
    data = read_file(file_path)
    # Encrypt the data using the given algorithm and key
    start_time = time.time()
    if algorithm == "DES":
        encrypted_data = des_encrypt(key, data)
    elif algorithm == "AES":
        encrypted_data = aes_encrypt(key, data)
    else:
        raise ValueError("Invalid algorithm")
    encryption_time = time.time() - start_time
    # Write the encrypted data to the file
    write_file(file_path + "." + algorithm.lower() + ".enc", encrypted_data)
    print(f"{file_path} encrypted using {algorithm} algorithm")
    # Read the encrypted data from the file
    encrypted_data = read_file(file_path + "." + algorithm.lower() + ".enc")
    # Decrypt the data using the given algorithm and key
    start_time = time.time()
    if algorithm == "DES":
        decrypted_data = des_decrypt(key, encrypted_data)
    elif algorithm == "AES":
        decrypted_data = aes_decrypt(key, encrypted_data)
    else:
        raise ValueError("Invalid algorithm")
    decryption_time = time.time() - start_time
    # Write the decrypted data to the file
    write_file(file_path + "." + algorithm.lower() + ".dec", decrypted_data)
    print(f"{file_path} decrypted using {algorithm} algorithm")
    # Print the encryption and decryption times
    print(f"{algorithm} encryption time: {encryption_time:.6f} seconds")
    print(f"{algorithm} decryption time: {decryption_time:.6f} seconds")

# Define the main function to encrypt and decrypt the files


def main():
    # Define the keys for AES and DES algorithms
    aes_key = b"1234567890123456"
    des_key = b"abcdefgh"
    # Encrypt and decrypt the text file using AES and DES algorithms
    for i in range(2):
        if os.path.getsize(TEXT_FILE_PATH) < 10000000:
            if i == 0:
                algorithm = "AES"
                key = aes_key
            else:
                algorithm = "DES"
                key = des_key
            encrypt_decrypt_file(TEXT_FILE_PATH, algorithm, key)
        else:
            print("File size is greater than 10MB")
    # Encrypt and decrypt the exe file using AES and DES algorithms
    for i in range(2):
        if os.path.getsize(EXE_FILE_PATH) < 10000000:
            if i == 0:
                algorithm = "AES"
                key = aes_key
            else:
                algorithm = "DES"
                key = des_key
            encrypt_decrypt_file(EXE_FILE_PATH, algorithm, key)
        else:
            print("File size is greater than 10MB")


# Call the main function
if __name__ == "__main__":
    main()
