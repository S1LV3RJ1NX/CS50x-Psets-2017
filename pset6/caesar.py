#!/usr/bin/env python3

import cs50
import sys

def main():
    if len(sys.argv) != 2:
        print("You should provide 2 cmd line arguments!")
        exit(1)
        
    key = int(sys.argv[1])
    
    print("plaintext: ", end ="")
    message = cs50.get_string()
    
    print("ciphertext: ", end="")
    
    for i in range(len(message)):
        if message[i].isalpha() == True:
            if message[i].islower() == True:
                print(chr(((ord(message[i]) - 97 + key) % 26) + 97), end = "")
            else:
                print(chr(((ord(message[i]) - 65 + key) % 26) + 65), end = "")
        
        else:
            print(message[i], end ="")
    
    print("")
    
if __name__ == "__main__":
    main()