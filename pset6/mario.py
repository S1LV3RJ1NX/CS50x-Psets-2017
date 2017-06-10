#!/usr/bin/env python3

import cs50

def main():
    
    while True:
        print("Height: ", end = "")
        height = cs50.get_int()
        if height >= 0 and height <23:
            break
        
    for row in range(height):
        
        for space in range (height - row - 1):
            print(" ", end = "")
            
        for hash in range (row + 2):
            print("#", end = "")
        
        print("")

if __name__ == "__main__":
    main()