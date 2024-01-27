# Clears out all log files in this folder.

import os

for file in os.listdir():
    if not file.endswith(".txt") and not file.endswith(".py"):
        try:
            os.remove(file)
        except:
            print("Some files weren't deleted")
        
print("Done.")