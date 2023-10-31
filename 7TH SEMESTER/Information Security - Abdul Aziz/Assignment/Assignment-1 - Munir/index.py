import time
import os
from Crypto.Cipher import DES, AES

TEXT_FILE_PATH = "Aliyan.txt"
EXE_FILE_PATH = "Aliyan.exe"


def des_encrypt(key, data):
    cipher = DES.new(key, DES.MODE_ECB)
    padded_data = data + b"\0" * (8 - len(data) % 8)
    return cipher.encrypt(padded_data)


def des_decrypt(key, data):
    cipher = DES.new(key, DES.MODE_ECB)
    return cipher.decrypt(data)


def aes_encrypt(key, data):
    cipher = AES.new(key, AES.MODE_ECB)
    padded_data = data + b"\0" * (16 - len(data) % 16)
    return cipher.encrypt(padded_data)


def aes_decrypt(key, data):
    cipher = AES.new(key, AES.MODE_ECB)
    return cipher.decrypt(data)


def read_file(file_path):
    with open(file_path, "rb") as file:
        data = file.read()
    return data


def write_file(file_path, data):
    with open(file_path, "wb") as file:
        file.write(data)


def encrypt_decrypt_file(file_path, algorithm, key):
    data = read_file(file_path)
    if algorithm == "DES":
        start_time = time.time()
        encrypted_data = des_encrypt(key, data)
        end_time = time.time()
        print(
            f"DES encryption time for {file_path}: {end_time - start_time} seconds")
    elif algorithm == "AES":
        start_time = time.time()
        encrypted_data = aes_encrypt(key, data)
        end_time = time.time()
        print(
            f"AES encryption time for {file_path}: {end_time - start_time} seconds")
    else:
        raise ValueError("Invalid algorithm")
    write_file(file_path + "." + algorithm.lower() + ".enc", encrypted_data)
    encrypted_data = read_file(file_path + "." + algorithm.lower() + ".enc")
    if algorithm == "DES":
        start_time = time.time()
        decrypted_data = des_decrypt(key, encrypted_data)
        end_time = time.time()
        print(
            f"DES decryption time for {file_path}: {end_time - start_time} seconds")
    elif algorithm == "AES":
        start_time = time.time()
        decrypted_data = aes_decrypt(key, encrypted_data)
        end_time = time.time()
        print(
            f"AES decryption time for {file_path}: {end_time - start_time} seconds")
    else:
        raise ValueError("Invalid algorithm")
    write_file(file_path + "." + algorithm.lower() + ".dec", decrypted_data)


def main():
    aes_key = b"1234567890123456"
    des_key = b"abcdefgh"
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


if __name__ == "__main__":
    main()
