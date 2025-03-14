import pandas as pd
import matplotlib.pyplot as plt

# 🚀 Laster inn CSV-fil
file_path = "pid_log.csv"
df = pd.read_csv(file_path, names=["timestamp", "surge", "sway", "heave", "yaw", "depth", "yaw_angle", "desired_depth"], skiprows=1)

# 💡 Fyll inn manglende verdier med NaN og håndter manglende data
df = df.fillna(method='ffill')  # Forward fill for å unngå NaN-verdier

# 📌 Normaliser tid slik at første datapunkt starter fra 0
df["timestamp"] = df["timestamp"] - df["timestamp"].iloc[0]

# 🎨 Plot stil
plt.style.use('ggplot')

# 🎯 1. Dybde: Ønsket vs. Faktisk
plt.figure(figsize=(10, 5))
plt.plot(df["timestamp"], df["desired_depth"], label="Ønsket dybde", linestyle="--", color="blue")
plt.plot(df["timestamp"], df["depth"], label="Faktisk dybde", color="red")
plt.xlabel("Tid (s)")
plt.ylabel("Dybde (m)")
plt.title("Dybde: Ønsket vs. Faktisk")
plt.legend()
plt.grid()
plt.savefig("depth_plot_last.png")
plt.show()

# 🎯 2. Yaw-vinkel: Ønsket vs. Faktisk
plt.figure(figsize=(10, 5))
plt.plot(df["timestamp"], df["yaw"], label="Ønsket yaw", linestyle="--", color="blue")
plt.plot(df["timestamp"], df["yaw_angle"], label="Faktisk yaw", color="red")
plt.xlabel("Tid (s)")
plt.ylabel("Yaw-vinkel (grader)")
plt.title("Yaw: Ønsket vs. Faktisk")
plt.legend()
plt.grid()
plt.savefig("yaw_plot_last.png")
plt.show()

# 🎯 3. Surge: Ønsket verdi
plt.figure(figsize=(10, 5))
plt.plot(df["timestamp"], df["surge"], label="Ønsket surge", linestyle="--", color="blue")
plt.xlabel("Tid (s)")
plt.ylabel("Surge")
plt.title("Surge: Ønsket verdi")
plt.legend()
plt.grid()
plt.savefig("surge_plot_last.png")
plt.show()

# 🎯 4. Heave: Ønsket verdi
plt.figure(figsize=(10, 5))
plt.plot(df["timestamp"], df["heave"], label="Ønsket heave", linestyle="--", color="blue")
plt.xlabel("Tid (s)")
plt.ylabel("Heave")
plt.title("Heave: Ønsket verdi")
plt.legend()
plt.grid()
plt.savefig("heave_plot_last.png")
plt.show()

print("✅ Plot lagret som depth_plot.png, yaw_plot.png, surge_plot.png, heave_plot.png")