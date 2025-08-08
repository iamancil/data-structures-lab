import matplotlib.pyplot as plt
import numpy as np 
import pandas as pd

fig, x1 = plt.subplots()
fig, x2 = plt.subplots()

data = pd.read_csv("result.csv")
x1.plot(data['n'], data['time On'], marker = '.', label = 'On method')
x2.plot(data['n'], data['time On_2'], marker = '.', label = 'On_2 method')
x2.set_xlabel("No. of Inputs")
x2.set_ylabel("Time")

x1.set_xlabel("No. of Inputs")
x1.set_ylabel("Time")

plt.show()