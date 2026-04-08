import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

t = np.linspace(0, 15, 1000)
a = pd.read_csv("acceleration.csv", header = None)
filtered = pd.read_csv("ProjectileData.csv", sep="\s+")

fig, ax = plt.subplots(2, 2)
ax[0,0].plot(t, filtered["Position"], color="#9244FFFF", label=" Filtered Signal")
ax[0,0].set_xlabel('time(s)')
ax[0,0].set_ylabel('distance (m)')
ax[0,0].set_title('Estimated Position')
ax[0,1].plot(t, filtered["Velocity"], color="#FF5E00", label=" Filtered Signal")
ax[0,1].set_xlabel('time(s)')
ax[0,1].set_ylabel('Velocity (m/s)')
ax[0,1].set_title('Estimated Velocity')
ax[1,0].plot(t, filtered["Acceleration"], color="#FF007B", label=" Filtered Signal")
ax[1,0].set_xlabel('time(s)')
ax[1,0].set_ylabel('Acceleration (m/s^2)')
ax[1,0].set_title('Estimated Acceleration')
ax[1,1].plot(t, a, color="#00882B", label=" Filtered Signal")
ax[1,1].set_xlabel('time(s)')
ax[1,1].set_ylabel('Acceleration (m/s^2)')
ax[1,1].set_title('Measured Acceleration')
plt.tight_layout()
plt.show()
