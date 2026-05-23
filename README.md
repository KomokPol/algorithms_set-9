# algorithms\_set-9

## Структура

```
├── Часть A. Set\_9.pdf    # отчет
├── task\_a/               # исходники алгоритмов
│   ├── 1aq.cpp           # тернарный String QuickSort
│   ├── 1am.cpp           # String MergeSort
│   ├── 1ar.cpp           # MSD Radix Sort
│   ├── 1arq.cpp          # MSD Radix + tQS
│   ├── std\_quick\_sort.cpp
│   ├── std\_merge\_sort.cpp
│   ├── string\_generator.cpp
│   ├── string\_sort\_tester.cpp
│   └── main.cpp
├── plot.py               # построение графиков
├── results.csv           # замеры
└── plots/                # графики
```
## Как запустить

Сборка:
```bash
cd task\_a
g++ -O2 \*.cpp -o main
./main
```

Построение графиков из корня репы:
```bash
python3 plot.py
```

