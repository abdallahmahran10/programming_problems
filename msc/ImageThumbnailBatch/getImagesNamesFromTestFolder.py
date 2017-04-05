import os
# get images names in test folder to use them in cmd param

dir_path = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'in')

cmdParams =""
for root, dirs, filenames in os.walk(dir_path):
    for f in filenames:
        cmdParams += os.path.join(root, f) + " "
		
with open("t.txt", 'w') as f:
	f.write(cmdParams)

		
