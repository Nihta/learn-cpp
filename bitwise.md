# Các toán thử thao tác trên bit (bitwise)

|Các phép thao tác trên bit|Kí hiệu|
|--------------------------|-------|
|[Phép AND](#1-Phép-AND)   | &     |
|[Phép OR](#2-Phép-OR)     | \|    |
|[Phép phủ định NOT](#3-Phép-phủ-định-NOT)| ~ |
|[Phép XOR](#4-Phép-XOR)   | ^     |
|[Phép dịch trái](#5-Phép-dịch-trái)  | << |
|[Phép dịch phải](#6-Phép-dịch-phải)  | >> |
-----

## 1 Phép AND

**Kí hiệu**: `&`

**Bảng chân trị**:

|A|B|A & B|
|-|-|-----|
|0|0|0|
|0|1|0|
|1|0|0|
|1|1|1|

> Phép AND chỉ có giá trị 1 nếu cả hai toán hạng đều có giá trị 1.
-----

## 2 Phép OR

**Kí hiệu**: `|`

**Bảng chân trị**:

|A|B|A \| B|
|-|-|------|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|1|

> Phép OR chỉ có giá trị 0 nếu cả hai toán hạng đều có giá trị 0.
-----

## 3 Phép phủ định NOT

**Kí hiệu**: `~`

**Bảng chân trị**:

|A|~A|
|-|--|
|0|1|
|1|0|

> Phép NOT đảo bit 1 thành 0 và ngược lại.
-----

## 4 Phép XOR

**Kí hiệu**: `^`

**Bảng chân trị**:

|A|B|A ^ B|
|-|-|-----|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|

> Phép XOR có giá trị 0 nếu cả hai toán hạng có cùng giá trị.
-----

## 5 Phép dịch trái

**Kí hiệu**: `<<`

> Phép dịch trái n bit tương đương với phép nhân cho 2 mũ n.
-----

## 6 Phép dịch phải

**Kí hiệu**: `>>`

> Phép dịch phải n bit tương đương với phép chia cho 2 mũ n.
-----
