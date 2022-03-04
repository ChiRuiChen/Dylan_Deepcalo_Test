import numpy as np
import sys

original_stdout = sys.stdout
with open('w40.txt', 'w') as f:
    sys.stdout = f
    for i in range(589824-1):
        print('1.0',end = ', ')
    print('1.0')    
    
with open('b40.txt', 'w') as f:
    sys.stdout = f
    for i in range(256-1):
        print('0.0',end = ', ')
    print('0.0')    
    
    sys.stdout = original_stdout