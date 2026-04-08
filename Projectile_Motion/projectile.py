import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

t = np.linspace(0, 15, 1000)
# a = np.full(shape=1000, fill_value=9.81)
# mu = 0
# sigma = 0.1
# noise_shape = a.shape
# noise = np.random.normal(mu, sigma, size=noise_shape)
# noisy_signal = noise + a
# np.savetxt('acceleration.csv', noisy_signal, delimiter=',') 
a = pd.read_csv("acceleration.csv", header = None)
filtered = pd.read_csv("ProjectileData.csv", sep="\s+")
print(filtered["Acce"])



plt.figure(figsize=(10, 5))
plt.plot(t, filtered["X"], color="#560088", label=" Filtered Signal")
plt.xlabel("time(s)")
plt.ylabel("Position")
# plt.plot(t, a, c="k",label="True value")
# plt.plot(t, filtered.iloc[:,0], label = "Filtered Signal",c="#45E235",linestyle="dotted")
plt.legend()
plt.show()
