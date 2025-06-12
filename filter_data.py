import pandas as pd
import csv


a = pd.read_csv("accelerometer.txt", sep="\s+")
a2 = pd.read_csv("accelerometer_2.txt", sep="\s+")
a3 = pd.read_csv("accelerometer_3.txt", sep="\s+")
g = pd.read_csv("gyroscope.txt", sep="\s+")
g2 = pd.read_csv("gyroscope_2.txt", sep="\s+")
m = pd.read_csv("magnetometer.txt", sep="\s+")

ax1 = []
ay1 = []
az1 = []
ax2 = []
ay2 = []
az2 = []
ax3 = []
ay3 = []
az3 = []
gx1 = []
gy1 = []
gz1 = []
gx2 = []
gy2 = []
gz2 = []
mx = []
my = []
mz = []


for i in range(len(m["MX"])):
    ax1.append(a["AX"].iloc[i])
    ay1.append(a["AY"].iloc[i])
    az1.append(a["AZ"].iloc[i])
    ax2.append(a2["AX"].iloc[i])
    ay2.append(a2["AY"].iloc[i])
    az2.append(a2["AZ"].iloc[i])
    ax3.append(a3["AX"].iloc[i])
    ay3.append(a3["AY"].iloc[i])
    az3.append(a3["AZ"].iloc[i])
    gx1.append(g["GX"].iloc[i])
    gy1.append(g["GY"].iloc[i])
    gz1.append(g["GZ"].iloc[i])
    gx2.append(g2["GX"].iloc[i])
    gy2.append(g2["GY"].iloc[i])
    gz2.append(g2["GZ"].iloc[i])
    mx.append(m["MX"].iloc[i])
    my.append(m["MY"].iloc[i])
    mz.append(m["MZ"].iloc[i])


data_names = ["ax1", "ay1", "az1", 
              "ax2", "ay2", "az2", "ax3", "ay3", 
              "az3", "gx1", "gy1", "gz1", "gx2", 
              "gy2", "gz2", "mx", "my", "mz"]
data = [[ax1],[ay1],[az1],[ax2],[ay2],[az2],[ax3],[ay3],[az3],[gx1],[gy1],[gz1],[gx2],[gy2],[gz2],[mx],[my],[mz]]


for i in range(len(data)):
    with open(data_names[i] + ".csv", 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',')
        writer.writerows(data[i])
        