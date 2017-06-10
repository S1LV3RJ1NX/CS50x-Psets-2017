#!/usr/bin/env python3

import cs50

def main():
    print("O hai! how much change is owned? ")
    while True:
            change = cs50.get_float()
            if change > 0:
                break
    
    cents = int(round(change* 100))
    
    counter = 0
    
    counter += cents // 25
    cents %= 25
  
    counter += cents // 10
    cents %= 10
    
    counter += cents // 5
    cents %= 5
    
    counter += cents
    
    print(counter)
    
        
    

if __name__ == "__main__":
    main()