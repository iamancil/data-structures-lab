import matplotlib.pyplot as plt
import numpy as np 
import pandas as pd

data = pd.read_csv("result.csv")
plt.plot(data['n'], data['time On'], marker = 'o', label = 'On method')
plt.plot(data['n'], data['time On_2'], marker = 'x', label = 'On_2 method')


plt.xlabel("No. of Inputs")
plt.ylabel("Time")
plt.show()