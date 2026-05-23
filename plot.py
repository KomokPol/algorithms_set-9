import pandas as pd
import matplotlib.pyplot as plt
import os

df = pd.read_csv("results.csv")

os.makedirs("plots", exist_ok=True)

algorithms = ["StdQuickSort", "StdMergeSort", "TernaryQuickSort", "StringMergeSort", "MSBRadixSort", "MSBRadixHybrid"]
types = ["random", "reverse", "almost"]
metrics = [("time_us", "Время, мкс"), ("comparisons", "Число сравнений")]

for metric, ylabel in metrics:
  for type_name in types:
    plt.figure(figsize=(10, 6))

    for algo in algorithms:
      sub = df[(df["algorithm"] == algo) & (df["type"] == type_name)]
      plt.plot(sub["size"], sub[metric], marker="o", label=algo)

    plt.xlabel("Размер массива")
    plt.ylabel(ylabel)
    plt.title(f"{ylabel}, тип: {type_name}")
    plt.legend()
    plt.grid(True)

    filename = f"plots/{metric}_{type_name}.png"
    plt.savefig(filename, dpi=120, bbox_inches="tight")
    plt.close()
    print(f"сохранено {filename}")
