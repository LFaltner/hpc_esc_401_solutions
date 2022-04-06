#!/usr/bin/env python
# coding: utf-8


import pandas as pd
import matplotlib.pyplot as plt

# read csv files and create a single pandas DataFrame
df_serial = pd.read_csv("output_serial.csv", delimiter=",")
df_serial.rename(columns={"nbody_count": "nbody_count_serial", "time": "time_serial"}, inplace=True)
df_parallel = pd.read_csv("output_parallel.csv", delimiter=",")
df_parallel.rename(columns={"nbody_count": "nbody_count_parallel", "time": "time_parallel"}, inplace=True)
df = pd.concat([df_serial, df_parallel], axis=1, join='outer')

# plot both curves and save
plt.plot(df["nbody_count_serial"], df["time_serial"], label="serial")
plt.plot(df["output_parallel"], df["time_parallel"], label="parallel")
plt.xlabel("nbody count")
plt.ylabel("Time")
plt.legend()
plt.savefig('plot.png')

